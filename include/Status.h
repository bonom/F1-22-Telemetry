#ifndef __Status_H__
#define __Status_H__

#include "Costants.h"
#include "Header.h"

struct CarStatusData {
    uint8 m_tractionControl;  // 0 (off) - 2 (high)
    uint8 m_antiLockBrakes;   // 0 (off) - 1 (on)
    uint8 m_fuelMix;  // Fuel mix - 0 = lean,1 = standard,2 = rich,3 = max
    uint8 m_frontBrakeBias;    // Front brake bias (percentage)
    uint8 m_pitLimiterStatus;  // Pit limiter status - 0 = off,1 = on
    float m_fuelInTank;        // Current fuel mass
    float m_fuelCapacity;      // Fuel capacity
    float
        m_fuelRemainingLaps;  // Fuel remaining in terms of laps (value on MFD)
    uint16 m_maxRPM;          // Cars max RPM,point of rev limiter
    uint16 m_idleRPM;         // Cars idle RPM
    uint8 m_maxGears;         // Maximum number of gears
    uint8 m_drsAllowed;       // 0 = not allowed,1 = allowed,-1 = unknown

    // Added in Beta3:
    uint16 m_drsActivationDistance;  // 0 = DRS not available,non-zero - DRS
                                     // will be available in [X] metres

    uint8 m_actualTyreCompound;  // F1 Modern - 16 = C5,17 = C4,18 = C3,19 =
                                 // C2,20 = C1 7 = inter,8 = wet F1 Classic - 9
                                 // = dry,10 = wet F2 – 11 = super soft,12 =
                                 // soft,13 = medium,14 = hard 15 = wet
    uint8 m_visualTyreCompound;  // F1 visual (can be different from actual
                                 // compound) 16 = soft,17 = medium,18 = hard,7
                                 // = inter,8 = wet F1 Classic – same as above
                                 // F2 – same as above
    uint8 m_tyresAgeLaps;        // Age in laps of the current set of tyres
    int8 m_vehicleFiaFlags;      // -1 = invalid/unknown,0 = none,1 = green
                                 // 2 = blue,3 = yellow,4 = red
    float m_ersStoreEnergy;      // ERS energy store in Joules
    uint8 m_ersDeployMode;       // ERS deployment mode,0 = none,1 = medium
                                 // 2 = overtake,3 = hotlap
    float m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
    float m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
    float m_ersDeployedThisLap;       // ERS energy deployed this lap
    uint8 m_networkPaused;  // Whether the car is paused in a network game

