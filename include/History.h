#ifndef __History_h__
#define __History_h__

#include "Costants.h"
#include "Header.h"

struct LapHistoryData {
    uint32 m_lapTimeInMS;      // Lap time in milliseconds
    uint16 m_sector1TimeInMS;  // Sector 1 time in milliseconds
    uint16 m_sector2TimeInMS;  // Sector 2 time in milliseconds
    uint16 m_sector3TimeInMS;  // Sector 3 time in milliseconds
    uint8 m_lapValidBitFlags;  // 0x01 bit set-lap valid,      0x02 bit
                               // set-sector 1 valid 0x04 bit set-sector 2
                               // valid, 0x08 bit set-sector 3 valid

    unsigned long get(char* buffer, unsigned long offset) {
        memcpy(&this->m_lapTimeInMS, &buffer[offset],
               sizeof(this->m_lapTimeInMS));
        offset += sizeof(this->m_lapTimeInMS);
        memcpy(&this->m_sector1TimeInMS, &buffer[offset],
               sizeof(this->m_sector1TimeInMS));
        offset += sizeof(this->m_sector1TimeInMS);
        memcpy(&this->m_sector2TimeInMS, &buffer[offset],
               sizeof(this->m_sector2TimeInMS));
        offset += sizeof(this->m_sector2TimeInMS);
        memcpy(&this->m_sector3TimeInMS, &buffer[offset],
               sizeof(this->m_sector3TimeInMS));
        offset += sizeof(this->m_sector3TimeInMS);
        memcpy(&this->m_lapValidBitFlags, &buffer[offset],
               sizeof(this->m_lapValidBitFlags));
        offset += sizeof(this->m_lapValidBitFlags);

        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["lapTimeInMS"] = this->m_lapTimeInMS;
        root["sector1TimeInMS"] = this->m_sector1TimeInMS;
        root["sector2TimeInMS"] = this->m_sector2TimeInMS;
        root["sector3TimeInMS"] = this->m_sector3TimeInMS;
        root["lapValidBitFlags"] = this->m_lapValidBitFlags;
        
        return root;
    }

    void print(int index) {
        std::wcout << "   LapHistoryData[" << index << "]{ " << std::endl;
        std::wcout << "      m_lapTimeInMS: " << this->m_lapTimeInMS
                   << std::endl;
        std::wcout << "      m_sector1TimeInMS: " << this->m_sector1TimeInMS
                   << std::endl;
        std::wcout << "      m_sector2TimeInMS: " << this->m_sector2TimeInMS
                   << std::endl;
        std::wcout << "      m_sector3TimeInMS: " << this->m_sector3TimeInMS
                   << std::endl;
        std::wcout << "      m_lapValidBitFlags: " << this->m_lapValidBitFlags
                   << " Casted in " << ((m_lapValidBitFlags >> 2) & 1)
                   << std::endl;
        std::wcout << "   }" << std::endl;
    }

    std::string head_to_string(int index) {
        std::string str;
        str.append("lapTimeInMS[");
        str.append(std::to_string(index));
        str.append("],sector1TimeInMS[");
        str.append(std::to_string(index));
        str.append("],sector2TimeInMS[");
        str.append(std::to_string(index));
        str.append("],sector3TimeInMS[");
        str.append(std::to_string(index));
        str.append("],lapValidBitFlags[");
        str.append(std::to_string(index));
        str.append("]");

        return str;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(head_to_string(0));
            str.append("\n");
        }
        str.append(std::to_string(this->m_lapTimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_sector1TimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_sector2TimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_sector3TimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_lapValidBitFlags));

        return str;
    }
};

struct TyreStintHistoryData {
    uint8 m_endLap;  // Lap the tyre usage ends on (255 of current tyre)
    uint8 m_tyreActualCompound;  // Actual tyres used by this driver
    uint8 m_tyreVisualCompound;  // Visual tyres used by this driver

