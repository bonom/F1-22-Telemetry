#ifndef __Setups_h__
#define __Setups_h__

#include "Costants.h"
#include "Header.h"

struct CarSetupData
{
    uint8     m_frontWing;                // Front wing aero
    uint8     m_rearWing;                 // Rear wing aero
    uint8     m_onThrottle;               // Differential adjustment on throttle (percentage)
    uint8     m_offThrottle;              // Differential adjustment off throttle (percentage)
    float     m_frontCamber;              // Front camber angle (suspension geometry)
    float     m_rearCamber;               // Rear camber angle (suspension geometry)
    float     m_frontToe;                 // Front toe angle (suspension geometry)
    float     m_rearToe;                  // Rear toe angle (suspension geometry)
    uint8     m_frontSuspension;          // Front suspension
    uint8     m_rearSuspension;           // Rear suspension
    uint8     m_frontAntiRollBar;         // Front anti-roll bar
    uint8     m_rearAntiRollBar;          // Front anti-roll bar
    uint8     m_frontSuspensionHeight;    // Front ride height
    uint8     m_rearSuspensionHeight;     // Rear ride height
    uint8     m_brakePressure;            // Brake pressure (percentage)
    uint8     m_brakeBias;                // Brake bias (percentage)
    float     m_rearLeftTyrePressure;     // Rear left tyre pressure (PSI)
    float     m_rearRightTyrePressure;    // Rear right tyre pressure (PSI)
    float     m_frontLeftTyrePressure;    // Front left tyre pressure (PSI)
    float     m_frontRightTyrePressure;   // Front right tyre pressure (PSI)
    uint8     m_ballast;                  // Ballast
    float     m_fuelLoad;                 // Fuel load

