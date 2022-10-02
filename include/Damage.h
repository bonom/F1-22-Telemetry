#ifndef __Damage_h__
#define __Damage_h__

#include "Costants.h"
#include "Header.h"

struct CarDamageData {
    float m_tyresWear[4];          // Tyre wear (percentage)
    uint8 m_tyresDamage[4];        // Tyre damage (percentage)
    uint8 m_brakesDamage[4];       // Brakes damage (percentage)
    uint8 m_frontLeftWingDamage;   // Front left wing damage (percentage)
    uint8 m_frontRightWingDamage;  // Front right wing damage (percentage)
    uint8 m_rearWingDamage;        // Rear wing damage (percentage)
    uint8 m_floorDamage;           // Floor damage (percentage)
    uint8 m_diffuserDamage;        // Diffuser damage (percentage)
    uint8 m_sidepodDamage;         // Sidepod damage (percentage)
    uint8 m_drsFault;              // Indicator for DRS fault, 0 = OK, 1 = fault
    uint8 m_gearBoxDamage;         // Gear box damage (percentage)
    uint8 m_engineDamage;          // Engine damage (percentage)
    uint8 m_engineMGUHWear;        // Engine wear MGU-H (percentage)
    uint8 m_engineESWear;          // Engine wear ES (percentage)
    uint8 m_engineCEWear;          // Engine wear CE (percentage)
    uint8 m_engineICEWear;         // Engine wear ICE (percentage)
    uint8 m_engineMGUKWear;        // Engine wear MGU-K (percentage)
    uint8 m_engineTCWear;          // Engine wear TC (percentage)
    uint8 m_engineBlown;           // Engine blown, 0 = OK, 1 = fault
    uint8 m_engineSeized;          // Engine seized, 0 = OK, 1 = fault

    unsigned long get(char* buffer, unsigned long offset) {
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_tyresWear[i], &buffer[offset],
                   sizeof(this->m_tyresWear[i]));
            offset = offset + sizeof(this->m_tyresWear[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_tyresDamage[i], &buffer[offset],
                   sizeof(this->m_tyresDamage[i]));
            offset = offset + sizeof(this->m_tyresDamage[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_brakesDamage[i], &buffer[offset],
                   sizeof(this->m_brakesDamage[i]));
            offset = offset + sizeof(this->m_brakesDamage[i]);
        }
        memcpy(&this->m_frontLeftWingDamage, &buffer[offset],
               sizeof(this->m_frontLeftWingDamage));
        offset = offset + sizeof(this->m_frontLeftWingDamage);
        memcpy(&this->m_frontRightWingDamage, &buffer[offset],
               sizeof(this->m_frontRightWingDamage));
        offset = offset + sizeof(this->m_frontRightWingDamage);
        memcpy(&this->m_rearWingDamage, &buffer[offset],
               sizeof(this->m_rearWingDamage));
        offset = offset + sizeof(this->m_rearWingDamage);
        memcpy(&this->m_floorDamage, &buffer[offset],
               sizeof(this->m_floorDamage));
        offset = offset + sizeof(this->m_floorDamage);
        memcpy(&this->m_diffuserDamage, &buffer[offset],
               sizeof(this->m_diffuserDamage));
        offset = offset + sizeof(this->m_diffuserDamage);
        memcpy(&this->m_sidepodDamage, &buffer[offset],
               sizeof(this->m_sidepodDamage));
        offset = offset + sizeof(this->m_sidepodDamage);
        memcpy(&this->m_drsFault, &buffer[offset], sizeof(this->m_drsFault));
        offset = offset + sizeof(this->m_drsFault);
        memcpy(&this->m_gearBoxDamage, &buffer[offset],
               sizeof(this->m_gearBoxDamage));
        offset = offset + sizeof(this->m_gearBoxDamage);
        memcpy(&this->m_engineDamage, &buffer[offset],
               sizeof(this->m_engineDamage));
        offset = offset + sizeof(this->m_engineDamage);
        memcpy(&this->m_engineMGUHWear, &buffer[offset],
               sizeof(this->m_engineMGUHWear));
        offset = offset + sizeof(this->m_engineMGUHWear);
        memcpy(&this->m_engineESWear, &buffer[offset],
               sizeof(this->m_engineESWear));
        offset = offset + sizeof(this->m_engineESWear);
        memcpy(&this->m_engineCEWear, &buffer[offset],
               sizeof(this->m_engineCEWear));
        offset = offset + sizeof(this->m_engineCEWear);
        memcpy(&this->m_engineICEWear, &buffer[offset],
               sizeof(this->m_engineICEWear));
        offset = offset + sizeof(this->m_engineICEWear);
        memcpy(&this->m_engineMGUKWear, &buffer[offset],
               sizeof(this->m_engineMGUKWear));
        offset = offset + sizeof(this->m_engineMGUKWear);
        memcpy(&this->m_engineTCWear, &buffer[offset],
               sizeof(this->m_engineTCWear));
        offset = offset + sizeof(this->m_engineTCWear);
        memcpy(&this->m_engineBlown, &buffer[offset],
               sizeof(this->m_engineBlown));
        offset = offset + sizeof(this->m_engineBlown);
        memcpy(&this->m_engineSeized, &buffer[offset],
               sizeof(this->m_engineSeized));
        offset = offset + sizeof(this->m_engineSeized);

        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        for (int i = 0; i < 4; i++) {
            root["tyresWear"][TyrePosition[i]] = this->m_tyresWear[i];
        }
        for (int i = 0; i < 4; i++) {
            root["tyresDamage"][TyrePosition[i]] = this->m_tyresDamage[i];
        }
        for (int i = 0; i < 4; i++) {
            root["brakesDamage"][TyrePosition[i]] = this->m_brakesDamage[i];
        }
        root["frontLeftWingDamage"] = this->m_frontLeftWingDamage;
        root["frontRightWingDamage"] = this->m_frontRightWingDamage;
        root["rearWingDamage"] = this->m_rearWingDamage;
        root["floorDamage"] = this->m_floorDamage;
        root["diffuserDamage"] = this->m_diffuserDamage;
        root["sidepodDamage"] = this->m_sidepodDamage;
        root["drsFault"] = this->m_drsFault;
        root["gearBoxDamage"] = this->m_gearBoxDamage;
        root["engineDamage"] = this->m_engineDamage;
        root["engineMGUHWear"] = this->m_engineMGUHWear;
        root["engineESWear"] = this->m_engineESWear;
        root["engineCEWear"] = this->m_engineCEWear;
        root["engineICEWear"] = this->m_engineICEWear;
        root["engineMGUKWear"] = this->m_engineMGUKWear;
        root["engineTCWear"] = this->m_engineTCWear;
        root["engineBlown"] = this->m_engineBlown;
        root["engineSeized"] = this->m_engineSeized;

        return root;
    }