    unsigned long get(char* buffer, unsigned long offset) {
        memcpy(&this->m_endLap, &buffer[offset], sizeof(this->m_endLap));
        offset += sizeof(this->m_endLap);
        memcpy(&this->m_tyreActualCompound, &buffer[offset],
               sizeof(this->m_tyreActualCompound));
        offset += sizeof(this->m_tyreActualCompound);
        memcpy(&this->m_tyreVisualCompound, &buffer[offset],
               sizeof(this->m_tyreVisualCompound));
        offset += sizeof(this->m_tyreVisualCompound);
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["endLap"] = this->m_endLap;
        root["tyreActualCompound"] = this->m_tyreActualCompound;
        root["tyreVisualCompound"] = this->m_tyreVisualCompound;
        
        return root;
    }

    void print(int index) {
        std::wcout << "   TyreStintHistoryData[" << index << "]{ " << std::endl;
        std::wcout << "      m_endLap: " << this->m_endLap << std::endl;
        std::wcout << "      m_tyreActualCompound: "
                   << this->m_tyreActualCompound << std::endl;
        std::wcout << "      m_tyreVisualCompound: "
                   << this->m_tyreVisualCompound << std::endl;
        std::wcout << "   }" << std::endl;
    }

    std::string head_to_string(int index) {
        std::string str;
        str.append("endLap[");
        str.append(std::to_string(index));
        str.append("],tyreActualCompound[");
        str.append(std::to_string(index));
        str.append("],tyreVisualCompound[");
        str.append(std::to_string(index));
        str.append("]");
        
        return str;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(head_to_string(0));
            str.append("\n");
        }
        str.append(std::to_string(this->m_endLap));
        str.append(",");
        str.append(std::to_string(this->m_tyreActualCompound));
        str.append(",");
        str.append(std::to_string(this->m_tyreVisualCompound));

        return str;
    }
};

struct PacketSessionHistoryData {
    PacketHeader m_header;  // Header

    uint8 m_carIdx;   // Index of the car this lap data relates to
    uint8 m_numLaps;  // Num laps in the data (including current partial lap)
    uint8 m_numTyreStints;  // Number of tyre stints in the data

    uint8 m_bestLapTimeLapNum;  // Lap the best lap time was achieved on
    uint8 m_bestSector1LapNum;  // Lap the best Sector 1 time was achieved on
    uint8 m_bestSector2LapNum;  // Lap the best Sector 2 time was achieved on
    uint8 m_bestSector3LapNum;  // Lap the best Sector 3 time was achieved on

    LapHistoryData m_lapHistoryData[100];  // 100 laps of data max
    TyreStintHistoryData m_tyreStintsHistoryData[8];

    void get(char* buffer) {
        unsigned long offset = this->m_header.get(buffer);
        memcpy(&this->m_carIdx, &buffer[offset], sizeof(this->m_carIdx));
        offset += sizeof(this->m_carIdx);
        memcpy(&this->m_numLaps, &buffer[offset], sizeof(this->m_numLaps));
        offset += sizeof(this->m_numLaps);
        memcpy(&this->m_numTyreStints, &buffer[offset],
               sizeof(this->m_numTyreStints));
        offset += sizeof(this->m_numTyreStints);
        memcpy(&this->m_bestLapTimeLapNum, &buffer[offset],
               sizeof(this->m_bestLapTimeLapNum));
        offset += sizeof(this->m_bestLapTimeLapNum);
        memcpy(&this->m_bestSector1LapNum, &buffer[offset],
               sizeof(this->m_bestSector1LapNum));
        offset += sizeof(this->m_bestSector1LapNum);
        memcpy(&this->m_bestSector2LapNum, &buffer[offset],
               sizeof(this->m_bestSector2LapNum));
        offset += sizeof(this->m_bestSector2LapNum);
        memcpy(&this->m_bestSector3LapNum, &buffer[offset],
               sizeof(this->m_bestSector3LapNum));
        offset += sizeof(this->m_bestSector3LapNum);
        for (int i = 0; i < 100; i++) {//m_numLaps
            offset = this->m_lapHistoryData[i].get(buffer, offset);
        }
        for (int i = 0; i < 8; i++) {
            offset = this->m_tyreStintsHistoryData[i].get(buffer, offset);// m_numTyreStints
        }
    }