    unsigned long get(char* buffer, unsigned long offset) {
        memcpy(&this->m_tractionControl, &buffer[offset],
               sizeof(this->m_tractionControl));
        offset = offset + sizeof(this->m_tractionControl);
        memcpy(&this->m_antiLockBrakes, &buffer[offset],
               sizeof(this->m_antiLockBrakes));
        offset = offset + sizeof(this->m_antiLockBrakes);
        memcpy(&this->m_fuelMix, &buffer[offset], sizeof(this->m_fuelMix));
        offset = offset + sizeof(this->m_fuelMix);
        memcpy(&this->m_frontBrakeBias, &buffer[offset],
               sizeof(this->m_frontBrakeBias));
        offset = offset + sizeof(this->m_frontBrakeBias);
        memcpy(&this->m_pitLimiterStatus, &buffer[offset],
               sizeof(this->m_pitLimiterStatus));
        offset = offset + sizeof(this->m_pitLimiterStatus);
        memcpy(&this->m_fuelInTank, &buffer[offset],
               sizeof(this->m_fuelInTank));
        offset = offset + sizeof(this->m_fuelInTank);
        memcpy(&this->m_fuelCapacity, &buffer[offset],
               sizeof(this->m_fuelCapacity));
        offset = offset + sizeof(this->m_fuelCapacity);
        memcpy(&this->m_fuelRemainingLaps, &buffer[offset],
               sizeof(this->m_fuelRemainingLaps));
        offset = offset + sizeof(this->m_fuelRemainingLaps);
        memcpy(&this->m_maxRPM, &buffer[offset], sizeof(this->m_maxRPM));
        offset = offset + sizeof(this->m_maxRPM);
        memcpy(&this->m_idleRPM, &buffer[offset], sizeof(this->m_idleRPM));
        offset = offset + sizeof(this->m_idleRPM);
        memcpy(&this->m_maxGears, &buffer[offset], sizeof(this->m_maxGears));
        offset = offset + sizeof(this->m_maxGears);
        memcpy(&this->m_drsAllowed, &buffer[offset],
               sizeof(this->m_drsAllowed));
        offset = offset + sizeof(this->m_drsAllowed);
        memcpy(&this->m_drsActivationDistance, &buffer[offset],
               sizeof(this->m_drsActivationDistance));
        offset = offset + sizeof(this->m_drsActivationDistance);

        memcpy(&this->m_actualTyreCompound, &buffer[offset],
               sizeof(this->m_actualTyreCompound));
        offset = offset + sizeof(this->m_actualTyreCompound);
        memcpy(&this->m_visualTyreCompound, &buffer[offset],
               sizeof(this->m_visualTyreCompound));
        offset = offset + sizeof(this->m_visualTyreCompound);
        memcpy(&this->m_tyresAgeLaps, &buffer[offset],
               sizeof(this->m_tyresAgeLaps));
        offset = offset + sizeof(this->m_tyresAgeLaps);

        memcpy(&this->m_vehicleFiaFlags, &buffer[offset],
               sizeof(this->m_vehicleFiaFlags));
        offset = offset + sizeof(this->m_vehicleFiaFlags);
        memcpy(&this->m_ersStoreEnergy, &buffer[offset],
               sizeof(this->m_ersStoreEnergy));
        offset = offset + sizeof(this->m_ersStoreEnergy);
        memcpy(&this->m_ersDeployMode, &buffer[offset],
               sizeof(this->m_ersDeployMode));
        offset = offset + sizeof(this->m_ersDeployMode);
        memcpy(&this->m_ersHarvestedThisLapMGUK, &buffer[offset],
               sizeof(this->m_ersHarvestedThisLapMGUK));
        offset = offset + sizeof(this->m_ersHarvestedThisLapMGUK);
        memcpy(&this->m_ersHarvestedThisLapMGUH, &buffer[offset],
               sizeof(this->m_ersHarvestedThisLapMGUH));
        offset = offset + sizeof(this->m_ersHarvestedThisLapMGUH);
        memcpy(&this->m_ersDeployedThisLap, &buffer[offset],
               sizeof(this->m_ersDeployedThisLap));
        offset = offset + sizeof(this->m_ersDeployedThisLap);

        memcpy(&this->m_networkPaused, &buffer[offset],
               sizeof(this->m_networkPaused));
        offset = offset + sizeof(this->m_networkPaused);
        return offset;
    }