    void print() {
        std::wcout << " "
                   << "CarDamageData {" << std::endl;
        std::wcout << "   "
                   << " m_tyresWearRL: " << m_tyresWear[0] << std::endl;
        std::wcout << "   "
                   << " m_tyresWearRR: " << m_tyresWear[1] << std::endl;
        std::wcout << "   "
                   << " m_tyresWearFL: " << m_tyresWear[2] << std::endl;
        std::wcout << "   "
                   << " m_tyresWearFR: " << m_tyresWear[3] << std::endl;
        std::wcout << "   "
                   << " m_tyresDamageRL: " << m_tyresDamage[0] << std::endl;
        std::wcout << "   "
                   << " m_tyresDamageRR: " << m_tyresDamage[1] << std::endl;
        std::wcout << "   "
                   << " m_tyresDamageFL: " << m_tyresDamage[2] << std::endl;
        std::wcout << "   "
                   << " m_tyresDamageFR: " << m_tyresDamage[3] << std::endl;
        std::wcout << "   "
                   << " m_brakesDamageRL: " << m_brakesDamage[0] << std::endl;
        std::wcout << "   "
                   << " m_brakesDamageRR: " << m_brakesDamage[1] << std::endl;
        std::wcout << "   "
                   << " m_brakesDamageFL: " << m_brakesDamage[2] << std::endl;
        std::wcout << "   "
                   << " m_brakesDamageFR: " << m_brakesDamage[3] << std::endl;
        std::wcout << "   "
                   << " m_frontLeftWingDamage: " << m_frontLeftWingDamage
                   << std::endl;
        std::wcout << "   "
                   << " m_frontRightWingDamage: " << m_frontRightWingDamage
                   << std::endl;
        std::wcout << "   "
                   << " m_rearWingDamage: " << m_rearWingDamage << std::endl;
        std::wcout << "   "
                   << " m_floorDamage: " << m_floorDamage << std::endl;
        std::wcout << "   "
                   << " m_diffuserDamage: " << m_diffuserDamage << std::endl;
        std::wcout << "   "
                   << " m_sidepodDamage: " << m_sidepodDamage << std::endl;
        std::wcout << "   "
                   << " m_drsFault: " << m_drsFault << std::endl;
        std::wcout << "   "
                   << " m_gearBoxDamage: " << m_gearBoxDamage << std::endl;
        std::wcout << "   "
                   << " m_engineDamage: " << m_engineDamage << std::endl;
        std::wcout << "   "
                   << " m_engineMGUHWear: " << m_engineMGUHWear << std::endl;
        std::wcout << "   "
                   << " m_engineESWear: " << m_engineESWear << std::endl;
        std::wcout << "   "
                   << " m_engineCEWear: " << m_engineCEWear << std::endl;
        std::wcout << "   "
                   << " m_engineICEWear: " << m_engineICEWear << std::endl;
        std::wcout << "   "
                   << " m_engineMGUKWear: " << m_engineMGUKWear << std::endl;
        std::wcout << "   "
                   << " m_engineTCWear: " << m_engineTCWear << std::endl;
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        return "TyresWearRL,TyresWearRR,TyresWearFL,TyresWearFR,TyresDamageRL,"
               "TyresDamageRR,TyresDamageFL,TyresDamageFR,BrakesDamageRL,"
               "BrakesDamageRR,BrakesDamageFL,BrakesDamageFR,"
               "FrontLeftWingDamage,FrontRightWingDamage,RearWingDamage,"
               "FloorDamage,DiffuserDamage,SidepodDamage,DrsFault,"
               "GearBoxDamage,EngineDamage,EngineMGUHWear,EngineESWear,"
               "EngineCEWear,EngineICEWear,EngineMGUKWear,EngineTCWear";
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }

