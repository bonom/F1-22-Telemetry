#ifndef __Lap_h__
#define __Lap_h__

#include "Costants.h"
#include "Header.h"


struct LapData
{
    uint32   m_lastLapTimeInMS;	       	 // Last lap time in milliseconds
    uint32   m_currentLapTimeInMS; 	 // Current time around the lap in milliseconds
    uint16   m_sector1TimeInMS;           // Sector 1 time in milliseconds
    uint16   m_sector2TimeInMS;           // Sector 2 time in milliseconds
    float    m_lapDistance;		 // Distance vehicle is around current lap in metres – could
					 // be negative if line hasn’t been crossed yet
    float    m_totalDistance;		 // Total distance travelled in session in metres – could
					 // be negative if line hasn’t been crossed yet
    float    m_safetyCarDelta;            // Delta in seconds for safety car
    uint8    m_carPosition;   	         // Car race position
    uint8    m_currentLapNum;		 // Current lap number
    uint8    m_pitStatus;            	 // 0 = none, 1 = pitting, 2 = in pit area
    uint8    m_numPitStops;            	 // Number of pit stops taken in this race
    uint8    m_sector;               	 // 0 = sector1, 1 = sector2, 2 = sector3
    uint8    m_currentLapInvalid;    	 // Current lap invalid - 0 = valid, 1 = invalid
    uint8    m_penalties;            	 // Accumulated time penalties in seconds to be added
    uint8    m_warnings;                  // Accumulated number of warnings issued
    uint8    m_numUnservedDriveThroughPens;  // Num drive through pens left to serve
    uint8    m_numUnservedStopGoPens;        // Num stop go pens left to serve
    uint8    m_gridPosition;         	 // Grid position the vehicle started the race in
    uint8    m_driverStatus;         	 // Status of driver - 0 = in garage, 1 = flying lap
                                          // 2 = in lap, 3 = out lap, 4 = on track
    uint8    m_resultStatus;              // Result status - 0 = invalid, 1 = inactive, 2 = active
                                          // 3 = finished, 4 = didnotfinish, 5 = disqualified
                                          // 6 = not classified, 7 = retired
    uint8    m_pitLaneTimerActive;     	 // Pit lane timing, 0 = inactive, 1 = active
    uint16   m_pitLaneTimeInLaneInMS;   	 // If active, the current time spent in the pit lane in ms
    uint16   m_pitStopTimerInMS;        	 // Time of the actual pit stop in ms
    uint8    m_pitStopShouldServePen;   	 // Whether the car should serve a penalty at this stop