    void print() {
        std::wcout << " "
                   << "CarStatusData {" << std::endl;
        std::wcout << "   "
                   << " m_tractionControl: " << this->m_tractionControl
                   << std::endl;
        std::wcout << "   "
                   << " m_antiLockBrakes: " << this->m_antiLockBrakes
                   << std::endl;
        std::wcout << "   "
                   << " m_fuelMix: " << this->m_fuelMix << std::endl;
        std::wcout << "   "
                   << " m_frontBrakeBias: " << this->m_frontBrakeBias
                   << std::endl;
        std::wcout << "   "
                   << " m_pitLimiterStatus: " << this->m_pitLimiterStatus
                   << std::endl;
        std::wcout << "   "
                   << " m_fuelInTank: " << this->m_fuelInTank << std::endl;
        std::wcout << "   "
                   << " m_fuelCapacity: " << this->m_fuelCapacity << std::endl;
        std::wcout << "   "
                   << " m_fuelRemainingLaps: " << this->m_fuelRemainingLaps
                   << std::endl;
        std::wcout << "   "
                   << " m_maxRPM: " << this->m_maxRPM << std::endl;
        std::wcout << "   "
                   << " m_idleRPM: " << this->m_idleRPM << std::endl;
        std::wcout << "   "
                   << " m_maxGears: " << this->m_maxGears << std::endl;
        std::wcout << "   "
                   << " m_drsAllowed: " << this->m_drsAllowed << std::endl;
        std::wcout << "   "
                   << " m_drsActivationDistance: "
                   << this->m_drsActivationDistance << std::endl;

        std::wcout << "   "
                   << " m_actualTyreCompound: "
                   << TyreCompound[this->m_actualTyreCompound] << std::endl;
        std::wcout << "   "
                   << " m_visualTyreCompound: "
                   << VisualTyreCompound[this->m_visualTyreCompound]
                   << std::endl;
        std::wcout << "   "
                   << " m_tyresAgeLaps: " << this->m_tyresAgeLaps << std::endl;

        std::wcout << "   "
                   << " m_vehicleFiaFlags: " << this->m_vehicleFiaFlags
                   << std::endl;
        std::wcout << "   "
                   << " m_ersStoreEnergy: " << this->m_ersStoreEnergy
                   << std::endl;
        std::wcout << "   "
                   << " m_ersDeployMode: " << this->m_ersDeployMode
                   << std::endl;
        std::wcout << "   "
                   << " m_ersHarvestedThisLapMGUK: "
                   << this->m_ersHarvestedThisLapMGUK << std::endl;
        std::wcout << "   "
                   << " m_ersHarvestedThisLapMGUH: "
                   << this->m_ersHarvestedThisLapMGUH << std::endl;
        std::wcout << "   "
                   << " m_ersDeployedThisLap: " << this->m_ersDeployedThisLap
                   << std::endl;

        std::wcout << "   "
                   << " m_networkPaused: " << this->m_networkPaused
                   << std::endl;

        std::wcout << " "
                   << "}" << std::endl;
    }

    Json::Value toJSON() {
        Json::Value root;

        root["tractionControl"] = this->m_tractionControl;
        root["antiLockBrakes"] = this->m_antiLockBrakes;
        root["fuelMix"] = this->m_fuelMix;
        root["frontBrakeBias"] = this->m_frontBrakeBias;
        root["pitLimiterStatus"] = this->m_pitLimiterStatus;
        root["fuelInTank"] = this->m_fuelInTank;
        root["fuelCapacity"] = this->m_fuelCapacity;
        root["fuelRemainingLaps"] = this->m_fuelRemainingLaps;
        root["maxRPM"] = this->m_maxRPM;
        root["idleRPM"] = this->m_idleRPM;
        root["maxGears"] = this->m_maxGears;
        root["drsAllowed"] = this->m_drsAllowed;
        root["drsActivationDistance"] = this->m_drsActivationDistance;
        root["actualTyreCompound"] = TyreCompound[this->m_actualTyreCompound];
        root["visualTyreCompound"] =
            VisualTyreCompound[this->m_visualTyreCompound];
        root["tyresAgeLaps"] = this->m_tyresAgeLaps;
        root["vehicleFiaFlags"] = this->m_vehicleFiaFlags;
        root["ersStoreEnergy"] = this->m_ersStoreEnergy;
        root["ersDeployMode"] = this->m_ersDeployMode;
        root["ersHarvestedThisLapMGUK"] = this->m_ersHarvestedThisLapMGUK;
        root["ersHarvestedThisLapMGUH"] = this->m_ersHarvestedThisLapMGUH;
        root["ersDeployedThisLap"] = this->m_ersDeployedThisLap;
        root["networkPaused"] = this->m_networkPaused;

        return root;
    }