        str.append(std::to_string(this->m_tyresWear[0]));
        str.append(",");
        str.append(std::to_string(this->m_tyresWear[1]));
        str.append(",");
        str.append(std::to_string(this->m_tyresWear[2]));
        str.append(",");
        str.append(std::to_string(this->m_tyresWear[3]));
        str.append(",");
        str.append(std::to_string(this->m_tyresDamage[0]));
        str.append(",");
        str.append(std::to_string(this->m_tyresDamage[1]));
        str.append(",");
        str.append(std::to_string(this->m_tyresDamage[2]));
        str.append(",");
        str.append(std::to_string(this->m_tyresDamage[3]));
        str.append(",");
        str.append(std::to_string(this->m_brakesDamage[0]));
        str.append(",");
        str.append(std::to_string(this->m_brakesDamage[1]));
        str.append(",");
        str.append(std::to_string(this->m_brakesDamage[2]));
        str.append(",");
        str.append(std::to_string(this->m_brakesDamage[3]));
        str.append(",");
        str.append(std::to_string(this->m_frontLeftWingDamage));
        str.append(",");
        str.append(std::to_string(this->m_frontRightWingDamage));
        str.append(",");
        str.append(std::to_string(this->m_rearWingDamage));
        str.append(",");
        str.append(std::to_string(this->m_floorDamage));
        str.append(",");
        str.append(std::to_string(this->m_diffuserDamage));
        str.append(",");
        str.append(std::to_string(this->m_sidepodDamage));
        str.append(",");
        str.append(std::to_string(this->m_drsFault));
        str.append(",");
        str.append(std::to_string(this->m_gearBoxDamage));
        str.append(",");
        str.append(std::to_string(this->m_engineDamage));
        str.append(",");
        str.append(std::to_string(this->m_engineMGUHWear));
        str.append(",");
        str.append(std::to_string(this->m_engineESWear));
        str.append(",");
        str.append(std::to_string(this->m_engineCEWear));
        str.append(",");
        str.append(std::to_string(this->m_engineICEWear));
        str.append(",");
        str.append(std::to_string(this->m_engineMGUKWear));
        str.append(",");
        str.append(std::to_string(this->m_engineTCWear));

        return str;
    }
};

struct PacketCarDamageData {
    PacketHeader m_header;  // Header

    CarDamageData m_carDamageData[22];

    unsigned long get(char* buffer) {
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++) {
            offset = this->m_carDamageData[i].get(buffer, offset);
        }

        return offset;
    }

    Json::Value toJSON(Json::Value root){
        for (int i = 0; i < 22; i++) {
            root["DamageData"]["carDamageData"][i] = this->m_carDamageData[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(DAMAGE_PATH, root["DamageData"], frame);

        return root;
    }

    void print() {
        std::wcout << " "
                   << "PacketCar Damage {" << std::endl;
        for (int i = 0; i < 22; i++) {
            std::wcout << "   m_carDamageData[" << i << "]" << std::endl;
            this->m_carDamageData[i].print();
        }
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",CarIndex,");
        s.append(this->m_carDamageData->head_to_string());
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
            str.append(this->m_carDamageData[i].to_string(false));
            if (i != 21) {
                str.append("\n");
            }
        }

        return str;
    }

    void to_csv(const char* dirname) {
        std::string filename = std::string(dirname) + "/Damage.csv";
        std::ofstream myfile;
        if (std::ifstream(filename)) {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(false) << "\n";
        } else {
            myfile.open(filename, std::ios_base::app);
            myfile << this->to_string(true) << "\n";
        }
        myfile.close();
    }
};

#endif