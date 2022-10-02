#ifndef __Event_h__
#define __Event_h__

#include "Costants.h"
#include "Header.h"

// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
union EventDataDetails {
    struct {
        uint8 vehicleIdx;  // Vehicle index of car achieving fastest lap
        float lapTime;     // Lap time is in seconds

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            memcpy(&this->lapTime, &buffer[offset], sizeof(this->lapTime));
            offset = offset + sizeof(this->lapTime);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;
            root["lapTime"] = this->lapTime;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "FastestLap {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << "   "
                       << "lapTime: " << this->lapTime << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "VehicleIndex, LapTime"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            str.append(",");
            str.append(std::to_string(this->lapTime));
            return str;
        }
    } FastestLap;

    struct {
        uint8 vehicleIdx;  // Vehicle index of car retiring

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "Retirement {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "VehicleIndex"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            return str;
        }

    } Retirement;

    struct {
        uint8 vehicleIdx;  // Vehicle index of team mate

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "TeamMateInPits {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "VehicleIndex"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            return str;
        }

    } TeamMateInPits;

    struct {
        uint8 vehicleIdx;  // Vehicle index of the race winner

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "RaceWinner {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "VehicleIndex"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            return str;
        }

    } RaceWinner;

    struct {                     // Not Working
        uint8 penaltyType;       // Penalty type – see Appendices
        uint8 infringementType;  // Infringement type – see Appendices
        uint8 vehicleIdx;  // Vehicle index of the car the penalty is applied to
        uint8 otherVehicleIdx;  // Vehicle index of the other car involved
        uint8 time;    // Time gained, or time spent doing action in seconds
        uint8 lapNum;  // Lap the penalty occurred on
        uint8 placesGained;  // Number of places gained by this

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->penaltyType, &buffer[offset],
                   sizeof(this->penaltyType));
            offset += sizeof(this->penaltyType);
            memcpy(&this->infringementType, &buffer[offset],
                   sizeof(this->infringementType));
            offset += sizeof(this->infringementType);
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset += sizeof(this->vehicleIdx);
            memcpy(&this->otherVehicleIdx, &buffer[offset],
                   sizeof(this->otherVehicleIdx));
            offset += sizeof(this->otherVehicleIdx);
            memcpy(&this->time, &buffer[offset], sizeof(this->time));
            offset += sizeof(this->time);
            memcpy(&this->lapNum, &buffer[offset], sizeof(this->lapNum));
            offset += sizeof(this->lapNum);
            memcpy(&this->placesGained, &buffer[offset],
                   sizeof(this->placesGained));
            offset += sizeof(this->placesGained);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["penaltyType"] = this->penaltyType;
            root["infringementType"] = this->infringementType;
            root["vehicleIdx"] = this->vehicleIdx;
            root["otherVehicleIdx"] = this->otherVehicleIdx;
            root["time"] = this->time;
            root["lapNum"] = this->lapNum;
            root["placesGained"] = this->placesGained;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "Penalty {" << std::endl;
            std::wcout << "   "
                       << "penaltyType: " << this->penaltyType << std::endl;
            std::wcout << "   "
                       << "infringementType: " << this->infringementType
                       << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << "   "
                       << "otherVehicleIdx: " << this->otherVehicleIdx
                       << std::endl;
            std::wcout << "   "
                       << "time: " << this->time << std::endl;
            std::wcout << "   "
                       << "lapNum: " << this->lapNum << std::endl;
            std::wcout << "   "
                       << "placesGained: " << this->placesGained << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() {
            return "PenaltyType,InfringementType,VehicleIndex,"
                   "OtherVehicleIndex,Time,LapNum,PlacesGained";
        }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->penaltyType));
            str.append(",");
            str.append(std::to_string(this->infringementType));
            str.append(",");
            str.append(std::to_string(this->vehicleIdx));
            str.append(",");
            str.append(std::to_string(this->otherVehicleIdx));
            str.append(",");
            str.append(std::to_string(this->time));
            str.append(",");
            str.append(std::to_string(this->lapNum));
            str.append(",");
            str.append(std::to_string(this->placesGained));
            return str;
        }

    } Penalty;

    struct {
        uint8 vehicleIdx;  // Vehicle index of the vehicle triggering speed trap
        float speed;       // Top speed achieved in kilometres per hour
        uint8 overallFastestInSession;  // Overall fastest speed in session = 1,
                                        // otherwise 0
        uint8 driverFastestInSession;   // Fastest speed for driver in session =
                                        // 1, otherwise 0
        uint8 fastestVehicleIdxInSession; // Vehicle index of the vehicle that is the fastest in this session
        float fastestSpeedInSession;    // Speed of the vehicle that is the fastest in this session


        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            memcpy(&this->speed, &buffer[offset], sizeof(this->speed));
            offset = offset + sizeof(this->speed);
            memcpy(&this->overallFastestInSession, &buffer[offset],
                   sizeof(this->overallFastestInSession));
            offset = offset + sizeof(this->overallFastestInSession);
            memcpy(&this->driverFastestInSession, &buffer[offset],
                   sizeof(this->driverFastestInSession));
            offset = offset + sizeof(this->driverFastestInSession);
            memcpy(&this->fastestVehicleIdxInSession, &buffer[offset],
                   sizeof(this->fastestVehicleIdxInSession));
            offset = offset + sizeof(this->fastestVehicleIdxInSession);
            memcpy(&this->fastestSpeedInSession, &buffer[offset],
                   sizeof(this->fastestSpeedInSession));
            offset = offset + sizeof(this->fastestSpeedInSession);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;
            root["speed"] = this->speed;
            root["overallFastestInSession"] = this->overallFastestInSession;
            root["driverFastestInSession"] = this->driverFastestInSession;
            root["fastestVehicleIdxInSession"] = this->fastestVehicleIdxInSession;
            root["fastestSpeedInSession"] = this->fastestSpeedInSession;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "SpeedTrap {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << "   "
                       << "speed: " << this->speed << std::endl;
            std::wcout << "   "
                       << "overallFastestInSession: "
                       << this->overallFastestInSession << std::endl;
            std::wcout << "   "
                       << "driverFastestInSession: "
                       << this->driverFastestInSession << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() {
            return "VehicleIndex,Speed,OverallFastestInSession,"
                   "DriverFastestInSession";
        }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            str.append(",");
            str.append(std::to_string(this->speed));
            str.append(",");
            str.append(std::to_string(this->overallFastestInSession));
            str.append(",");
            str.append(std::to_string(this->driverFastestInSession));

            return str;
        }

    } SpeedTrap;

    struct {
        uint8 numLights;  // Number of lights showing

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->numLights, &buffer[offset], sizeof(this->numLights));
            offset = offset + sizeof(this->numLights);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["numLights"] = this->numLights;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "StartLights {" << std::endl;
            std::wcout << "   "
                       << "numLights: " << this->numLights << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "numLights"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->numLights));
            return str;
        }
    } StartLIghts;

    struct {
        uint8 vehicleIdx;  // Vehicle index of the vehicle serving drive through

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "DriveThrough {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "vehicleIdx"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            return str;
        }
    } DriveThroughPenaltyServed;

    struct {
        uint8 vehicleIdx;  // Vehicle index of the vehicle serving stop go

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->vehicleIdx, &buffer[offset],
                   sizeof(this->vehicleIdx));
            offset = offset + sizeof(this->vehicleIdx);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["vehicleIdx"] = this->vehicleIdx;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "StopGo {" << std::endl;
            std::wcout << "   "
                       << "vehicleIdx: " << this->vehicleIdx << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "vehicleIdx"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->vehicleIdx));
            return str;
        }
    } StopGoPenaltyServed;

    struct {
        uint32 flashbackFrameIdentifier;  // Frame identifier flashed back to
        float flashbackSessionTime;       // Session time flashed back to

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->flashbackFrameIdentifier, &buffer[offset],
                   sizeof(this->flashbackFrameIdentifier));
            offset = offset + sizeof(this->flashbackFrameIdentifier);
            memcpy(&this->flashbackSessionTime, &buffer[offset],
                   sizeof(this->flashbackSessionTime));
            offset = offset + sizeof(this->flashbackSessionTime);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;
            
            root["flashbackFrameIdentifier"] = this->flashbackFrameIdentifier;
            root["flashbackSessionTime"] = this->flashbackSessionTime;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "Flashback {" << std::endl;
            std::wcout << "   "
                       << "flashbackFrameIdentifier: "
                       << this->flashbackFrameIdentifier << std::endl;
            std::wcout << "   "
                       << "flashbackSessionTime: " << this->flashbackSessionTime
                       << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() {
            return "FlashbackFrameIdentifier,FlashbackSessionTime";
        }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->flashbackFrameIdentifier));
            str.append(",");
            str.append(std::to_string(this->flashbackSessionTime));
            return str;
        }
    } Flashback;

    struct {
        uint32 m_buttonStatus;  // Bit flags specifying which buttons are being
                                // pressed currently - see appendices

        unsigned long get(char* buffer, unsigned long offset) {
            memcpy(&this->m_buttonStatus, &buffer[offset],
                   sizeof(this->m_buttonStatus));
            offset = offset + sizeof(this->m_buttonStatus);
            return offset;
        }

        Json::Value toJSON(){
            Json::Value root;

            root["buttonStatus"] = this->m_buttonStatus;

            return root;
        }

        void print() {
            std::wcout << " "
                       << "Button {" << std::endl;
            std::wcout << "   "
                       << "m_buttonStatus: " << this->m_buttonStatus
                       << std::endl;
            std::wcout << " "
                       << "}" << std::endl;
        }

        std::string head_to_string() { return "m_buttonStatus"; }

        std::string to_string(bool flag) {
            std::string str;
            if (flag) {
                str.append(this->head_to_string());
                str.append("\n");
            }
            str.append(std::to_string(this->m_buttonStatus));
            return str;
        }
    } Buttons;
};

