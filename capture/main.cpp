#if defined(_WIN64) || defined(_WIN32)

#include <winsock2.h>
#include <Windows.h>
#include <Ws2tcpip.h>
#include <fileapi.h>
#include <string.h>

#include <algorithm>

#endif

#if defined(__unix__) || defined(__APPLE__)

#include <netinet/in.h>  ///< sockaddr_in
#include <sys/socket.h>  ///< socket
#include <unistd.h>

#endif

#include <json/json.h>
#include <time.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iomanip>

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/includer.h"

#define bzero(b, len) (memset((b), '\0', (len)), (void)0)  // bzero

#define BUFFER_SIZE 4096
#define DEBUG 0
#define DS 0
#define JSON 1

bool CTRLC = false;
static const unsigned short DEFAULT_PORT = 20777;

class InputParser {
   public:
    InputParser(int &argc, char **argv) {
        for (int i = 1; i < argc; ++i)
            this->tokens.push_back(std::string(argv[i]));
    }
    /// @author iain
    const std::string &getCmdOption(const std::string &option) const {
        std::vector<std::string>::const_iterator itr;
        itr = std::find(this->tokens.begin(), this->tokens.end(), option);
        if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
            return *itr;
        }
        static const std::string empty_string("");
        return empty_string;
    }
    /// @author iain
    bool cmdOptionExists(const std::string &option) const {
        return std::find(this->tokens.begin(), this->tokens.end(), option) !=
               this->tokens.end();
    }

   private:
    std::vector<std::string> tokens;
};

void clear_line() {
#if defined(_WIN64) || defined(_WIN32)
    if (!DEBUG) {
        std::cout << std::flush
                  << "\r                                                       "
                     "                                    \r";
    }
#endif
#if defined(__linux__) || defined(__APPLE__)
    if (!DEBUG) {
        std::cout << std::flush << "\33[2K\r";
    }
#endif
}

