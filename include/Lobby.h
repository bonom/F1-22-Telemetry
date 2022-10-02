#ifndef __Lobby_h__
#define __Lobby_h__

#include "Costants.h"
#include "Header.h"

struct LobbyInfoData
{
    uint8     m_aiControlled;            // Whether the vehicle is AI (1) or Human (0) controlled
    uint8     m_teamId;                  // Team id - see appendix (255 if no team currently selected)
    uint8     m_nationality;             // Nationality of the driver
    char      m_name[48];		// Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with ... (U+2026) if too long
    uint8     m_carNumber;               // Car number of the player
    uint8     m_readyStatus;             // 0 = not ready, 1 = ready, 2 = spectating


    unsigned long get(char * buffer,unsigned long offset){
        memcpy(&this->m_aiControlled,&buffer[offset],sizeof(this->m_aiControlled));
        offset = offset + sizeof(this->m_aiControlled);
        memcpy(&this->m_teamId,&buffer[offset],sizeof(this->m_teamId));
        offset = offset + sizeof(this->m_teamId);
        memcpy(&this->m_nationality,&buffer[offset],sizeof(this->m_nationality));
        offset = offset + sizeof(this->m_nationality);
        for (int i = 0; i < 48; i++){
            memcpy(&this->m_name,&buffer[offset],sizeof(this->m_name));
            offset = offset + sizeof(this->m_name);
        }
        memcpy(&this->m_carNumber,&buffer[offset],sizeof(this->m_carNumber));
        offset = offset + sizeof(this->m_carNumber);
        memcpy(&this->m_readyStatus,&buffer[offset],sizeof(this->m_readyStatus));
        offset = offset + sizeof(this->m_readyStatus);
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["aiControlled"] = this->m_aiControlled;
        root["teamId"] = this->m_teamId;
        root["nationality"] = this->m_nationality;
        root["name"] = this->m_name;
        root["carNumber"] = this->m_carNumber;
        root["readyStatus"] = this->m_readyStatus;
        
        return root;
    }

    void print(){
        std::wcout << " " << "LobbyInfoData {" << std::endl;
        std::wcout << "   " << " m_aiControlled: "<< this->m_aiControlled << std::endl;
        std::wcout << "   " << " m_teamId: "<< Teams[this->m_teamId] << std::endl;
        std::wcout << "   " << " m_nationality: "<< Nationalities[this->m_nationality] << std::endl;
        std::wcout << "   " << " m_name: ";
        for (int i = 0; i < 48; i++){
            std::wcout << this->m_name[i];
        }
        std::wcout << std::endl;
        std::wcout << "   " << " m_carNumber: "<< this->m_carNumber << std::endl;
        std::wcout << "   " << " m_readyStatus: "<< this->m_readyStatus << std::endl;
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        return "AIControlled,TeamId,Nationality,Name,CarNumber,ReadyStatus";
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_aiControlled));
        str.append(",");
        str.append(std::to_string(this->m_teamId));
        str.append(",");
        str.append(std::to_string(this->m_nationality));
        str.append(",");
        str.append(this->m_name);
        str.append(",");
        str.append(std::to_string(this->m_carNumber));
        str.append(",");
        str.append(std::to_string(this->m_readyStatus));
        str.append("\n");        
        return str;
    }

};

struct PacketLobbyInfoData
{
    PacketHeader    m_header;                       // Header

    // Packet specific data
    uint8               m_numPlayers;               // Number of players in the lobby data
    LobbyInfoData       m_lobbyPlayers[22];

    void get(char * buffer){
        unsigned long offset = this->m_header.get(buffer);
        memcpy(&this->m_numPlayers,&buffer[offset],sizeof(this->m_numPlayers));
        offset = offset + sizeof(this->m_numPlayers);
        for (int i = 0; i < this->m_numPlayers; i++){
            offset = this->m_lobbyPlayers[i].get(buffer,offset);
        }
    }

    Json::Value toJSON(Json::Value root){
        root["LobbyData"]["numPlayers"] = this->m_numPlayers;
        for (int i = 0; i < this->m_numPlayers; i++){
            root["LobbyData"]["carLobbyData"][i] = this->m_lobbyPlayers[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(LOBBY_PATH, root["LobbyData"], frame);

        return root;
    }

    void print(){
        std::wcout << " " << "PacketLobbyInfoData {" << std::endl;
        std::wcout << "   " << " m_numPlayers: "<< this->m_numPlayers << std::endl;
        for (int i = 0; i < (int)this->m_numPlayers; i++){
            std::wcout << "   " << " m_numPlayers[" << i << "]: "<< std::endl;
            this->m_lobbyPlayers[i].print();
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",NumPlayers,CarIndex");
        s.append(this->m_lobbyPlayers->head_to_string());
        return s;
    }

    std::string to_string(bool flag){
        std::string str;
        if(flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < (int) this->m_numPlayers; i++){
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(this->m_numPlayers));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(this->m_lobbyPlayers[i].to_string(false));
            str.append("\n");
        }
        
        return str;
        
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Lobby.csv";
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