struct PacketEventData {
    PacketHeader m_header;  // Header

    uint8 m_eventStringCode[4];       // Event string code, see below
    EventDataDetails m_eventDetails;  // Event details - should be interpreted
                                      // differently for each type

    void get(char* buffer) {
        unsigned long offset = this->m_header.get(buffer);

        memcpy(&this->m_eventStringCode, &buffer[offset],
               sizeof(m_eventStringCode));
        offset = offset + sizeof(m_eventStringCode);

        std::string eventString = (const char*)this->m_eventStringCode;
        eventString = eventString.substr(0, 4);
        const char* eventConstChar = (const char*)eventString.c_str();
#if defined(_WIN64) || defined(_WIN32)
        if (strcmp(eventConstChar, "SSTA") == 0) {
        } else if (strcmp(eventConstChar, "SEND") == 0) {
        } else if (strcmp(eventConstChar, "FTLP") == 0) {
            this->m_eventDetails.FastestLap.get(buffer, offset);
        } else if (strcmp(eventConstChar, "RTMT") == 0) {
            this->m_eventDetails.Retirement.get(buffer, offset);
        } else if (strcmp(eventConstChar, "DRSE") == 0) {
        } else if (strcmp(eventConstChar, "DRSD") == 0) {
        } else if (strcmp(eventConstChar, "TMPT") == 0) {
            this->m_eventDetails.TeamMateInPits.get(buffer, offset);
        } else if (strcmp(eventConstChar, "CHQF") == 0) {
        } else if (strcmp(eventConstChar, "RCWN") == 0) {
            this->m_eventDetails.RaceWinner.get(buffer, offset);
        } else if (strcmp(eventConstChar, "PENA") == 0) {
            this->m_eventDetails.Penalty.get(buffer, offset);
        } else if (strcmp(eventConstChar, "SPTP") == 0) {
            this->m_eventDetails.SpeedTrap.get(buffer, offset);
        } else if (strcmp(eventConstChar, "STLG") == 0) {
            this->m_eventDetails.StartLIghts.get(buffer, offset);
        } else if (strcmp(eventConstChar, "LGOT") == 0) {
        } else if (strcmp(eventConstChar, "DTSV") == 0) {
            this->m_eventDetails.DriveThroughPenaltyServed.get(buffer, offset);
        } else if (strcmp(eventConstChar, "SGSV") == 0) {
            this->m_eventDetails.StopGoPenaltyServed.get(buffer, offset);
        } else if (strcmp(eventConstChar, "FLBK") == 0) {
            this->m_eventDetails.Flashback.get(buffer, offset);
        } else if (strcmp(eventConstChar, "BUTN") == 0) {
            this->m_eventDetails.Buttons.get(buffer, offset);
        } else {
            std::cout << "EventStringCode: " << eventString << std::endl;
        }

#endif
#if defined(__unix__) || defined(__APPLE__)
        if (std::strcmp(eventConstChar, "SSTA") == 0) {
        } else if (std::strcmp(eventConstChar, "SEND") == 0) {
        } else if (std::strcmp(eventConstChar, "FTLP") == 0) {
            this->m_eventDetails.FastestLap.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "RTMT") == 0) {
            this->m_eventDetails.Retirement.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "DRSE") == 0) {
        } else if (std::strcmp(eventConstChar, "DRSD") == 0) {
        } else if (std::strcmp(eventConstChar, "TMPT") == 0) {
            this->m_eventDetails.TeamMateInPits.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "CHQF") == 0) {
        } else if (std::strcmp(eventConstChar, "RCWN") == 0) {
            this->m_eventDetails.RaceWinner.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "PENA") == 0) {
            this->m_eventDetails.Penalty.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "SPTP") == 0) {
            this->m_eventDetails.SpeedTrap.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "STLG") == 0) {
            this->m_eventDetails.StartLIghts.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "LGOT") == 0) {
        } else if (std::strcmp(eventConstChar, "DTSV") == 0) {
            this->m_eventDetails.DriveThroughPenaltyServed.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "SGSV") == 0) {
            this->m_eventDetails.StopGoPenaltyServed.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "FLBK") == 0) {
            this->m_eventDetails.Flashback.get(buffer, offset);
        } else if (std::strcmp(eventConstChar, "BUTN") == 0) {
            this->m_eventDetails.Buttons.get(buffer, offset);
        } else {
            std::cout << "EventStringCode: " << eventString << std::endl;
        }