    Json::Value toJSON(Json::Value root){
        root["HistoryData"]["carIdx"] = this->m_carIdx;
        root["HistoryData"]["numLaps"] = this->m_numLaps;
        root["HistoryData"]["numTyreStints"] = this->m_numTyreStints;
        root["HistoryData"]["bestLapTimeLapNum"] = this->m_bestLapTimeLapNum;
        root["HistoryData"]["bestSector1LapNum"] = this->m_bestSector1LapNum;
        root["HistoryData"]["bestSector2LapNum"] = this->m_bestSector2LapNum;
        root["HistoryData"]["bestSector3LapNum"] = this->m_bestSector3LapNum;
        
        for (int i = 0; i < this->m_numLaps; i++) {
            root["HistoryData"]["lapHistoryData"][i]=this->m_lapHistoryData[i].toJSON();
        }
        
        for (int i = 0; i < this->m_numTyreStints; i++) {
            root["HistoryData"]["tyreStintsHistoryData"][i]=this->m_tyreStintsHistoryData[i].toJSON();
        }
        
        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(HISTORY_PATH, root["HistoryData"], frame);

        return root;
    }

    void print() {
        std::wcout << "   PacketSessionHistoryData{ " << std::endl;
        std::wcout << "      m_carIdx: " << this->m_carIdx << std::endl;
        std::wcout << "      m_numLaps: " << this->m_numLaps << std::endl;
        std::wcout << "      m_numTyreStints: " << this->m_numTyreStints
                   << std::endl;
        std::wcout << "      m_bestLapTimeLapNum: " << this->m_bestLapTimeLapNum
                   << std::endl;
        std::wcout << "      m_bestSector1LapNum: " << this->m_bestSector1LapNum
                   << std::endl;
        std::wcout << "      m_bestSector2LapNum: " << this->m_bestSector2LapNum
                   << std::endl;
        std::wcout << "      m_bestSector3LapNum: " << this->m_bestSector3LapNum
                   << std::endl;
        for (int i = 0; i < this->m_numLaps; i++) {
            this->m_lapHistoryData[i].print(i);
        }
        for (int i = 0; i < this->m_numTyreStints; i++) {
            this->m_tyreStintsHistoryData[i].print(i);
        }
        std::wcout << "   }" << std::endl;
    }

    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(
            ",CarIndex,NumLaps,NumTyreStints,BestLapTimeLapNum,"
            "BestSector1LapNum,BestSector2LapNum,BestSector3LapNum");
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        std::string header;
        if (flag) {
            header.append(this->head_to_string());
        }
        str.append(this->m_header.to_string(false));
        str.append(",");
        str.append(std::to_string(this->m_carIdx));
        str.append(",");
        str.append(std::to_string(this->m_numLaps));
        str.append(",");
        str.append(std::to_string(this->m_numTyreStints));
        str.append(",");
        str.append(std::to_string(this->m_bestLapTimeLapNum));
        str.append(",");
        str.append(std::to_string(this->m_bestSector1LapNum));
        str.append(",");
        str.append(std::to_string(this->m_bestSector2LapNum));
        str.append(",");
        str.append(std::to_string(this->m_bestSector3LapNum));
        str.append(",");
        for (int i = 0; i < 100; i++) {
            if (flag) {
                header.append(",");
                header.append(this->m_lapHistoryData[i].head_to_string(i));
            }
            if (i < this->m_numLaps) {
                str.append(this->m_lapHistoryData[i].to_string(false));
                str.append(",");
            } else {
                str.append("-,-,-,-,-,");
            }
        }
        for (int i = 0; i < 8; i++) {
            if (flag) {
                header.append(",");
                header.append(
                    this->m_tyreStintsHistoryData[i].head_to_string(i));
            }
            if (i < this->m_numTyreStints) {
                str.append(this->m_tyreStintsHistoryData[i].to_string(false));
            } else {
                str.append("-,-,-");
            }
            if (i < 7) {
                str.append(",");
            }
        }
        str.append("\n");
        if (flag) {
            header.append("\n");
            header.append(str);
            return header;
        }
        return str;
    }

    void to_csv(const char* dirname) {
        std::string filename = std::string(dirname) + "/History.csv";
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