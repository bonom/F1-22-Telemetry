#ifndef __Classification_h__
#define __Classification_h__

#include "Costants.h"
#include "Header.h"

struct FinalClassificationData{
    uint8     m_position;              // Finishing position
    uint8     m_numLaps;               // Number of laps completed
    uint8     m_gridPosition;          // Grid position of the car
    uint8     m_points;                // Number of points scored
    uint8     m_numPitStops;           // Number of pit stops made
    uint8     m_resultStatus;          // Result status - 0 = invalid,1 = inactive,2 = active
                                       // 3 = finished,4 = disqualified,5 = not classified
                                       // 6 = retired
    uint32     m_bestLapTimeInMS;           // Best lap time of the session in seconds
    double    m_totalRaceTime;         // Total race time in seconds without penalties
    uint8     m_penaltiesTime;         // Total penalties accumulated in seconds
    uint8     m_numPenalties;          // Number of penalties applied to this driver
    uint8     m_numTyreStints;         // Number of tyres stints up to maximum
    uint8     m_tyreStintsActual[8];   // Actual tyres used by this driver
    uint8     m_tyreStintsVisual[8];   // Visual tyres used by this driver
    uint8     m_tyreStintsEndLaps[8];  // The lap number stints end on

    unsigned long get(char * buffer,unsigned long offset){
        memcpy(&this->m_position,&buffer[offset],sizeof(this->m_position));
        offset = offset + sizeof(this->m_position);
        memcpy(&this->m_numLaps,&buffer[offset],sizeof(this->m_numLaps));
        offset = offset + sizeof(this->m_numLaps);
        memcpy(&this->m_gridPosition,&buffer[offset],sizeof(this->m_gridPosition));
        offset = offset + sizeof(this->m_gridPosition);
        memcpy(&this->m_points,&buffer[offset],sizeof(this->m_points));
        offset = offset + sizeof(this->m_points);
        memcpy(&this->m_numPitStops,&buffer[offset],sizeof(this->m_numPitStops));
        offset = offset + sizeof(this->m_numPitStops);
        memcpy(&this->m_resultStatus,&buffer[offset],sizeof(this->m_resultStatus));
        offset = offset + sizeof(this->m_resultStatus);
        memcpy(&this->m_bestLapTimeInMS,&buffer[offset],sizeof(this->m_bestLapTimeInMS));
        offset = offset + sizeof(this->m_bestLapTimeInMS);
        memcpy(&this->m_totalRaceTime,&buffer[offset],sizeof(this->m_totalRaceTime));
        offset = offset + sizeof(this->m_totalRaceTime);
        memcpy(&this->m_penaltiesTime,&buffer[offset],sizeof(this->m_penaltiesTime));
        offset = offset + sizeof(this->m_penaltiesTime);
        memcpy(&this->m_numPenalties,&buffer[offset],sizeof(this->m_numPenalties));
        offset = offset + sizeof(this->m_numPenalties);
        memcpy(&this->m_numTyreStints,&buffer[offset],sizeof(this->m_numTyreStints));
        offset = offset + sizeof(this->m_numTyreStints);
        for (int i = 0; i < 8; i++) {
            memcpy(&this->m_tyreStintsActual[i],&buffer[offset],sizeof(this->m_tyreStintsActual[i]));
            offset = offset + sizeof(this->m_tyreStintsActual[i]);
        }
        for (int i = 0; i < 8; i++) {
            memcpy(&this->m_tyreStintsVisual[i],&buffer[offset],sizeof(this->m_tyreStintsVisual[i]));
            offset = offset + sizeof(this->m_tyreStintsVisual[i]);
        }
        for (int i = 0; i < 8; i++) {
            memcpy(&this->m_tyreStintsEndLaps[i],&buffer[offset],sizeof(this->m_tyreStintsEndLaps[i]));
            offset = offset + sizeof(this->m_tyreStintsEndLaps[i]);
        }

        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["position"] = this->m_position;
        root["numLaps"] = this->m_numLaps;
        root["gridPosition"] = this->m_gridPosition;
        root["points"] = this->m_points;
        root["numPitStops"] = this->m_numPitStops;
        root["resultStatus"] = this->m_resultStatus;
        root["bestLapTimeInMS"] = this->m_bestLapTimeInMS;
        root["totalRaceTime"] = this->m_totalRaceTime;
        root["penaltiesTime"] = this->m_penaltiesTime;
        root["numPenalties"] = this->m_numPenalties;
        root["numTyreStints"] = this->m_numTyreStints;
        for (int i = 0; i < 8; i++) {
            root["tyreStintsActual"][i] = this->m_tyreStintsActual[i];
        }
        for (int i = 0; i < 8; i++) {
            root["tyreStintsVisual"][i] = this->m_tyreStintsVisual[i];
        }
        for (int i = 0; i < 8; i++) {
            root["tyreStintsEndLaps"][i] = this->m_tyreStintsEndLaps[i];
        }

        return root;
    }