void mkoutdir(std::string dirname) {
#if defined(_WIN64) || defined(_WIN32)
    if (CreateDirectoryA(dirname.c_str(), NULL) ||
        GetLastError() == ERROR_ALREADY_EXISTS) {
        std::cout << "Directory " << dirname << " already exists";
    } else {
        std::cout << "Directory " << dirname << " created";
    }
    clear_line();
#endif
#if defined(__unix__) || defined(__APPLE__)
    if (mkdir((const char *)dirname.c_str(),
              S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
        if (errno == EEXIST) {
            std::cout << "Folder '" << dirname << "' already exists";
        } else {
            // something else
            std::cerr << "Cannot create folder error:" << strerror(errno);
            throw std::runtime_error(strerror(errno));
        }
    } else {
        std::cout << "Folder '" << dirname << "' created";
    }
    clear_line();
#endif
}

void initJsonFile(std::string path, int startFrame) {
    std::ofstream file;
    file.open(path, std::ios::app);
    file << "[" << std::endl;
    for (int i = 0; i < startFrame; i++) {
        file << "\t{}";
        if (i != startFrame - 1) {
            file << "," << std::endl;
        }
    }
    file.close();
}

void initAllJsonFiles(int startFrame) {
    std::string path = "Outputs";
    mkoutdir(path);
    std::string basePath = OUTPUT_PATH;
    mkoutdir(basePath);

    for (std::vector<std::string>::iterator t = ALL_PATHS.begin();
         t != ALL_PATHS.end(); ++t) {
        initJsonFile(*t, startFrame);
    }
}

void updateJson(int actualFrame, int flashbackFrame, std::string path) {
    std::string tempPath = path + ".bak";
    Json::Reader reader;
    Json::Value root;

    // First add the end of the file for correct json format read
    std::ofstream fix_file(path, std::ios::app);
    fix_file << "]" << std::endl;
    fix_file.close();

    // Read the json file and parse
    std::ifstream in_file(path);
    reader.parse(in_file, root);
    in_file.close();

    // Clear the frames
    for (int i = actualFrame; i >= flashbackFrame; i--) {
        root[i].clear();
    }

    // Write the json file

    std::ofstream out_file(tempPath);
    out_file << root;
    out_file.close();

    // Remove the old file and correct the new one

    std::vector<int> lines_length;
    std::ifstream in_file2(tempPath);
    std::string temp_line;
    while (std::getline(in_file2, temp_line)) {
        lines_length.push_back(temp_line.length());
    }
    in_file2.close();

    std::fstream file_in(tempPath, std::ios::in);
    std::fstream file_out(path, std::ios::out);
    std::string line;

    int diff = actualFrame - flashbackFrame + 2;
    int row_counter = 0;

    while (std::getline(file_in, line)) {
        if (row_counter >= (int)lines_length.size() - diff - 1) {
            line.replace(line.find(","), 1, "");
            file_out << line;
            break;
        }
        row_counter += 1;
        file_out << line << std::endl;
    }

    file_in.close();
    file_out.close();
    lines_length.clear();
    temp_line.clear();
    line.clear();

    // Remove the temp file
    remove(tempPath.c_str());
}

std::ostream& operator<<(std::ostream& os, const seconds_t& v) {
    // convert to milliseconds
    int ms = static_cast<int>(v.value * 1000.);

    int h = ms / (1000 * 60 * 60);
    ms -= h * (1000 * 60 * 60);

    int m = ms / (1000 * 60);
    ms -= m * (1000 * 60);

    int s = ms / 1000;
    ms -= s * 1000;

    return os << std::setfill('0') << std::setw(2) << h << ':' << std::setw(2) << m
              << ':' << std::setw(2) << s << '.' << std::setw(3) << ms;
}

void updateAllJsonFiles(int actualFrame, int flashbackFrame) {
    int it = 0;
    const clock_t begin_time = clock();
    for (std::vector<std::string>::iterator t = ALL_PATHS.begin();
         t != ALL_PATHS.end(); ++t) {
        clear_line();
        std::cout << "Flashback occurred! Updating json files [" << it << "/" << ALL_PATHS.size() << "] ";
        for (int printer = 0; printer < (int)ALL_PATHS.size(); printer++) {
            if (printer < it) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        updateJson(actualFrame, flashbackFrame, *t);
        it += 1;
    }
    clear_line();
    seconds_t m{float(clock () - begin_time ) /  CLOCKS_PER_SEC};
    std::cout << "Flashback occurred! Updated all json files in " << m << std::endl;
}

void writeEmptyData(std::vector<std::string> inserted) {
    std::vector<std::string> empty;
    // Check if inserted elements are a substring of ALL_PATHS elements
    for (std::vector<std::string>::iterator t = ALL_PATHS.begin();
         t != ALL_PATHS.end(); ++t) {
        bool found = false;
        for (std::vector<std::string>::iterator i = inserted.begin();
             i != inserted.end(); ++i) {
            if (t->find(*i) != std::string::npos) {
                found = true;
                break;
            }
        }
        if (!found) {
            empty.push_back(*t);
        }
    }

    std::ofstream file;
    for (std::vector<std::string>::iterator t = empty.begin(); t != empty.end();
         ++t) {
        file.open(*t, std::ios::app);
        file << ",\n\t{}";
        file.close();
    }
}

void closeJson(std::string path) {
    std::ofstream file;
    file.open(path, std::ios::app);
    file << "]" << std::endl;
    file.close();
}

void closeAllJsonFiles() {
    for (std::vector<std::string>::iterator t = ALL_PATHS.begin();
         t != ALL_PATHS.end(); ++t) {
        closeJson(*t);
    }
}

void endSession(const char *dirname, uint8 session, char *trackName) {
    closeAllJsonFiles();

    if (session > 0) {
        clear_line();
#if defined(_WIN32) || defined(_WIN64)
        wprintf(L"Session %s Ended. ", Session_Type[session]);

        std::string renString = "Outputs\\";
        renString += Session_Type[session];
        renString += "_";
        renString += trackName;
#endif
#if defined(__linux__) || defined(__APPLE__)
        std::cout << "Session " << Session_Type[session] << " Ended"
                  << std::endl;
        std::string renString = "Outputs/";
        renString += (char *)sessionName;
        renString += "_";
        renString += (char *)trackName;
#endif

        if (rename(dirname, renString.c_str())) {
#if defined(_WIN32) || defined(_WIN64)
            wprintf(L"Error renaming directory\n");
            WSACleanup();
#endif
#if defined(__linux__) || defined(__APPLE__)
            std::cerr << "Error renaming directory" << std::endl;
#endif
            exit(2);
        }
    } else {
        clear_line();
#if defined(_WIN32) || defined(_WIN64)
        wprintf(L"Session not yet initialized\n");
#endif
#if defined(__linux__) || defined(__APPLE__)
        std::cout << "Session not yet initialized" << std::endl;
#endif
    }
    if (CTRLC){
#if defined(_WIN32) || defined(_WIN64)
        wprintf(L"CTRL+C detected, exiting.\n");
        WSACleanup();
#endif
#if defined(__linux__) || defined(__APPLE__)
        std::cout << "CTRL+C detected, exiting." << std::endl;
#endif
        exit(0);
    }
}

void signal_callback_handler(int signum) {
    // std::cout << std::endl << "Ctrl-C occurred, initiated closing procedure..." << std::endl;
    CTRLC = true;
}

int main(int argc, char **argv) {
    // Signal handler
    signal(SIGINT, signal_callback_handler);

    // Parser - Works!
    InputParser input(argc, argv);
    if (input.cmdOptionExists("-h")) {
        std::cout << "-h detected" << std::endl;
    }
    if (input.cmdOptionExists("-f")) {
        const std::string &filename = input.getCmdOption("-f");
        if (!filename.empty()) {
            std::cout << "-f detected" << std::endl;
            // Do interesting things ...
        } else {
            std::cout << "-f detected with no files" << std::endl;
        }
    }

#if defined(_WIN64) || defined(_WIN32)
    WSACleanup();
#endif
    unsigned short port = DEFAULT_PORT;

// Socket creation
#if defined(_WIN64) || defined(_WIN32)

    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        exit(1);
    }

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == INVALID_SOCKET)
        wprintf(L"socket function failed with error = %d\n", WSAGetLastError());
    else {
        wprintf(L"UDP Socket created\n");
        if (iResult == SOCKET_ERROR) {
            wprintf(L"closesocket failed with error = %d\n", WSAGetLastError());
            WSACleanup();
            exit(2);
        }
    }
#endif
#if defined(__unix__) || defined(__APPLE__)
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        if (DEBUG) std::cerr << "Could not create socket" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (DEBUG) std::cout << "UDP Socket created" << std::endl;
#endif

    // Just for rebooting the server faster
    int optval = 1;
#if defined(_WIN64) || defined(_WIN32)
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval,
               sizeof(int));