#endif
    }

    Json::Value toJSON(Json::Value root){
        std::string eventString = (const char*)this->m_eventStringCode;
        eventString = eventString.substr(0, 4);
        const char* eventConstChar = (const char*)eventString.c_str();

        root["EventData"]["eventStringCode"] = eventConstChar;

#if defined(_WIN64) || defined(_WIN32)
        if (strcmp(eventConstChar, "SSTA") == 0) {
            root["EventData"]["eventDetails"] = "SSTA";
        } else if (strcmp(eventConstChar, "SEND") == 0) {
            root["EventData"]["eventDetails"] = "SEND";
        } else if (strcmp(eventConstChar, "FTLP") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.FastestLap.toJSON();
        } else if (strcmp(eventConstChar, "RTMT") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Retirement.toJSON();
        } else if (strcmp(eventConstChar, "DRSE") == 0) {
            root["EventData"]["eventDetails"] = "DRSE";
        } else if (strcmp(eventConstChar, "DRSD") == 0) {
            root["EventData"]["eventDetails"] = "DRSD";
        } else if (strcmp(eventConstChar, "TMPT") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.TeamMateInPits.toJSON();
        } else if (strcmp(eventConstChar, "CHQF") == 0) {
            root["EventData"]["eventDetails"] = "CHQF";
        } else if (strcmp(eventConstChar, "RCWN") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.RaceWinner.toJSON();
        } else if (strcmp(eventConstChar, "PENA") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Penalty.toJSON();
        } else if (strcmp(eventConstChar, "SPTP") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.SpeedTrap.toJSON();
        } else if (strcmp(eventConstChar, "STLG") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.StartLIghts.toJSON();
        } else if (strcmp(eventConstChar, "LGOT") == 0) {
            root["EventData"]["eventDetails"] = "LGOT";
        } else if (strcmp(eventConstChar, "DTSV") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.DriveThroughPenaltyServed.toJSON();
        } else if (strcmp(eventConstChar, "SGSV") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.StopGoPenaltyServed.toJSON();
        } else if (strcmp(eventConstChar, "FLBK") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Flashback.toJSON();
        } else if (strcmp(eventConstChar, "BUTN") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Buttons.toJSON();
        } else {
            std::cout << "EventStringCode: " << eventString << " NOT RECOGNIZED!"<<std::endl;
        }
#endif
#if defined(__unix__) || defined(__APPLE__)
        if (std::strcmp(eventConstChar, "SSTA") == 0) {
            root["EventData"]["eventDetails"] = "SSTA";
        } else if (std::strcmp(eventConstChar, "SEND") == 0) {
            root["EventData"]["eventDetails"] = "SEND";
        } else if (std::strcmp(eventConstChar, "FTLP") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.FastestLap.toJSON();
        } else if (std::strcmp(eventConstChar, "RTMT") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Retirement.toJSON();
        } else if (std::strcmp(eventConstChar, "DRSE") == 0) {
            root["EventData"]["eventDetails"] = "DRSE";
        } else if (std::strcmp(eventConstChar, "DRSD") == 0) {
            root["EventData"]["eventDetails"] = "DRSD";
        } else if (std::strcmp(eventConstChar, "TMPT") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.TeamMateInPits.toJSON();
        } else if (std::strcmp(eventConstChar, "CHQF") == 0) {
            root["EventData"]["eventDetails"] = "CHQF";
        } else if (std::strcmp(eventConstChar, "RCWN") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.RaceWinner.toJSON();
        } else if (std::strcmp(eventConstChar, "PENA") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Penalty.toJSON();
        } else if (std::strcmp(eventConstChar, "SPTP") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.SpeedTrap.toJSON();
        } else if (std::strcmp(eventConstChar, "STLG") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.StartLIghts.toJSON();
        } else if (std::strcmp(eventConstChar, "LGOT") == 0) {
            root["EventData"]["eventDetails"] = "LGOT";
        } else if (std::strcmp(eventConstChar, "DTSV") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.DriveThroughPenaltyServed.toJSON();
        } else if (std::strcmp(eventConstChar, "SGSV") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.StopGoPenaltyServed.toJSON();
        } else if (std::strcmp(eventConstChar, "FLBK") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Flashback.toJSON();
        } else if (std::strcmp(eventConstChar, "BUTN") == 0) {
            root["EventData"]["eventDetails"] = this->m_eventDetails.Buttons.toJSON();
        } else {
            std::cout << "EventStringCode: " << eventString << " NOT RECOGNIZED!"<<std::endl;
        }
#endif

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(EVENT_PATH, root["EventData"], frame);
        
        return root;
    }

    void print() {
        std::string eventString = (const char*)this->m_eventStringCode;
        eventString = eventString.substr(0, 4);
        const char* eventConstChar = (const char*)eventString.c_str();

        std::wcout << " "
                   << "PacketEventData {" << std::endl;
        std::cout << "   "
                  << "m_eventStringCode: " << eventConstChar << std::endl;
        std::wcout << "   "
                   << "m_eventDetails: " << std::endl;
#if defined(_WIN64) || defined(_WIN32)
        if (strcmp(eventConstChar, "SSTA") == 0) {
            std::wcout << "      Session Started" << std::endl;
        } else if (strcmp(eventConstChar, "SEND") == 0) {
            std::wcout << "      Session Ended" << std::endl;
        } else if (strcmp(eventConstChar, "FTLP") == 0) {
            m_eventDetails.FastestLap.print();
        } else if (strcmp(eventConstChar, "RTMT") == 0) {
            m_eventDetails.Retirement.print();
        } else if (strcmp(eventConstChar, "DRSE") == 0) {
            std::wcout << "      DRS Enabled" << std::endl;
        } else if (strcmp(eventConstChar, "DRSD") == 0) {
            std::wcout << "      DRS Disabled" << std::endl;
        } else if (strcmp(eventConstChar, "TMPT") == 0) {
            m_eventDetails.TeamMateInPits.print();
        } else if (strcmp(eventConstChar, "CHQF") == 0) {
            std::wcout << "      Chequered Flag" << std::endl;
        } else if (strcmp(eventConstChar, "RCWN") == 0) {
            m_eventDetails.RaceWinner.print();
        } else if (strcmp(eventConstChar, "PENA") == 0) {
            m_eventDetails.Penalty.print();
        } else if (strcmp(eventConstChar, "SPTP") == 0) {
            m_eventDetails.SpeedTrap.print();
        } else if (strcmp(eventConstChar, "STLG") == 0) {
            m_eventDetails.StartLIghts.print();
        } else if (strcmp(eventConstChar, "LGOT") == 0) {
            std::wcout << "      Lights Out" << std::endl;
        } else if (strcmp(eventConstChar, "DTSV") == 0) {
            m_eventDetails.DriveThroughPenaltyServed.print();
        } else if (strcmp(eventConstChar, "SGSV") == 0) {
            m_eventDetails.StopGoPenaltyServed.print();
        } else if (strcmp(eventConstChar, "FLBK") == 0) {
            m_eventDetails.Flashback.print();
        } else if (strcmp(eventConstChar, "BUTN") == 0) {
            m_eventDetails.Buttons.print();
        } else {
            std::cout << "EventStringCode: " << eventString << std::endl;
        }
#endif
#if defined(__unix__) || defined(__APPLE__)
        if (std::strcmp(eventConstChar, "SSTA") == 0) {
            std::wcout << "      Session Started" << std::endl;
        } else if (std::strcmp(eventConstChar, "SEND") == 0) {
            std::wcout << "      Session Ended" << std::endl;
        } else if (std::strcmp(eventConstChar, "FTLP") == 0) {
            m_eventDetails.FastestLap.print();
        } else if (std::strcmp(eventConstChar, "RTMT") == 0) {
            m_eventDetails.Retirement.print();
        } else if (std::strcmp(eventConstChar, "DRSE") == 0) {
            std::wcout << "      DRS Enabled" << std::endl;
        } else if (std::strcmp(eventConstChar, "DRSD") == 0) {
            std::wcout << "      DRS Disabled" << std::endl;
        } else if (std::strcmp(eventConstChar, "TMPT") == 0) {
            m_eventDetails.TeamMateInPits.print();
        } else if (std::strcmp(eventConstChar, "CHQF") == 0) {
            std::wcout << "      Chequered Flag" << std::endl;
        } else if (std::strcmp(eventConstChar, "RCWN") == 0) {
            m_eventDetails.RaceWinner.print();
        } else if (std::strcmp(eventConstChar, "PENA") == 0) {
            m_eventDetails.Penalty.print();
        } else if (std::strcmp(eventConstChar, "SPTP") == 0) {
            m_eventDetails.SpeedTrap.print();
        } else if (std::strcmp(eventConstChar, "STLG") == 0) {
            m_eventDetails.StartLIghts.print();
        } else if (std::strcmp(eventConstChar, "LGOT") == 0) {
            std::wcout << "      Lights Out" << std::endl;
        } else if (std::strcmp(eventConstChar, "DTSV") == 0) {
            m_eventDetails.DriveThroughPenaltyServed.print();
        } else if (std::strcmp(eventConstChar, "SGSV") == 0) {
            m_eventDetails.StopGoPenaltyServed.print();
        } else if (std::strcmp(eventConstChar, "FLBK") == 0) {
            m_eventDetails.Flashback.print();
        } else if (std::strcmp(eventConstChar, "BUTN") == 0) {
            m_eventDetails.Buttons.print();
        } else {
            std::cout << "EventStringCode: " << eventString << std::endl;
        }
#endif

        std::wcout << std::endl;
    }

    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",EventString,");
        s.append(
            "VehicleIndex,LapTime,Speed,PenaltyType,InfringementType,"
            "OtherVehicleIndex,Time,LapNum,PlacesGained,"
            "OverallFastestInSession,DriverFastestInSession,numLights,"
            "flashbackFrameIdentifier,flashbackSessionTime,Button");
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(this->m_header.to_string(false));
        str.append(",");
        std::string eventString = (const char*)this->m_eventStringCode;
        eventString = eventString.substr(0, 4);
        str.append(eventString);
        str.append(",");
        const char* eventConstChar = (const char*)eventString.c_str();