    unsigned long get(char* buffer,unsigned long offset){
        memcpy(&this->m_lastLapTimeInMS, &buffer[offset], sizeof(this->m_lastLapTimeInMS));
        offset += sizeof(this->m_lastLapTimeInMS);
        memcpy(&this->m_currentLapTimeInMS, &buffer[offset], sizeof(this->m_currentLapTimeInMS));
        offset += sizeof(this->m_currentLapTimeInMS);
        memcpy(&this->m_sector1TimeInMS, &buffer[offset], sizeof(this->m_sector1TimeInMS));
        offset += sizeof(this->m_sector1TimeInMS);
        memcpy(&this->m_sector2TimeInMS, &buffer[offset], sizeof(this->m_sector2TimeInMS));
        offset += sizeof(this->m_sector2TimeInMS);
        memcpy(&this->m_lapDistance, &buffer[offset], sizeof(this->m_lapDistance));
        offset += sizeof(this->m_lapDistance);
        memcpy(&this->m_totalDistance, &buffer[offset], sizeof(this->m_totalDistance));
        offset += sizeof(this->m_totalDistance);
        memcpy(&this->m_safetyCarDelta, &buffer[offset], sizeof(this->m_safetyCarDelta));
        offset += sizeof(this->m_safetyCarDelta);
        memcpy(&this->m_carPosition, &buffer[offset], sizeof(this->m_carPosition));
        offset += sizeof(this->m_carPosition);
        memcpy(&this->m_currentLapNum, &buffer[offset], sizeof(this->m_currentLapNum));
        offset += sizeof(this->m_currentLapNum);
        memcpy(&this->m_pitStatus, &buffer[offset], sizeof(this->m_pitStatus));
        offset += sizeof(this->m_pitStatus);
        memcpy(&this->m_numPitStops, &buffer[offset], sizeof(this->m_numPitStops));
        offset += sizeof(this->m_numPitStops);
        memcpy(&this->m_sector, &buffer[offset], sizeof(this->m_sector));
        offset += sizeof(this->m_sector);
        memcpy(&this->m_currentLapInvalid, &buffer[offset], sizeof(this->m_currentLapInvalid));
        offset += sizeof(this->m_currentLapInvalid);
        memcpy(&this->m_penalties, &buffer[offset], sizeof(this->m_penalties));
        offset += sizeof(this->m_penalties);
        memcpy(&this->m_warnings, &buffer[offset], sizeof(this->m_warnings));
        offset += sizeof(this->m_warnings);
        memcpy(&this->m_numUnservedDriveThroughPens, &buffer[offset], sizeof(this->m_numUnservedDriveThroughPens));
        offset += sizeof(this->m_numUnservedDriveThroughPens);
        memcpy(&this->m_numUnservedStopGoPens, &buffer[offset], sizeof(this->m_numUnservedStopGoPens));
        offset += sizeof(this->m_numUnservedStopGoPens);
        memcpy(&this->m_gridPosition, &buffer[offset], sizeof(this->m_gridPosition));
        offset += sizeof(this->m_gridPosition);
        memcpy(&this->m_driverStatus, &buffer[offset], sizeof(this->m_driverStatus));
        offset += sizeof(this->m_driverStatus);
        memcpy(&this->m_resultStatus, &buffer[offset], sizeof(this->m_resultStatus));
        offset += sizeof(this->m_resultStatus);
        memcpy(&this->m_pitLaneTimerActive, &buffer[offset], sizeof(this->m_pitLaneTimerActive));
        offset += sizeof(this->m_pitLaneTimerActive);
        memcpy(&this->m_pitLaneTimeInLaneInMS, &buffer[offset], sizeof(this->m_pitLaneTimeInLaneInMS));
        offset += sizeof(this->m_pitLaneTimeInLaneInMS);
        memcpy(&this->m_pitStopTimerInMS, &buffer[offset], sizeof(this->m_pitStopTimerInMS));
        offset += sizeof(this->m_pitStopTimerInMS);
        memcpy(&this->m_pitStopShouldServePen, &buffer[offset], sizeof(this->m_pitStopShouldServePen));
        offset += sizeof(this->m_pitStopShouldServePen);
        
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["lastLapTimeInMS"] = this->m_lastLapTimeInMS;
        root["currentLapTimeInMS"] = this->m_currentLapTimeInMS;
        root["sector1TimeInMS"] = this->m_sector1TimeInMS;
        root["sector2TimeInMS"] = this->m_sector2TimeInMS;
        root["lapDistance"] = this->m_lapDistance;
        root["totalDistance"] = this->m_totalDistance;
        root["safetyCarDelta"] = this->m_safetyCarDelta;
        root["carPosition"] = this->m_carPosition;
        root["currentLapNum"] = this->m_currentLapNum;
        root["pitStatus"] = this->m_pitStatus;
        root["numPitStops"] = this->m_numPitStops;
        root["sector"] = this->m_sector;
        root["currentLapInvalid"] = this->m_currentLapInvalid;
        root["penalties"] = this->m_penalties;
        root["warnings"] = this->m_warnings;
        root["numUnservedDriveThroughPens"] = this->m_numUnservedDriveThroughPens;
        root["numUnservedStopGoPens"] = this->m_numUnservedStopGoPens;
        root["gridPosition"] = this->m_gridPosition;
        root["driverStatus"] = this->m_driverStatus;
        root["resultStatus"] = this->m_resultStatus;
        root["pitLaneTimerActive"] = this->m_pitLaneTimerActive;
        root["pitLaneTimeInLaneInMS"] = this->m_pitLaneTimeInLaneInMS;
        root["pitStopTimerInMS"] = this->m_pitStopTimerInMS;
        root["pitStopShouldServePen"] = this->m_pitStopShouldServePen;

        return root;
    }

    void print(){
        std::wcout << " " << "LapData {" << std::endl;
        std::wcout << "   " << "m_lastLapTimeInMS: " << this->m_lastLapTimeInMS << std::endl;
        std::wcout << "   " << "m_currentLapTimeInMS: " << this->m_currentLapTimeInMS << std::endl;
        std::wcout << "   " << "m_sector1TimeInMS: " << this->m_sector1TimeInMS << std::endl;
        std::wcout << "   " << "m_sector2TimeInMS: " << this->m_sector2TimeInMS << std::endl;
        std::wcout << "   " << "m_lapDistance: " << this->m_lapDistance << std::endl;
        std::wcout << "   " << "m_totalDistance: " << this->m_totalDistance << std::endl;
        std::wcout << "   " << "m_safetyCarDelta: " << this->m_safetyCarDelta << std::endl;
        std::wcout << "   " << "m_carPosition: " << this->m_carPosition << std::endl;
        std::wcout << "   " << "m_currentLapNum: " << this->m_currentLapNum << std::endl;
        std::wcout << "   " << "m_pitStatus: " << this->m_pitStatus << std::endl;
        std::wcout << "   " << "m_numPitStops: " << this->m_numPitStops << std::endl;
        std::wcout << "   " << "m_sector: " << this->m_sector << std::endl;
        std::wcout << "   " << "m_currentLapInvalid: " << this->m_currentLapInvalid << std::endl;
        std::wcout << "   " << "m_penalties: " << this->m_penalties << std::endl;
        std::wcout << "   " << "m_warnings: " << this->m_warnings << std::endl;
        std::wcout << "   " << "m_numUnservedDriveThroughPens: " << this->m_numUnservedDriveThroughPens << std::endl;
        std::wcout << "   " << "m_numUnservedStopGoPens: " << this->m_numUnservedStopGoPens << std::endl;
        std::wcout << "   " << "m_gridPosition: " << this->m_gridPosition << std::endl;
        std::wcout << "   " << "m_driverStatus: " << this->m_driverStatus << std::endl;
        std::wcout << "   " << "m_resultStatus: " << this->m_resultStatus << std::endl;
        std::wcout << "   " << "m_pitLaneTimerActive: " << this->m_pitLaneTimerActive << std::endl;
        std::wcout << "   " << "m_pitLaneTimeInLaneInMS: " << this->m_pitLaneTimeInLaneInMS << std::endl;
        std::wcout << "   " << "m_pitStopTimerInMS: " << this->m_pitStopTimerInMS << std::endl;
        std::wcout << "   " << "m_pitStopShouldServePen: " << this->m_pitStopShouldServePen << std::endl;
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        return "LastLapTimeInMS,CurrentLapTimeInMS,Sector1TimeInMS,Sector2TimeInMS,LapDistance,TotalDistance,SafetyCarDelta,CarPosition,CurrentLapNum,PitStatus,NumPitStops,Sector,CurrentLapInvalid,Penalties,Warnings,NumUnservedDriveThroughPens,NumUnservedStopGoPens,GridPosition,DriverStatus,ResultStatus,PitLaneTimerActive,PitLaneTimeInLaneInMS,PitStopTimerInMS,PitStopShouldServePen";
    }