    void print(){
        std::wcout << " " << "FinalClassificationData {" << std::endl;
        std::wcout << "   " << "    m_position: " << this->m_position << std::endl;
        std::wcout << "   " << "    m_numLaps: " << this->m_numLaps << std::endl;
        std::wcout << "   " << "    m_gridPosition: " << this->m_gridPosition << std::endl;
        std::wcout << "   " << "    m_points: " << this->m_points << std::endl;
        std::wcout << "   " << "    m_numPitStops: " << this->m_numPitStops << std::endl;
        std::wcout << "   " << "    m_resultStatus: " << this->m_resultStatus << std::endl;
        std::wcout << "   " << "    m_bestLapTime: " << this->m_bestLapTimeInMS << std::endl;
        std::wcout << "   " << "    m_totalRaceTime: " << this->m_totalRaceTime << std::endl;
        std::wcout << "   " << "    m_penaltiesTime: " << this->m_penaltiesTime << std::endl;
        std::wcout << "   " << "    m_numPenalties: " << this->m_numPenalties << std::endl;
        std::wcout << "   " << "    m_numTyreStints: " << this->m_numTyreStints << std::endl;
        for (int i = 0; i < 8; i++) {
            std::wcout << "   " << "    m_tyreStintsActual[" << i << "]: " << this->m_tyreStintsActual[i] << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::wcout << "   " << "    m_tyreStintsVisual[" << i << "]: " << this->m_tyreStintsVisual[i] << std::endl;
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append("Position,NumLaps,GridPosition,Points,NumPitStops,ResultStatus,BestLapTimeInMS,TotalRaceTime,PenaltiesTime,NumPenalties,NumTyreStints");
        for (int i = 0; i < this->m_numTyreStints; i++) {
            s.append(",TyreStintActual,TyreStintsVisual");
        }
        return s;
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_position));
        str.append(",");
        str.append(std::to_string(this->m_numLaps));
        str.append(",");
        str.append(std::to_string(this->m_gridPosition));
        str.append(",");
        str.append(std::to_string(this->m_points));
        str.append(",");
        str.append(std::to_string(this->m_numPitStops));
        str.append(",");
        str.append(std::to_string(this->m_resultStatus));
        str.append(",");
        str.append(std::to_string(this->m_bestLapTimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_totalRaceTime));
        str.append(",");
        str.append(std::to_string(this->m_penaltiesTime));
        str.append(",");
        str.append(std::to_string(this->m_numPenalties));
        str.append(",");
        str.append(std::to_string(this->m_numTyreStints));
        for (int i = 0; i < this->m_numTyreStints; i++) {
            str.append(",");
            str.append(std::to_string(this->m_tyreStintsActual[i]));
            str.append(",");
            str.append(std::to_string(this->m_tyreStintsVisual[i]));
        }
        
        return str;
    }

};

struct PacketFinalClassificationData{
    PacketHeader    m_header;                             // Header

    uint8                      m_numCars;                 // Number of cars in the final classification
    FinalClassificationData    m_classificationData[22];

    void get(char * buffer){
        unsigned long offset = this->m_header.get(buffer);
        memcpy(&this->m_numCars,&buffer[offset],sizeof(this->m_numCars));
        offset = offset + sizeof(this->m_numCars);
        for (int i = 0; i < 22; i++) {
            offset = this->m_classificationData[i].get(buffer,offset);
        }
    }

    Json::Value toJSON(Json::Value root){
        root["ClassificationData"]["numCars"] = this->m_numCars;
        for (int i = 0; i < 22; i++) {
            root["ClassificationData"]["carClassificationData"][i] = this->m_classificationData[i].toJSON();
        }

        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(CLASSIFICATION_PATH, root["ClassificationData"], frame);

        return root;
    }

    void print(){
        std::wcout << " " << "PacketFinalClassificationData {" << std::endl;
        std::wcout << "   " << "    m_numCars: " << this->m_numCars << std::endl;
        for (int i = 0; i < this->m_numCars; i++) {
            std::wcout << "   m_classificationData["<<i<<"]"<<std::endl;
            this->m_classificationData[i].print();
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",NumCars,CarIndex,");
        s.append(this->m_classificationData->head_to_string());
        return s;
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < this->m_numCars; i++) {
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(this->m_numCars));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(this->m_classificationData[i].to_string(false));
            str.append("\n");
        }

        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Classification.csv";
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