#if defined(_WIN64) || defined(_WIN32)
        if (strcmp(eventConstChar, "SSTA") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "SEND") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "FTLP") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.FastestLap.vehicleIdx));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.FastestLap.lapTime));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "RTMT") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.Retirement.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "DRSE") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "DRSD") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "TMPT") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.TeamMateInPits.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "CHQF") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "RCWN") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.RaceWinner.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "PENA") == 0) {
            str.append(std::to_string(this->m_eventDetails.Penalty.vehicleIdx));
            str.append(",-,-,");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.penaltyType));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.infringementType));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.otherVehicleIdx));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Penalty.time));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Penalty.lapNum));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.placesGained));
            str.append(",-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "SPTP") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.SpeedTrap.vehicleIdx));
            str.append(",-,");
            str.append(std::to_string(this->m_eventDetails.SpeedTrap.speed));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "STLG") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.StartLIghts.numLights));
            str.append(",-,-,-\n");
        } else if (strcmp(eventConstChar, "LGOT") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "DTSV") == 0) {
            str.append(std::to_string(this->m_eventDetails.DriveThroughPenaltyServed.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "SGSV") == 0) {
            str.append(std::to_string(this->m_eventDetails.StopGoPenaltyServed.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (strcmp(eventConstChar, "FLBK") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.Flashback.flashbackFrameIdentifier));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Flashback.flashbackSessionTime));
            str.append(",-\n");
        } else if (strcmp(eventConstChar, "BUTN") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.Buttons.m_buttonStatus));
            str.append("\n");
        } else {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        }
