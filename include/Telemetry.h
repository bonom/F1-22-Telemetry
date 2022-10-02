#ifndef __Telemetry_h__
#define __Telemetry_h__

#include "Costants.h"
#include "Header.h"

struct CarTelemetryData {
    uint16 m_speed;    // Speed of car in kilometres per hour
    float m_throttle;  // Amount of throttle applied (0.0 to 1.0)
    float m_steer;  // Steering (-1.0 (full lock left) to 1.0 (full lock right))
    float m_brake;  // Amount of brake applied (0.0 to 1.0)
    uint8 m_clutch;                      // Amount of clutch applied (0 to 100)
    int8 m_gear;                         // Gear selected (1-8,N=0,R=-1)
    uint16 m_engineRPM;                  // Engine RPM
    uint8 m_drs;                         // 0 = off,1 = on
    uint8 m_revLightsPercent;            // Rev lights indicator (percentage)
    uint16 m_revLightsBitValue;          // Rev lights (bit 0 = leftmost LED, bit 14 = rightmost LED)
    uint16 m_brakesTemperature[4];       // Brakes temperature (celsius)
    uint8 m_tyresSurfaceTemperature[4];  // Tyres surface temperature (celsius)
    uint8 m_tyresInnerTemperature[4];    // Tyres inner temperature (celsius)
    uint16 m_engineTemperature;          // Engine temperature (celsius)
    float m_tyresPressure[4];            // Tyres pressure (PSI)
    uint8 m_surfaceType[4];              // Driving surface,see appendices

    unsigned long get(char *buffer, unsigned long offset) {
        memcpy(&this->m_speed, &buffer[offset], sizeof(this->m_speed));
        offset = offset + sizeof(this->m_speed);
        memcpy(&this->m_throttle, &buffer[offset], sizeof(this->m_throttle));
        offset = offset + sizeof(this->m_throttle);
        memcpy(&this->m_steer, &buffer[offset], sizeof(this->m_steer));
        offset = offset + sizeof(this->m_steer);
        memcpy(&this->m_brake, &buffer[offset], sizeof(this->m_brake));
        offset = offset + sizeof(this->m_brake);
        memcpy(&this->m_clutch, &buffer[offset], sizeof(this->m_clutch));
        offset = offset + sizeof(this->m_clutch);
        memcpy(&this->m_gear, &buffer[offset], sizeof(this->m_gear));
        offset = offset + sizeof(this->m_gear);
        memcpy(&this->m_engineRPM, &buffer[offset], sizeof(this->m_engineRPM));
        offset = offset + sizeof(this->m_engineRPM);
        memcpy(&this->m_drs, &buffer[offset], sizeof(this->m_drs));
        offset = offset + sizeof(this->m_drs);
        memcpy(&this->m_revLightsPercent, &buffer[offset],
               sizeof(this->m_revLightsPercent));
        offset = offset + sizeof(this->m_revLightsPercent);
        memcpy(&this->m_revLightsBitValue, &buffer[offset],
               sizeof(this->m_revLightsBitValue));
        offset = offset + sizeof(this->m_revLightsBitValue);
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_brakesTemperature[i], &buffer[offset],
                   sizeof(this->m_brakesTemperature[i]));
            offset = offset + sizeof(this->m_brakesTemperature[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_tyresSurfaceTemperature[i], &buffer[offset],
                   sizeof(this->m_tyresSurfaceTemperature[i]));
            offset = offset + sizeof(this->m_tyresSurfaceTemperature[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_tyresInnerTemperature[i], &buffer[offset],
                   sizeof(this->m_tyresInnerTemperature[i]));
            offset = offset + sizeof(this->m_tyresInnerTemperature[i]);
        }
        memcpy(&this->m_engineTemperature, &buffer[offset],
               sizeof(this->m_engineTemperature));
        offset = offset + sizeof(this->m_engineTemperature);
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_tyresPressure[i], &buffer[offset],
                   sizeof(this->m_tyresPressure[i]));
            offset = offset + sizeof(this->m_tyresPressure[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_surfaceType[i], &buffer[offset],
                   sizeof(this->m_surfaceType[i]));
            offset = offset + sizeof(this->m_surfaceType[i]);
        }
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["speed"] = this->m_speed;
        root["throttle"] = this->m_throttle;
        root["steer"] = this->m_steer;
        root["brake"] = this->m_brake;
        root["clutch"] = this->m_clutch;
        root["gear"] = this->m_gear;
        root["engineRPM"] = this->m_engineRPM;
        root["drs"] = this->m_drs;
        root["revLightsPercent"] = this->m_revLightsPercent;
        root["revLightsBitValue"] = this->m_revLightsBitValue;
        for (int i = 0; i < 4; i++) {
            root["brakesTemperature"][TyrePosition[i]] = this->m_brakesTemperature[i];
        }
        for (int i = 0; i < 4; i++) {
            root["tyresSurfaceTemperature"][TyrePosition[i]] = this->m_tyresSurfaceTemperature[i];
        }
        for (int i = 0; i < 4; i++) {
            root["tyresInnerTemperature"][TyrePosition[i]] = this->m_tyresInnerTemperature[i];
        }
        root["engineTemperature"] = this->m_engineTemperature;
        for (int i = 0; i < 4; i++) {
            root["tyresPressure"][TyrePosition[i]] = this->m_tyresPressure[i];
        }
        for (int i = 0; i < 4; i++) {
            root["surfaceType"][TyrePosition[i]] = this->m_surfaceType[i];
        }
        