    std::string to_string(bool flag){
        std::string str;
        if (flag){
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_lastLapTimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_currentLapTimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_sector1TimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_sector2TimeInMS));
        str.append(",");
        str.append(std::to_string(this->m_lapDistance));
        str.append(",");
        str.append(std::to_string(this->m_totalDistance));
        str.append(",");
        str.append(std::to_string(this->m_safetyCarDelta));
        str.append(",");
        str.append(std::to_string(this->m_carPosition));
        str.append(",");
        str.append(std::to_string(this->m_currentLapNum));
        str.append(",");
        str.append(std::to_string(this->m_pitStatus));
        str.append(",");
        str.append(std::to_string(this->m_numPitStops));
        str.append(",");
        str.append(std::to_string(this->m_sector));
        str.append(",");
        str.append(std::to_string(this->m_currentLapInvalid));
        str.append(",");
        str.append(std::to_string(this->m_penalties));
        str.append(",");
        str.append(std::to_string(this->m_warnings));
        str.append(",");
        str.append(std::to_string(this->m_numUnservedDriveThroughPens));
        str.append(",");
        str.append(std::to_string(this->m_numUnservedStopGoPens));
        str.append(",");
        str.append(std::to_string(this->m_gridPosition));
        str.append(",");
        str.append(std::to_string(this->m_driverStatus));
        str.append(",");
        str.append(std::to_string(this->m_resultStatus));
        str.append(",");
        str.append(std::to_string(this->m_pitLaneTimerActive));
        str.append(",");
        str.append(std::to_string(this->m_pitLaneTimeInLaneInMS));
        str.append(",");
        str.append(std::to_string(this->m_pitStopTimerInMS));
        str.append(",");
        str.append(std::to_string(this->m_pitStopShouldServePen));
        
        return str;
    }

};


struct PacketLapData
{
    PacketHeader    m_header;             // Header

    LapData         m_lapData[22];        // Lap data for all cars on track

    uint8 m_timeTrialPBCarIdx;            // Index of Personal Best car in time trial (255 if invalid)
    uint8 m_timeTrialRivalCarIdx;         // Index of Rival car in time trial (255 if invalid)

    void get(char* buffer){
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++){
            offset = this->m_lapData[i].get(buffer,offset);
        }
        memcpy(&this->m_timeTrialPBCarIdx, &buffer[offset], sizeof(this->m_timeTrialPBCarIdx));
        offset += sizeof(this->m_timeTrialPBCarIdx);
        memcpy(&this->m_timeTrialRivalCarIdx, &buffer[offset], sizeof(this->m_timeTrialRivalCarIdx));
        offset += sizeof(this->m_timeTrialRivalCarIdx);
    }

    Json::Value toJSON(Json::Value root){
        for (int i = 0; i < 22; i++){
            root["LapData"]["carLapData"][i] = this->m_lapData[i].toJSON();
        }
        root["LapData"]["timeTrialPBCarIdx"] = this->m_timeTrialPBCarIdx;
        root["LapData"]["timeTrialRivalCarIdx"] = this->m_timeTrialRivalCarIdx;
        
        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(LAP_PATH, root["LapData"], frame);

        return root;
    }

    void print(){
        std::wcout << " " << "LapData {" << std::endl;
        for (int i = 0; i < 22; i++) {//22 = this->m_lapData.size()
            std::wcout << "   " << "m_lapData[" << i << "]: " << std::endl;
            this->m_lapData[i].print();
        }
        std::wcout << " " << "}" << std::endl;
    }

    std::string head_to_string(){
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",CarIndex,");
        s.append(this->m_lapData->head_to_string());
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
            str.append(this->m_lapData[i].to_string(false));
            str.append("\n");
        }
        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Lap.csv";
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