#endif
#if defined(__linux__) || defined(__APPLE__)
        if (std::strcmp(eventConstChar, "SSTA") == 0) {
            str.append("-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "SEND") == 0) {
            str.append("-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "FTLP") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.FastestLap.vehicleIdx));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.FastestLap.lapTime));
            str.append(",-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "RTMT") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.Retirement.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "DRSE") == 0) {
            str.append("-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "DRSD") == 0) {
            str.append("-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "TMPT") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.TeamMateInPits.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "CHQF") == 0) {
            str.append("-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "RCWN") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.RaceWinner.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "PENA") == 0) {
            str.append(std::to_string(this->m_eventDetails.Penalty.vehicleIdx));
            str.append(",-,-,");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.penaltyType));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.infringementType));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.otherVehicleIdx));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Penalty.time));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Penalty.lapNum));
            str.append(",");
            str.append(
                std::to_string(this->m_eventDetails.Penalty.placesGained));
            str.append("\n");
        } else if (std::strcmp(eventConstChar, "SPTP") == 0) {
            str.append(
                std::to_string(this->m_eventDetails.SpeedTrap.vehicleIdx));
            str.append(",-,");
            str.append(std::to_string(this->m_eventDetails.SpeedTrap.speed));
            str.append(",-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "STLG") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.StartLIghts.numLights));
            str.append(",-,-,-\n");
        } else if (std::strcmp(eventConstChar, "LGOT") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "DTSV") == 0) {
            str.append(std::to_string(this->m_eventDetails.DriveThroughPenaltyServed.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "SGSV") == 0) {
            str.append(std::to_string(this->m_eventDetails.StopGoPenaltyServed.vehicleIdx));
            str.append(",-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        } else if (std::strcmp(eventConstChar, "FLBK") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.Flashback.flashbackFrameIdentifier));
            str.append(",");
            str.append(std::to_string(this->m_eventDetails.Flashback.flashbackSessionTime));
            str.append(",-\n");
        } else if (std::strcmp(eventConstChar, "BUTN") == 0) {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,");
            str.append(std::to_string(this->m_eventDetails.Buttons.m_buttonStatus));
            str.append("\n");
        } else {
            str.append("-,-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
        }
#endif

        return str;
    }

    void to_csv(const char* dirname) {
        std::string filename = std::string(dirname) + "/Event.csv";
        std::ofstream myfile;
        if (std::ifstream(filename)) {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(false);
        } else {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(true);
        }
        myfile.close();
    }
};
#endif