        return root;
    }

    void print() {
        std::wcout << " "
                   << "CarTelemetryData {" << std::endl;
        std::wcout << "   "
                   << " m_speed: " << this->m_speed << std::endl;
        std::wcout << "   "
                   << " m_throttle: " << this->m_throttle << std::endl;
        std::wcout << "   "
                   << " m_steer: " << this->m_steer << std::endl;
        std::wcout << "   "
                   << " m_brake: " << this->m_brake << std::endl;
        std::wcout << "   "
                   << " m_clutch: " << this->m_clutch << std::endl;
        std::wcout << "   "
                   << " m_gear: " << this->m_gear << std::endl;
        std::wcout << "   "
                   << " m_engineRPM: " << this->m_engineRPM << std::endl;
        std::wcout << "   "
                   << " m_drs: " << this->m_drs << std::endl;
        std::wcout << "   "
                   << " m_revLightsPercent: " << this->m_revLightsPercent
                   << std::endl;
        std::wcout << "   "
                     << " m_revLightsBitValue: " << this->m_revLightsBitValue
                     << std::endl;
        for (int i = 0; i < 4; i++) {
            std::wcout << "   "
                       << " m_brakesTemperature[" << i
                       << "]: " << this->m_brakesTemperature[i] << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            std::wcout << "   "
                       << " m_tyresSurfaceTemperature[" << i
                       << "]: " << this->m_tyresSurfaceTemperature[i]
                       << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            std::wcout << "   "
                       << " m_tyresInnerTemperature[" << i
                       << "]: " << this->m_tyresInnerTemperature[i]
                       << std::endl;
        }
        std::wcout << "   "
                   << " m_engineTemperature: " << this->m_engineTemperature
                   << std::endl;
        for (int i = 0; i < 4; i++) {
            std::wcout << "   "
                       << " m_tyresPressure[" << i
                       << "]: " << this->m_tyresPressure[i] << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            std::wcout << "   "
                       << " m_surfaceType[" << i
                       << "]: " << Surfaces[this->m_surfaceType[i]]
                       << std::endl;
        }
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        return "Speed,Throttle,Steer,Brake,Clutch,Gear,EngineRPM,DRS,"
               "RevLightsPercent,RevLightsBitValue,"
               "RLBrakeTemperature,RRBrakeTemperature,FLBrakeTemperature,FRBrakeTemperature,"
               "RLTyreSurfaceTemperature,RRTyreSurfaceTemperature,FLTyreSurfaceTemperature,FRTyreSurfaceTemperature,"
               "RLTyreInnerTemperature,RRTyreInnerTemperature,FLTyreInnerTemperature,FRTyreInnerTemperature,"
               "EngineTemperature,"
               "RLTyrePressure,RRTyrePressure,FLTyrePressure,FRTyrePressure,"
               "RLSurfaceType,RRSurfaceType,FLSurfaceType,FRSurfaceType";
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_speed));
        str.append(",");
        str.append(std::to_string(this->m_throttle));
        str.append(",");
        str.append(std::to_string(this->m_steer));
        str.append(",");
        str.append(std::to_string(this->m_brake));
        str.append(",");
        str.append(std::to_string(this->m_clutch));
        str.append(",");
        str.append(std::to_string(this->m_gear));
        str.append(",");
        str.append(std::to_string(this->m_engineRPM));
        str.append(",");
        str.append(std::to_string(this->m_drs));
        str.append(",");
        str.append(std::to_string(this->m_revLightsPercent));
        str.append(",");
        str.append(std::to_string(this->m_revLightsBitValue));
        str.append(",");
        for (int i = 0; i < 4; i++){
            str.append(std::to_string(this->m_brakesTemperature[i]));
            str.append(",");
        }
        for (int i = 0; i < 4; i++) {
            str.append(std::to_string(this->m_tyresSurfaceTemperature[i]));
            str.append(",");
        }
        for (int i = 0; i < 4; i++){
            str.append(std::to_string(this->m_tyresInnerTemperature[i]));
            str.append(",");
        }
        str.append(std::to_string(this->m_engineTemperature));
        str.append(",");
        for (int i = 0; i < 4; i++){
            str.append(std::to_string(this->m_tyresPressure[i]));
            str.append(",");
        }
        for (int i = 0; i < 4; i++){
            str.append(std::to_string(this->m_surfaceType[i]));
            str.append(",");
        }
        return str;
    }
};