    std::string head_to_string() {
        return "TractionControl,AntiLockBrakes,FuelMix,FrontBrakeBias,"
               "PitLimiterStatus,FuelInTank,FuelCapacity,FuelRemainingLaps,"
               "MaxRPM,IdleRPM,MaxGears,DRSAllowed,DRSActivationSystem,"
               "ActualTyreCompound,VisualTyreCompound,TyresAgeLaps,"
               "VehicleFIAFlags,ERSStoreEnergy,ERSDeployMode,"
               "ERSHarvestedThisLapMGUK,ERSHarvestedThisLapMGUH,"
               "ERSDeployedThisLap,NetworkPaused";
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }

        str.append(std::to_string(this->m_tractionControl));
        str.append(",");
        str.append(std::to_string(this->m_antiLockBrakes));
        str.append(",");
        str.append(std::to_string(this->m_fuelMix));
        str.append(",");
        str.append(std::to_string(this->m_frontBrakeBias));
        str.append(",");
        str.append(std::to_string(this->m_pitLimiterStatus));
        str.append(",");
        str.append(std::to_string(this->m_fuelInTank));
        str.append(",");
        str.append(std::to_string(this->m_fuelCapacity));
        str.append(",");
        str.append(std::to_string(this->m_fuelRemainingLaps));
        str.append(",");
        str.append(std::to_string(this->m_maxRPM));
        str.append(",");
        str.append(std::to_string(this->m_idleRPM));
        str.append(",");
        str.append(std::to_string(this->m_maxGears));
        str.append(",");
        str.append(std::to_string(this->m_drsAllowed));
        str.append(",");
        str.append(std::to_string(this->m_drsActivationDistance));
        str.append(",");
        str.append(std::to_string(this->m_actualTyreCompound));
        str.append(",");
        str.append(std::to_string(this->m_visualTyreCompound));
        str.append(",");
        str.append(std::to_string(this->m_tyresAgeLaps));
        str.append(",");
        str.append(std::to_string(this->m_vehicleFiaFlags));
        str.append(",");
        str.append(std::to_string(this->m_ersStoreEnergy));
        str.append(",");
        str.append(std::to_string(this->m_ersDeployMode));
        str.append(",");
        str.append(std::to_string(this->m_ersHarvestedThisLapMGUK));
        str.append(",");
        str.append(std::to_string(this->m_ersHarvestedThisLapMGUH));
        str.append(",");
        str.append(std::to_string(this->m_ersDeployedThisLap));
        str.append(",");
        str.append(std::to_string(this->m_networkPaused));

        return str;
    }
};

struct PacketCarStatusData {
    PacketHeader m_header;  // Header

    CarStatusData m_carStatusData[22];

    void get(char* buffer) {
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++) {
            offset = m_carStatusData[i].get(buffer, offset);
        }
    }

    Json::Value toJSON(Json::Value root) {
        for (int i = 0; i < 22; i++) {
            root["StatusData"]["carStatusData"][i] = this->m_carStatusData[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(STATUS_PATH, root["StatusData"], frame);

        return root;
    }

    void print() {
        std::wcout << " "
                   << "PacketCarStatusData {" << std::endl;
        for (int i = 0; i < 22; i++) {
            std::wcout << "   "
                       << " m_carStatusData[" << i << "]: " << std::endl;
            m_carStatusData[i].print();
        }
        std::wcout << " "
                   << "}" << std::endl;
    }

    // Add car Index
    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",CarIndex,");
        s.append(this->m_carStatusData->head_to_string());
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
            str.append(this->m_carStatusData[i].to_string(false));
            if (i != 21) {
                str.append("\n");
            }
        }
        return str;
    }

    void to_csv(const char* dirname) {
        std::string filename = std::string(dirname) + "/Status.csv";
        std::ofstream myfile;
        if (std::ifstream(filename)) {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(false) << std::endl;
        } else {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(true) << std::endl;
        }
        myfile.close();
    }
};

#endif