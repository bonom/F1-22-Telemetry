#ifndef __Header_h__
#define __Header_h__

#include "Costants.h"

struct PacketHeader
{
    uint16    m_packetFormat;             // 2022
    uint8     m_gameMajorVersion;         // Game major version - "X.00"
    uint8     m_gameMinorVersion;         // Game minor version - "1.XX"
    uint8     m_packetVersion;            // Version of this packet type,all start from 1
    uint8     m_packetId;                 // Identifier for the packet type,see below
    uint64    m_sessionUID;               // Unique identifier for the session
    float     m_sessionTime;              // Session timestamp
    uint32    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;           // Index of player's car in the array
    uint8     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
                                              // 255 if no second player

    unsigned long get(char* buffer){
        unsigned long offset = 0;
        memcpy(&this->m_packetFormat,&buffer[offset],sizeof(this->m_packetFormat));
        offset = offset + sizeof(this->m_packetFormat);
        memcpy(&this->m_gameMajorVersion,&buffer[offset],sizeof(this->m_gameMajorVersion));
        offset = offset + sizeof(this->m_gameMajorVersion);
        memcpy(&this->m_gameMinorVersion,&buffer[offset],sizeof(this->m_gameMinorVersion));
        offset = offset + sizeof(this->m_gameMinorVersion);
        memcpy(&this->m_packetVersion,&buffer[offset],sizeof(this->m_packetVersion));
        offset = offset + sizeof(this->m_packetVersion);
        memcpy(&this->m_packetId,&buffer[offset],sizeof(this->m_packetId));
        offset = offset + sizeof(this->m_packetId);
        memcpy(&this->m_sessionUID,&buffer[offset],sizeof(this->m_sessionUID));
        offset = offset + sizeof(this->m_sessionUID);
        memcpy(&this->m_sessionTime,&buffer[offset],sizeof(this->m_sessionTime));
        offset = offset + sizeof(this->m_sessionTime);
        memcpy(&this->m_frameIdentifier,&buffer[offset],sizeof(this->m_frameIdentifier));
        offset = offset + sizeof(this->m_frameIdentifier);
        memcpy(&this->m_playerCarIndex,&buffer[offset],sizeof(this->m_playerCarIndex));
        offset = offset + sizeof(this->m_playerCarIndex);
        memcpy(&this->m_secondaryPlayerCarIndex,&buffer[offset],sizeof(this->m_secondaryPlayerCarIndex));
        offset = offset + sizeof(this->m_secondaryPlayerCarIndex);

        return offset;
    }

    Json::Value toJSON(Json::Value root){
        root["Header"]["packetFormat"] = this->m_packetFormat;
        root["Header"]["gameMajorVersion"] = this->m_gameMajorVersion;
        root["Header"]["gameMinorVersion"] = this->m_gameMinorVersion;
        root["Header"]["packetVersion"] = this->m_packetVersion;
        root["Header"]["packetId"] = this->m_packetId;
        root["Header"]["sessionUID"] = this->m_sessionUID;
        root["Header"]["sessionTime"] = this->m_sessionTime;
        root["Header"]["frameIdentifier"] = this->m_frameIdentifier;
        root["Header"]["playerCarIndex"] = this->m_playerCarIndex;
        root["Header"]["secondaryPlayerCarIndex"] = this->m_secondaryPlayerCarIndex;

        writeJsonDataToFile(HEADER_PATH, root["Header"], this->m_frameIdentifier);

        return root;
    }
    
    void print() {
        std::wcout << " " << "PacketHeader {" << std::endl;
        std::wcout << "   " << "m_packetFormat: " << this->m_packetFormat << std::endl;
        std::wcout << "   " << "m_gameMajorVersion: " << this->m_gameMajorVersion << std::endl;
        std::wcout << "   " << "m_gameMinorVersion: " << this->m_gameMinorVersion << std::endl;
        std::wcout << "   " << "m_packetVersion: " << this->m_packetVersion << std::endl;
        std::wcout << "   " << "m_packetId: " << Packet_ID_name[this->m_packetId] << std::endl;
        std::wcout << "   " << "m_sessionUID: " << this->m_sessionUID << std::endl;
        std::wcout << "   " << "m_sessionTime: " << this->m_sessionTime << std::endl;
        std::wcout << "   " << "m_frameIdentifier: " << this->m_frameIdentifier << std::endl;
        std::wcout << "   " << "m_playerCarIndex: " << this->m_playerCarIndex << std::endl;
        std::wcout << "   " << "m_secondaryPlayerCarIndex: " << this->m_secondaryPlayerCarIndex << std::endl;
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        return "PacketFormat,GameMajorVersion,GameMinorVersion,PacketVersion,PacketId,SessionUID,SessionTime,FrameIdentifier,PlayerCarIndex,SecondaryPlayerCarIndex";
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_packetFormat));
        str.append(",");
        str.append(std::to_string(this->m_gameMajorVersion));
        str.append(",");
        str.append(std::to_string(this->m_gameMinorVersion));
        str.append(",");
        str.append(std::to_string(this->m_packetVersion));
        str.append(",");
        str.append(std::to_string(this->m_packetId));
        str.append(",");
        str.append(std::to_string(this->m_sessionUID));
        str.append(",");
        str.append(std::to_string(this->m_sessionTime));
        str.append(",");
        str.append(std::to_string(this->m_frameIdentifier));
        str.append(",");
        str.append(std::to_string(this->m_playerCarIndex));
        str.append(",");
        str.append(std::to_string(this->m_secondaryPlayerCarIndex));
        
        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Header.csv";
        std::ofstream myfile;
        if (std::ifstream(filename)){
            myfile.open(filename,std::ios_base::app);
            myfile << this->to_string(false)<<"\n";
        }else{
            myfile.open(filename,std::ios_base::app);
            myfile << this->to_string(true)<<"\n";
        }
        myfile.close();
    }
};




#endif