struct PacketCarTelemetryData {
    PacketHeader m_header;  // Header

    CarTelemetryData m_carTelemetryData[22];

    uint8 m_mfdPanelIndex;  // Index of MFD panel open - 255 = MFD closed
                            // Single player,race – 0 = Car setup,1 = Pits
                            // 2 = Damage,3 =  Engine,4 = Temperatures
                            // May vary depending on game mode
    uint8 m_mfdPanelIndexSecondaryPlayer;  // See above
    int8 m_suggestedGear;  // Suggested gear for the player (1-8)
                           // 0 if no gear suggested

    void get(char *buffer) {
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++) {
            offset = this->m_carTelemetryData[i].get(buffer, offset);
        }
        memcpy(&this->m_mfdPanelIndex, &buffer[offset],
               sizeof(this->m_mfdPanelIndex));
        offset = offset + sizeof(this->m_mfdPanelIndex);
        memcpy(&this->m_mfdPanelIndexSecondaryPlayer, &buffer[offset],
               sizeof(this->m_mfdPanelIndexSecondaryPlayer));
        offset = offset + sizeof(this->m_mfdPanelIndexSecondaryPlayer);
        memcpy(&this->m_suggestedGear, &buffer[offset],
               sizeof(this->m_suggestedGear));
        offset = offset + sizeof(this->m_suggestedGear);
    }

    Json::Value toJSON(Json::Value root){
        for (int i = 0; i < 22; i++) {
            root["TelemetryData"]["carTelemetryData"][i] = this->m_carTelemetryData[i].toJSON();
        }
        root["TelemetryData"]["mfdPanelIndex"] = this->m_mfdPanelIndex;
        root["TelemetryData"]["mfdPanelIndexSecondaryPlayer"] = this->m_mfdPanelIndexSecondaryPlayer;
        root["TelemetryData"]["suggestedGear"] = this->m_suggestedGear;
        
        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(TELEMETRY_PATH, root["TelemetryData"], frame);

        return root;
    }

    void print() {
        std::wcout << " "
                   << "PacketCarTelemetryData {" << std::endl;
        for (int i = 0; i < 22; i++) {
            std::wcout << "   "
                       << " m_carTelemetryData[" << i << "]: " << std::endl;
            this->m_carTelemetryData[i].print();
        }
        std::wcout << "   "
                   << " m_mfdPanelIndex: " << MFD[this->m_mfdPanelIndex]
                   << std::endl;
        std::wcout << "   "
                   << " m_mfdPanelIndexSecondaryPlayer: "
                   << MFD[this->m_mfdPanelIndexSecondaryPlayer] << std::endl;
        std::wcout << "   "
                   << " m_suggestedGear: " << this->m_suggestedGear
                   << std::endl;
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",CarIndex,");
        s.append(this->m_carTelemetryData->head_to_string());
        s.append(",");
        s.append("MFD,MFDSecondaryPlayer,SuggestedGear");

        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < 22; i++) {
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(this->m_carTelemetryData[i].to_string(false));
            //str.append(","); //Already append in m_carTelemetryData->to_string()
            str.append(std::to_string(this->m_mfdPanelIndex));
            str.append(",");
            str.append(std::to_string(this->m_mfdPanelIndexSecondaryPlayer));
            str.append(",");
            str.append(std::to_string(this->m_suggestedGear));
            str.append("\n");
        }

        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Telemetry.csv";
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