    unsigned long get(char* buffer,unsigned long offset){
        memcpy(&this->m_frontWing,&buffer[offset],sizeof(this->m_frontWing));
        offset = offset + sizeof(this->m_frontWing);
        memcpy(&this->m_rearWing,&buffer[offset],sizeof(this->m_rearWing));
        offset = offset + sizeof(this->m_rearWing);
        memcpy(&this->m_onThrottle,&buffer[offset],sizeof(this->m_onThrottle));
        offset = offset + sizeof(this->m_onThrottle);
        memcpy(&this->m_offThrottle,&buffer[offset],sizeof(this->m_offThrottle));
        offset = offset + sizeof(this->m_offThrottle);
        memcpy(&this->m_frontCamber,&buffer[offset],sizeof(this->m_frontCamber));
        offset = offset + sizeof(this->m_frontCamber);
        memcpy(&this->m_rearCamber,&buffer[offset],sizeof(this->m_rearCamber));
        offset = offset + sizeof(this->m_rearCamber);
        memcpy(&this->m_frontToe,&buffer[offset],sizeof(this->m_frontToe));
        offset = offset + sizeof(this->m_frontToe);
        memcpy(&this->m_rearToe,&buffer[offset],sizeof(this->m_rearToe));
        offset = offset + sizeof(this->m_rearToe);
        memcpy(&this->m_frontSuspension,&buffer[offset],sizeof(this->m_frontSuspension));
        offset = offset + sizeof(this->m_frontSuspension);
        memcpy(&this->m_rearSuspension,&buffer[offset],sizeof(this->m_rearSuspension));
        offset = offset + sizeof(this->m_rearSuspension);
        memcpy(&this->m_frontAntiRollBar,&buffer[offset],sizeof(this->m_frontAntiRollBar));
        offset = offset + sizeof(this->m_frontAntiRollBar);
        memcpy(&this->m_rearAntiRollBar,&buffer[offset],sizeof(this->m_rearAntiRollBar));
        offset = offset + sizeof(this->m_rearAntiRollBar);
        memcpy(&this->m_frontSuspensionHeight,&buffer[offset],sizeof(this->m_frontSuspensionHeight));
        offset = offset + sizeof(this->m_frontSuspensionHeight);
        memcpy(&this->m_rearSuspensionHeight,&buffer[offset],sizeof(this->m_rearSuspensionHeight));
        offset = offset + sizeof(this->m_rearSuspensionHeight);
        memcpy(&this->m_brakePressure,&buffer[offset],sizeof(this->m_brakePressure));
        offset = offset + sizeof(this->m_brakePressure);
        memcpy(&this->m_brakeBias,&buffer[offset],sizeof(this->m_brakeBias));
        offset = offset + sizeof(this->m_brakeBias);
        memcpy(&this->m_rearLeftTyrePressure,&buffer[offset],sizeof(this->m_rearLeftTyrePressure));
        offset = offset + sizeof(this->m_rearLeftTyrePressure);
        memcpy(&this->m_rearRightTyrePressure,&buffer[offset],sizeof(this->m_rearRightTyrePressure));
        offset = offset + sizeof(this->m_rearRightTyrePressure);
        memcpy(&this->m_frontLeftTyrePressure,&buffer[offset],sizeof(this->m_frontLeftTyrePressure));
        offset = offset + sizeof(this->m_frontLeftTyrePressure);
        memcpy(&this->m_frontRightTyrePressure,&buffer[offset],sizeof(this->m_frontRightTyrePressure));
        offset = offset + sizeof(this->m_frontRightTyrePressure);
        memcpy(&this->m_ballast,&buffer[offset],sizeof(this->m_ballast));
        offset = offset + sizeof(this->m_ballast);
        memcpy(&this->m_fuelLoad,&buffer[offset],sizeof(this->m_fuelLoad));
        offset = offset + sizeof(this->m_fuelLoad);
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["frontWing"] = this->m_frontWing;
        root["rearWing"] = this->m_rearWing;
        root["onThrottle"] = this->m_onThrottle;
        root["offThrottle"] = this->m_offThrottle;
        root["frontCamber"] = this->m_frontCamber;
        root["rearCamber"] = this->m_rearCamber;
        root["frontToe"] = this->m_frontToe;
        root["rearToe"] = this->m_rearToe;
        root["frontSuspension"] = this->m_frontSuspension;
        root["rearSuspension"] = this->m_rearSuspension;
        root["frontAntiRollBar"] = this->m_frontAntiRollBar;
        root["rearAntiRollBar"] = this->m_rearAntiRollBar;
        root["frontSuspensionHeight"] = this->m_frontSuspensionHeight;
        root["rearSuspensionHeight"] = this->m_rearSuspensionHeight;
        root["brakePressure"] = this->m_brakePressure;
        root["brakeBias"] = this->m_brakeBias;
        root["rearLeftTyrePressure"] = this->m_rearLeftTyrePressure;
        root["rearRightTyrePressure"] = this->m_rearRightTyrePressure;
        root["frontLeftTyrePressure"] = this->m_frontLeftTyrePressure;
        root["frontRightTyrePressure"] = this->m_frontRightTyrePressure;
        root["ballast"] = this->m_ballast;
        root["fuelLoad"] = this->m_fuelLoad;

        return root;
    }