#endif
#if defined(__unix__) || defined(__APPLE__)
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval,
               sizeof(int));
#endif

    // Server address
    struct sockaddr_in addr;
    bzero((char *)&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = ntohs(port);

// Binding
#if defined(_WIN64) || defined(_WIN32)
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        if (DEBUG) wprintf(L"Could not bind the socket");
        exit(3);
    }
    if (DEBUG) wprintf(L"Socket bound on port %d\n", port);
#endif
#if defined(__unix__) || defined(__APPLE__)
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        if (DEBUG) std::cerr << "Could not bind the socket" << std::endl;
    }
    if (DEBUG) std::cout << "Socket bound on port " << port << std::endl;
#endif

    // main loop
    char buffer[BUFFER_SIZE];
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    int n = 0;
    bool start = true;
    std::vector<int> frame_list;
    std::vector<int> sessionTime_list;
    std::vector<std::string> addValue_list;
    std::ofstream file;
    Json::Value root;

    PacketHeader h_packet;
    PacketMotionData p_Motion;
    PacketSessionData p_Session;
    PacketLapData p_Lap;
    PacketEventData p_Event;
    PacketParticipantsData p_Participants;
    PacketCarSetupData p_CarSetup;
    PacketCarTelemetryData p_CarTelemetry;
    PacketCarStatusData p_CarStatus;
    PacketFinalClassificationData p_FinalClassification;
    PacketLobbyInfoData p_LobbyInfo;
    PacketCarDamageData p_CarDamage;
    PacketSessionHistoryData p_SessionHistory;

    // Create or check if exists the output folder
    std::string dirname = OUTPUT_PATH;
    std::cout << "Waiting for data...";
