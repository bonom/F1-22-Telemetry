#ifndef __Participant_h__
#define __Participant_h__

#include "Costants.h"
#include "Header.h"

struct ParticipantData
{
    uint8      m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
    uint8      m_driverId;               // Driver id - see appendix
    uint8      m_networkId;		// Network id – unique identifier for network players
    uint16      m_teamId;                 // Team id - see appendix
    uint8      m_raceNumber;             // Race number of the car
    uint8      m_nationality;            // Nationality of the driver
    char       m_name[48];               // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with … (U+2026) if too long
    uint8      m_yourTelemetry;          // The player's UDP setting,0 = restricted,1 = public

    unsigned long get(char* buffer,unsigned long offset){
        memcpy(&this->m_aiControlled,&buffer[offset],sizeof(this->m_aiControlled));
        offset += sizeof(this->m_aiControlled);
        memcpy(&this->m_driverId,&buffer[offset],sizeof(this->m_driverId));
        offset += sizeof(this->m_driverId);
        memcpy(&this->m_networkId,&buffer[offset],sizeof(this->m_networkId));
        offset += sizeof(this->m_networkId);
        memcpy(&this->m_teamId,&buffer[offset],sizeof(this->m_teamId));
        offset += sizeof(this->m_teamId);

        memcpy(&this->m_raceNumber,&buffer[offset],sizeof(this->m_raceNumber));
        offset += sizeof(this->m_raceNumber);

        memcpy(&this->m_nationality,&buffer[offset],sizeof(this->m_nationality));
        offset += sizeof(this->m_nationality);

        memcpy(&this->m_name,&buffer[offset],sizeof(this->m_name));
        offset += 48UL;

        /*for(int i = 0; i < 48; i++){
            memcpy(&this->m_name[i],&buffer[offset],sizeof(this->m_name[i]));
            offset += sizeof(this->m_name[i]);
            if (this->m_name[i] == '\0'){
                offset += sizeof((48-i-1)*this->m_name[i]);
                wprintf(L"\nOffset = %d\n",offset);
                break;
            }
            wprintf(L"%c",this->m_name[i]);
        }*/

        memcpy(&this->m_yourTelemetry,&buffer[offset],sizeof(this->m_yourTelemetry));
        offset += sizeof(this->m_yourTelemetry);
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["aiControlled"] = this->m_aiControlled;
        root["driverId"] = this->m_driverId;
        root["networkId"] = this->m_networkId;
        root["teamId"] = this->m_teamId;
        root["raceNumber"] = this->m_raceNumber;
        root["nationality"] = this->m_nationality;
        root["name"] = this->m_name;
        root["yourTelemetry"] = this->m_yourTelemetry;

        return root;
    }

    void print(){
        std::wcout << " " << "ParticipationData {" << std::endl;
        std::wcout << "   " << "m_aiControlled: " << this->m_aiControlled << std::endl;
        std::wcout << "   " << "m_driverId: " << Drivers[this->m_driverId] << std::endl;
        std::wcout << "   " << "m_networkId: " << this->m_networkId << std::endl;
        std::wcout << "   " << "m_teamId: " << Teams[this->m_teamId] << std::endl;
        std::wcout << "   " << "m_raceNumber: " << this->m_raceNumber << std::endl;
        std::wcout << "   " << "m_nationality: " << Nationalities[this->m_nationality] << std::endl;
        std::wcout << "   " << "m_name: ";
        int i = 0;
        while (this->m_name[i] != '\0'){
            std::wcout << this->m_name[i];
            i += 1;
        }
        std::wcout << std::endl;
        std::wcout << "   " << "m_yourTelemetry: " << this->m_yourTelemetry << std::endl;
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        return "Ai_Controlled,DriverId,NetworkId,TeamId,RaceNumber,Nationality,Name,YourTelemetry";
    }

    std::string to_string(bool flag){
        std::string str;
        if(flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_aiControlled));
        str.append(",");
        str.append(std::to_string(this->m_driverId));
        str.append(",");
        str.append(std::to_string(this->m_networkId));
        str.append(",");
        str.append(std::to_string(this->m_teamId));
        str.append(",");
        str.append(std::to_string(this->m_raceNumber));
        str.append(",");
        str.append(std::to_string(this->m_nationality));
        str.append(",");
        str.append((const char*)this->m_name);
        str.append(",");
        str.append(std::to_string(this->m_yourTelemetry));
        return str;

    }

};

struct PacketParticipantsData
{
    PacketHeader    m_header;           // Header

    uint8           m_numActiveCars;	// Number of active cars in the data – should match number of
                                        // cars on HUD
    ParticipantData m_participants[22];

    void get(char* buffer){
        unsigned long offset = this->m_header.get(buffer);
        
        memcpy(&this->m_numActiveCars,&buffer[offset],sizeof(this->m_numActiveCars));
        offset += sizeof(this->m_numActiveCars);
       
        for (int i = 0; i < this->m_numActiveCars; i++){
            offset = this->m_participants[i].get(buffer,offset);
        }
    }

    Json::Value toJSON(Json::Value root){
        root["ParticipantData"]["numActiveCars"] = this->m_numActiveCars;
        for (int i = 0; i < this->m_numActiveCars; i++){
            root["ParticipantData"]["carParticipantData"][i] = this->m_participants[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(PARTICIPANT_PATH, root["ParticipantData"], frame);

        return root;
    }

    void print(){
        std::wcout << " " << "PacketParticipantsData {" << std::endl;
        std::wcout << "   " << "m_numActiveCars: " << this->m_numActiveCars << std::endl;
        for (int i = 0; i < this->m_numActiveCars; i++){
            std::wcout << "   " << "m_participants[" << i << "]: " << std::endl;
            this->m_participants[i].print();
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",NumActiveCars,CarIndex,");
        s.append(this->m_participants->head_to_string());
        return s;
    }

    std::string to_string(bool flag){
        std::string str;
        if(flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < this->m_numActiveCars; i++){
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(this->m_numActiveCars));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(this->m_participants[i].to_string(false));
            str.append("\n");
        }
        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Participant.csv";
        std::ofstream myfile;
        if (std::ifstream(filename)){
            myfile.open(filename,std::ios_base::app);
            myfile << this->to_string(false);
        }else{
            myfile.open(filename,std::ios_base::app);
            myfile << this->to_string(true);
        }
        myfile.close();
    }

};


#endif 