    void print(){
        std::wcout << " " << "CarSetupData {" << std::endl;
        std::wcout << "   " << "m_frontWing: " << this->m_frontWing << std::endl;
        std::wcout << "   " << "m_rearWing: " << this->m_rearWing << std::endl;
        std::wcout << "   " << "m_onThrottle: " << this->m_onThrottle << std::endl;
        std::wcout << "   " << "m_offThrottle: " << this->m_offThrottle << std::endl;
        std::wcout << "   " << "m_frontCamber: " << this->m_frontCamber << std::endl;
        std::wcout << "   " << "m_rearCamber: " << this->m_rearCamber << std::endl;
        std::wcout << "   " << "m_frontToe: " << this->m_frontToe << std::endl;
        std::wcout << "   " << "m_rearToe: " << this->m_rearToe << std::endl;
        std::wcout << "   " << "m_frontSuspension: " << this->m_frontSuspension << std::endl;
        std::wcout << "   " << "m_rearSuspension: " << this->m_rearSuspension << std::endl;
        std::wcout << "   " << "m_frontAntiRollBar: " << this->m_frontAntiRollBar << std::endl;
        std::wcout << "   " << "m_rearAntiRollBar: " << this->m_rearAntiRollBar << std::endl;
        std::wcout << "   " << "m_frontSuspensionHeight: " << this->m_frontSuspensionHeight << std::endl;
        std::wcout << "   " << "m_rearSuspensionHeight: " << this->m_rearSuspensionHeight << std::endl;
        std::wcout << "   " << "m_brakePressure: " << this->m_brakePressure << std::endl;
        std::wcout << "   " << "m_brakeBias: " << this->m_brakeBias << std::endl;
        std::wcout << "   " << "m_rearLeftTyrePressure: " << this->m_rearLeftTyrePressure << std::endl;
        std::wcout << "   " << "m_rearRightTyrePressure: " << this->m_rearRightTyrePressure << std::endl;
        std::wcout << "   " << "m_frontLeftTyrePressure: " << this->m_frontLeftTyrePressure << std::endl;
        std::wcout << "   " << "m_frontRightTyrePressure: " << this->m_frontRightTyrePressure << std::endl;
        std::wcout << "   " << "m_ballast: " << this->m_ballast << std::endl;
        std::wcout << "   " << "m_fuelLoad: " << this->m_fuelLoad << std::endl;
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        return "FrontWing,RearWing,OnThrottle,OffThrottle,FrontCamber,RearCamber,FrontToe,RearToe,FrontSuspension,RearSuspension,FrontAntiRollBar,RearAntiRollBar,FrontSuspensionHeight,RearSuspensionHeight,BrakePressure,BrakeBias,RearLeftTyrePressure,RearRightTyrePressure,FrontLeftTyrePressure,FrontRightTyrePressure,Ballast,FuelLoad";
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_frontWing));
        str.append(",");
        str.append(std::to_string(this->m_rearWing));
        str.append(",");
        str.append(std::to_string(this->m_onThrottle));
        str.append(",");
        str.append(std::to_string(this->m_offThrottle));
        str.append(",");
        str.append(std::to_string(this->m_frontCamber));
        str.append(",");
        str.append(std::to_string(this->m_rearCamber));
        str.append(",");
        str.append(std::to_string(this->m_frontToe));
        str.append(",");
        str.append(std::to_string(this->m_rearToe));
        str.append(",");
        str.append(std::to_string(this->m_frontSuspension));
        str.append(",");
        str.append(std::to_string(this->m_rearSuspension));
        str.append(",");
        str.append(std::to_string(this->m_frontAntiRollBar));
        str.append(",");
        str.append(std::to_string(this->m_rearAntiRollBar));
        str.append(",");
        str.append(std::to_string(this->m_frontSuspensionHeight));
        str.append(",");
        str.append(std::to_string(this->m_rearSuspensionHeight));
        str.append(",");
        str.append(std::to_string(this->m_brakePressure));
        str.append(",");
        str.append(std::to_string(this->m_brakeBias));
        str.append(",");
        str.append(std::to_string(this->m_rearLeftTyrePressure));
        str.append(",");
        str.append(std::to_string(this->m_rearRightTyrePressure));
        str.append(",");
        str.append(std::to_string(this->m_frontLeftTyrePressure));
        str.append(",");
        str.append(std::to_string(this->m_frontRightTyrePressure));
        str.append(",");
        str.append(std::to_string(this->m_ballast));
        str.append(",");
        str.append(std::to_string(this->m_fuelLoad));
        
        return str;
}

};

struct PacketCarSetupData
{
    PacketHeader    m_header;            // Header

    CarSetupData    m_carSetups[22];

    void get(char* buffer){
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++){
            offset = this->m_carSetups[i].get(buffer,offset);
        }
    }

    Json::Value toJSON(Json::Value root){
        for (int i = 0; i < 22; i++){
            root["SetupData"]["carSetupData"][i] = this->m_carSetups[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(SETUP_PATH,root["SetupData"], frame);

        return root;
    }

    void print(){
        std::wcout << " " << "PacketCarSetupData {" << std::endl;
        for (int i = 0; i < 22; i++){
            std::wcout << "   " << "m_carSetups[" << i << "]: " << std::endl;
            this->m_carSetups[i].print();
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",CarIndex,");
        s.append(this->m_carSetups->head_to_string());
        return s;
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < 22; i++){
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(this->m_carSetups[i].to_string(false));
            str.append("\n");
        }
        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Setup.csv";
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