#if defined(__unix__) || defined(__APPLE__)
    clear_line();
#endif
    while (1) {
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                     (struct sockaddr *)&clientAddr, &clientLen);

        if (n < 0) {
#if defined(_WIN64) || defined(_WIN32)
            wprintf(L"Error receiving data\n");
            WSACleanup();
#endif
#if defined(__unix__) || defined(__APPLE__)
            std::cerr << "Error receiving data" << std::endl;
#endif
            exit(EXIT_FAILURE);
        }
        h_packet.get(buffer);

        // if (DS) h_packet.to_csv(dirname);
        if (JSON) {
            uint32 frame = h_packet.m_frameIdentifier;
            if (start) {
                initAllJsonFiles(frame);
                addValue_list = ALL_PATHS;
                start = false;
            }
            if (frame_list.size() == 0 ||
                std::count(frame_list.begin(), frame_list.end(), frame) == 0) {
                // Save to the complete json file
                if (frame_list.size() > 0) {
                    writeJsonDataToFile(DATA_PATH, root, frame);
                }

                // Save the single json files
                writeEmptyData(addValue_list);

                frame_list.push_back(frame);
                sessionTime_list.push_back(h_packet.m_sessionTime);
                root = h_packet.toJSON(root);
                addValue_list.clear();
                addValue_list.push_back("Data");
                addValue_list.push_back("Header");
            }
        }

        switch (h_packet.m_packetId) {
            case PACKET_ID_MOTION:  // 0 - Motion
                p_Motion.get(buffer);
                // if (DS) p_Motion.to_csv(dirname);
                if (JSON) {
                    root = p_Motion.toJSON(root);
                    addValue_list.push_back("Motion");
                }
                break;
            case PACKET_ID_SESSION:  // 1 - Session
                p_Session.get(buffer);
                // if (DS) p_Session.to_csv(dirname);
                if (JSON) {
                    root = p_Session.toJSON(root);
                    addValue_list.push_back("Session");
                }
                break;
            case PACKET_ID_LAP_DATA:  // 2 - Lap Data
                p_Lap.get(buffer);
                // if (DS) p_Lap.to_csv(dirname);
                if (JSON) {
                    root = p_Lap.toJSON(root);
                    addValue_list.push_back("Lap");
                }
                break;
            case PACKET_ID_EVENT:  // 3 - Event
                p_Event.get(buffer);
                // if (DS) p_Event.to_csv(dirname);
                if (JSON) {
                    root = p_Event.toJSON(root);
                    if (root["EventData"]["eventStringCode"] == "FLBK") {
                        updateAllJsonFiles(frame_list.back(),
                                           root["EventData"]["eventDetails"]
                                               ["flashbackFrameIdentifier"]
                                                   .asInt());
                        // updateJson(frame_list.back(),root["eventDetails"]["flashbackFrameIdentifier"].asInt(),SAVE_PATH_JSON);
                    }
                    addValue_list.push_back("Event");
                }
                break;
            case PACKET_ID_PARTICIPANTS:  // 4 - Participants
                p_Participants.get(buffer);
                // if (DS) p_Participants.to_csv(dirname);
                if (JSON) {
                    root = p_Participants.toJSON(root);
                    addValue_list.push_back("Participants");
                }
                break;
            case PACKET_ID_CAR_SETUPS:  // 5 - Car Setups
                p_CarSetup.get(buffer);
                // if (DS) p_CarSetup.to_csv(dirname);
                if (JSON) {
                    root = p_CarSetup.toJSON(root);
                    addValue_list.push_back("Setup");
                }
                break;
            case PACKET_ID_CAR_TELEMETRY:  // 6 - Car Telemetry
                p_CarTelemetry.get(buffer);
                // if (DS) p_CarTelemetry.to_csv(dirname);
                if (JSON) {
                    root = p_CarTelemetry.toJSON(root);
                    addValue_list.push_back("Telemetry");
                }
                break;
            case PACKET_ID_CAR_STATUS:  // 7 - Car Status
                p_CarStatus.get(buffer);
                // if (DS) p_CarStatus.to_csv(dirname);
                if (JSON) {
                    root = p_CarStatus.toJSON(root);
                    addValue_list.push_back("Status");
                }
                break;
            case PACKET_ID_FINAL_CLASSIFICATION:  // 8 - Final Classification
                p_FinalClassification.get(buffer);
                // if (DS) p_FinalClassification.to_csv(dirname);
                if (JSON) {
                    root = p_FinalClassification.toJSON(root);
                    addValue_list.push_back("Classification");
                }
                break;
            case PACKET_ID_LOBBY_INFO:  // 9 - Lobby Info
                p_LobbyInfo.get(buffer);
                // if (DS) p_LobbyInfo.to_csv(dirname);
                if (JSON) {
                    root = p_LobbyInfo.toJSON(root);
                    addValue_list.push_back("Lobby");
                }
                break;
            case PACKET_ID_CAR_DAMAGE:  // 10 - Car Damage
                p_CarDamage.get(buffer);
                // if (DS) p_CarDamage.to_csv(dirname);
                if (JSON) {
                    root = p_CarDamage.toJSON(root);
                    addValue_list.push_back("Damage");
                }
                break;
            case PACKET_ID_SESSION_HISTORY:  // 11 - Session History
                p_SessionHistory.get(buffer);
                // if (DS) p_SessionHistory.to_csv(dirname);
                if (JSON) {
                    root = p_SessionHistory.toJSON(root);
                    addValue_list.push_back("History");
                }
                break;
            default:
                std::cout << "Default occurred: ";
                h_packet.print();
                std::cout << std::endl;
#if defined(_WIN64) || defined(_WIN32)
                WSACleanup();
#endif
                exit(-1);
                break;
        }

        uint8 session = p_Session.m_sessionType;
        uint8 track = p_Session.m_trackId;
        const char *sessionName = Session_Type[session];
        const char *trackName = Track[track];

        clear_line();
        if (!DEBUG) {
            std::cout << sessionName << " ";
            std::cout << trackName << " || ";
            if (session < 10) {
                int seconds = p_Session.m_sessionTimeLeft;
                int minutes = seconds / 60;
                int hours = minutes / 60;
                seconds = seconds - ((hours * 3600) + (minutes * 60));
                if (seconds < 0) {
                    clear_line();
                    std::cout << "Session not yet initialized";
                } else {
                    std::cout << "Time remaining: " << hours << ":" << minutes
                              << ":" << seconds;
                }
            } else {
                int lap_time_sec =
                    (int)p_Lap.m_lapData[h_packet.m_playerCarIndex]
                        .m_currentLapTimeInMS /
                    1000;
                int lap_time_min = (int)lap_time_sec / 60;
                lap_time_sec = lap_time_sec - (lap_time_min * 60);
                int lap_time_ms =
                    (int)p_Lap.m_lapData[h_packet.m_playerCarIndex]
                        .m_currentLapTimeInMS -
                    (lap_time_sec * 1000);
                std::cout << "Lap: "
                          << (int)p_Lap.m_lapData[h_packet.m_playerCarIndex]
                                 .m_currentLapNum
                          << "/" << (int)p_Session.m_totalLaps
                          << " Lap time: " << lap_time_min << ":"
                          << lap_time_sec << "." << lap_time_ms;
            }
            std::cout
                << " || Position: "
                << (int)p_Lap.m_lapData[h_packet.m_playerCarIndex].m_carPosition
                << "/" << (int)h_packet.m_playerCarIndex + 1;
        }

        std::string eventString = (const char *)p_Event.m_eventStringCode;
        eventString = eventString.substr(0, 4);
        const char *eventConstChar = (const char *)eventString.c_str();
#if defined(_WIN64) || defined(_WIN32)
        if (strcmp(eventConstChar, "SEND") == 0 || CTRLC) {
#endif
#if defined(__linux__) || defined(__APPLE__)
        if (std::strcmp(eventConstChar, "SEND") == 0 || CTRLC) {
#endif
            endSession((const char *)dirname.c_str(), session, (char *)trackName);
            memset(buffer, 0, sizeof(buffer));
            memset(&eventConstChar, 0, sizeof(eventConstChar));
        }
    }

    return 0;
}
