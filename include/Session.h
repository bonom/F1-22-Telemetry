#ifndef __Session_h__
#define __Session_h__

#include <vector>

#include "Costants.h"
#include "Header.h"

struct MarshalZone {
    float m_zoneStart;  // Fraction (0..1) of way through the lap the marshal
                        // zone starts
    int8 m_zoneFlag;  // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3
                      // = yellow, 4 = red

    unsigned long get(char* buffer, unsigned long offset) {
        memcpy(&this->m_zoneStart, &buffer[offset], sizeof(m_zoneStart));
        offset = offset + sizeof(m_zoneStart);
        memcpy(&this->m_zoneFlag, &buffer[offset], sizeof(m_zoneFlag));
        offset = offset + sizeof(m_zoneFlag);

        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["zoneStart"] = m_zoneStart;
        root["zoneFlag"] = m_zoneFlag;

        return root;
    }

    void print() {
        std::wcout << " "
                   << "MarshalZone {" << std::endl;
        std::wcout << "   "
                   << "m_zoneStart: " << this->m_zoneStart << std::endl;
        std::wcout << "D  "
                   << "m_zoneFlag: " << this->m_zoneFlag << std::endl;
        std::wcout << "   "
                   << "m_zoneFlag: " << Marshal_Zone_Flag[this->m_zoneFlag]
                   << std::endl;
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string(int index) {
        std::string s;
        s.append("ZoneStart[");
        s.append(std::to_string(index));
        s.append("],");
        s.append("ZoneFlag[");
        s.append(std::to_string(index));
        s.append("]");
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string(0));
        }
        str.append(std::to_string(this->m_zoneStart));
        str.append(",");
        str.append(std::to_string(this->m_zoneFlag));

        return str;
    }
};

struct WeatherForecastSample {
    uint8 m_sessionType;  // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1 // 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
                          // 12 = R3, 13 = Time Trial
    uint8 m_timeOffset;   // Time in minutes the forecast is for
    uint8 m_weather;      // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                          // 3 = light rain, 4 = heavy rain, 5 = storm
    int8 m_trackTemperature;        // Track temp. in degrees Celsius
    int8 m_trackTemperatureChange;  // Track temp. change – 0 = up, 1 = down, 2
                                    // = no change
    int8 m_airTemperature;        // Air temp. in degrees celsius
    int8 m_airTemperatureChange;  // Air temp. change – 0 = up, 1 = down, 2 = no
                                  // change
    uint8 m_rainPercentage;  // Rain percentage (0-100)

    unsigned long get(char* buffer, unsigned long offset) {
        memcpy(&this->m_sessionType, &buffer[offset], sizeof(m_sessionType));
        offset = offset + sizeof(m_sessionType);
        memcpy(&this->m_timeOffset, &buffer[offset], sizeof(m_timeOffset));
        offset = offset + sizeof(m_timeOffset);
        memcpy(&this->m_weather, &buffer[offset], sizeof(m_weather));
        offset = offset + sizeof(m_weather);
        memcpy(&this->m_trackTemperature, &buffer[offset],
               sizeof(m_trackTemperature));
        offset = offset + sizeof(m_trackTemperature);
        memcpy(&this->m_trackTemperatureChange, &buffer[offset],
               sizeof(m_trackTemperatureChange));
        offset = offset + sizeof(m_trackTemperatureChange);
        memcpy(&this->m_airTemperature, &buffer[offset],
               sizeof(m_airTemperature));
        offset = offset + sizeof(m_airTemperature);
        memcpy(&this->m_airTemperatureChange, &buffer[offset],
               sizeof(m_airTemperatureChange));
        offset = offset + sizeof(m_airTemperatureChange);
        memcpy(&this->m_rainPercentage, &buffer[offset],
               sizeof(m_rainPercentage));
        offset = offset + sizeof(m_rainPercentage);
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;

        root["sessionType"] = m_sessionType;
        root["timeOffset"] = m_timeOffset;
        root["weather"] = m_weather;
        root["trackTemperature"] = m_trackTemperature;
        root["trackTemperatureChange"] = m_trackTemperatureChange;
        root["airTemperature"] = m_airTemperature;
        root["airTemperatureChange"] = m_airTemperatureChange;
        root["rainPercentage"] = m_rainPercentage;
        
        return root;
    }

    void print() {
        std::wcout << " "
                   << "WeatherForecastSample {" << std::endl;
        std::wcout << "   "
                   << "m_sessionType: " << Session_Type[this->m_sessionType]
                   << std::endl;
        std::wcout << "   "
                   << "m_timeOffset: " << this->m_timeOffset << std::endl;
        std::wcout << "   "
                   << "m_weather: " << Weather_Type[this->m_weather]
                   << std::endl;
        std::wcout << "   "
                   << "m_trackTemperature: " << this->m_trackTemperature
                   << std::endl;
        std::wcout << "   "
                   << "m_trackTemperatureChange: "
                   << this->m_trackTemperatureChange << std::endl;
        std::wcout << "   "
                   << "m_airTemperature: " << this->m_airTemperature
                   << std::endl;
        std::wcout << "   "
                   << "m_airTemperatureChange: " << this->m_airTemperatureChange
                   << std::endl;
        std::wcout << "   "
                   << "m_rainPercentage: " << this->m_rainPercentage
                   << std::endl;
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string(int index) {
        std::string s;
        s.append("SessionType[");
        s.append(std::to_string(index));
        s.append("],TimeOffset[");
        s.append(std::to_string(index));
        s.append("],Weather[");
        s.append(std::to_string(index));
        s.append("],TrackTemperature[");
        s.append(std::to_string(index));
        s.append("],TrackTemperatureChange[");
        s.append(std::to_string(index));
        s.append("],AirTemperature[");
        s.append(std::to_string(index));
        s.append("],AirTemperatureChange[");
        s.append(std::to_string(index));
        s.append("],RainPercentage[");
        s.append(std::to_string(index));
        s.append("]");
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string(0));
        }
        str.append(std::to_string(this->m_sessionType));
        str.append(",");
        str.append(std::to_string(this->m_timeOffset));
        str.append(",");
        str.append(std::to_string(this->m_weather));
        str.append(",");
        str.append(std::to_string(this->m_trackTemperature));
        str.append(",");
        str.append(std::to_string(this->m_trackTemperatureChange));
        str.append(",");
        str.append(std::to_string(this->m_airTemperature));
        str.append(",");
        str.append(std::to_string(this->m_airTemperatureChange));
        str.append(",");
        str.append(std::to_string(this->m_rainPercentage));

        return str;
    }
};

struct PacketSessionData {
    PacketHeader m_header;  // Header

    uint8 m_weather;  // Weather - 0 = clear,1 = light cloud,2 = overcast
                      // 3 = light rain,4 = heavy rain,5 = storm
    int8 m_trackTemperature;    // Track temp. in degrees celsius
    int8 m_airTemperature;      // Air temp. in degrees celsius
    uint8 m_totalLaps;          // Total number of laps in this race
    uint16 m_trackLength;       // Track length in metres
    uint8 m_sessionType;        //0=unknown,1=P1,2=P2, 3 = P3, 4 = Short P // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
                                // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
    int8 m_trackId;             // -1 for unknown,0-21 for tracks,see appendix
    uint8 m_formula;            // Formula,0 = F1 Modern,1 = F1 Classic,2 = F2,
                                // 3 = F1 Generic, 4 = Beta, 5 = Supercars
                                // 6 = Esports, 7 = F2 2021
    uint16 m_sessionTimeLeft;   // Time left in session in seconds
    uint16 m_sessionDuration;   // Session duration in seconds
    uint8 m_pitSpeedLimit;      // Pit speed limit in kilometres per hour
    uint8 m_gamePaused;         // Whether the game is paused
    uint8 m_isSpectating;       // Whether the player is spectating
    uint8 m_spectatorCarIndex;  // Index of the car being spectated
    uint8 m_sliProNativeSupport;     // SLI Pro support,0 = inactive,1 = active
    uint8 m_numMarshalZones;         // Number of marshal zones to follow
    MarshalZone m_marshalZones[21];  // List of marshal zones – max 21
    uint8 m_safetyCarStatus;         // 0 = no safety car,1 = full safety car
                                     // 2 = virtual safety car, 3 = formation lap
    uint8 m_networkGame;             // 0 = offline,1 = online
    uint8 m_numWeatherForecastSamples;  // Number of weather samples to follow
    WeatherForecastSample
        m_weatherForecastSamples[56];  // Array of weather forecast samples
    uint8 m_forecastAccuracy;          // 0 = Perfect, 1 = Approximate
    uint8 m_aiDifficulty;              // AI Difficulty rating – 0-110
    uint32 m_seasonLinkIdentifier;   // Identifier for season - persists across
                                     // saves
    uint32 m_weekendLinkIdentifier;  // Identifier for weekend - persists across
                                     // saves
    uint32 m_sessionLinkIdentifier;  // Identifier for session - persists across
                                     // saves
    uint8 m_pitStopWindowIdealLap;   // Ideal lap to pit on for current strategy
                                     // (player)
    uint8 m_pitStopWindowLatestLap;  // Latest lap to pit on for current
                                     // strategy (player)
    uint8 m_pitStopRejoinPosition;   // Predicted position to rejoin at (player)
    uint8 m_steeringAssist;          // 0 = off, 1 = on
    uint8 m_brakingAssist;           // 0 = off, 1 = low, 2 = medium, 3 = high
    uint8 m_gearboxAssist;  // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8 m_pitAssist;      // 0 = off, 1 = on
    uint8 m_pitReleaseAssist;       // 0 = off, 1 = on
    uint8 m_ERSAssist;              // 0 = off, 1 = on
    uint8 m_DRSAssist;              // 0 = off, 1 = on
    uint8 m_dynamicRacingLine;      // 0 = off, 1 = corners only, 2 = full
    uint8 m_dynamicRacingLineType;  // 0 = 2D, 1 = 3D
    uint8 m_gameMode;               // Game mode id - see appendix
    uint8 m_ruleSet;                // Ruleset - see appendix
    uint32 m_timeOfDay;             // Local time of day - minutes since midnight
    uint8 m_sessionLength;          // 0 = None, 2 = Very Short, 3 = Short, 4 = Medium // 5 = Medium Long, 6 = Long, 7 = Full

    void get(char* buffer) {
        unsigned long offset = this->m_header.get(buffer);
        memcpy(&this->m_weather, &buffer[offset], sizeof(m_weather));
        offset = offset + sizeof(m_weather);
        memcpy(&this->m_trackTemperature, &buffer[offset],
               sizeof(m_trackTemperature));
        offset = offset + sizeof(m_trackTemperature);
        memcpy(&this->m_airTemperature, &buffer[offset],
               sizeof(m_airTemperature));
        offset = offset + sizeof(m_airTemperature);
        memcpy(&this->m_totalLaps, &buffer[offset], sizeof(m_totalLaps));
        offset = offset + sizeof(m_totalLaps);
        memcpy(&this->m_trackLength, &buffer[offset], sizeof(m_trackLength));
        offset = offset + sizeof(m_trackLength);
        memcpy(&this->m_sessionType, &buffer[offset], sizeof(m_sessionType));
        offset = offset + sizeof(m_sessionType);
        memcpy(&this->m_trackId, &buffer[offset], sizeof(m_trackId));
        offset = offset + sizeof(m_trackId);
        memcpy(&this->m_formula, &buffer[offset], sizeof(m_formula));
        offset = offset + sizeof(m_formula);
        memcpy(&this->m_sessionTimeLeft, &buffer[offset],
               sizeof(m_sessionTimeLeft));
        offset = offset + sizeof(m_sessionTimeLeft);
        memcpy(&this->m_sessionDuration, &buffer[offset],
               sizeof(m_sessionDuration));
        offset = offset + sizeof(m_sessionDuration);
        memcpy(&this->m_pitSpeedLimit, &buffer[offset],
               sizeof(m_pitSpeedLimit));
        offset = offset + sizeof(m_pitSpeedLimit);
        memcpy(&this->m_gamePaused, &buffer[offset], sizeof(m_gamePaused));
        offset = offset + sizeof(m_gamePaused);
        memcpy(&this->m_isSpectating, &buffer[offset], sizeof(m_isSpectating));
        offset = offset + sizeof(m_isSpectating);
        memcpy(&this->m_spectatorCarIndex, &buffer[offset],
               sizeof(m_spectatorCarIndex));
        offset = offset + sizeof(m_spectatorCarIndex);
        memcpy(&this->m_sliProNativeSupport, &buffer[offset],
               sizeof(m_sliProNativeSupport));
        offset = offset + sizeof(m_sliProNativeSupport);
        memcpy(&this->m_numMarshalZones, &buffer[offset],
               sizeof(m_numMarshalZones));
        offset = offset + sizeof(m_numMarshalZones);
        for (int i = 0; i < this->m_numMarshalZones; i++) {
            offset = this->m_marshalZones[i].get(buffer, offset);
        }
        memcpy(&this->m_safetyCarStatus, &buffer[offset],
               sizeof(m_safetyCarStatus));
        offset = offset + sizeof(m_safetyCarStatus);
        memcpy(&this->m_networkGame, &buffer[offset], sizeof(m_networkGame));
        offset = offset + sizeof(m_networkGame);
        memcpy(&this->m_numWeatherForecastSamples, &buffer[offset],
               sizeof(m_numWeatherForecastSamples));
        offset = offset + sizeof(m_numWeatherForecastSamples);
        for (int i = 0; i < this->m_numWeatherForecastSamples; i++) {
            offset = this->m_weatherForecastSamples[i].get(buffer, offset);
        }
        memcpy(&this->m_forecastAccuracy, &buffer[offset],
               sizeof(m_forecastAccuracy));
        offset = offset + sizeof(m_forecastAccuracy);
        memcpy(&this->m_aiDifficulty, &buffer[offset], sizeof(m_aiDifficulty));
        offset = offset + sizeof(m_aiDifficulty);
        memcpy(&this->m_seasonLinkIdentifier, &buffer[offset],
               sizeof(m_seasonLinkIdentifier));
        offset = offset + sizeof(m_seasonLinkIdentifier);
        memcpy(&this->m_weekendLinkIdentifier, &buffer[offset],
               sizeof(m_weekendLinkIdentifier));
        offset = offset + sizeof(m_weekendLinkIdentifier);
        memcpy(&this->m_sessionLinkIdentifier, &buffer[offset],
               sizeof(m_sessionLinkIdentifier));
        offset = offset + sizeof(m_sessionLinkIdentifier);
        memcpy(&this->m_pitStopWindowIdealLap, &buffer[offset],
               sizeof(m_pitStopWindowIdealLap));
        offset = offset + sizeof(m_pitStopWindowIdealLap);
        memcpy(&this->m_pitStopWindowLatestLap, &buffer[offset],
               sizeof(m_pitStopWindowLatestLap));
        offset = offset + sizeof(m_pitStopWindowLatestLap);
        memcpy(&this->m_pitStopRejoinPosition, &buffer[offset],
               sizeof(m_pitStopRejoinPosition));
        offset = offset + sizeof(m_pitStopRejoinPosition);
        memcpy(&this->m_steeringAssist, &buffer[offset],
               sizeof(m_steeringAssist));
        offset = offset + sizeof(m_steeringAssist);
        memcpy(&this->m_brakingAssist, &buffer[offset],
               sizeof(m_brakingAssist));
        offset = offset + sizeof(m_brakingAssist);
        memcpy(&this->m_gearboxAssist, &buffer[offset],
               sizeof(m_gearboxAssist));
        offset = offset + sizeof(m_gearboxAssist);
        memcpy(&this->m_pitAssist, &buffer[offset], sizeof(m_pitAssist));
        offset = offset + sizeof(m_pitAssist);
        memcpy(&this->m_pitReleaseAssist, &buffer[offset],
               sizeof(m_pitReleaseAssist));
        offset = offset + sizeof(m_pitReleaseAssist);
        memcpy(&this->m_ERSAssist, &buffer[offset], sizeof(m_ERSAssist));
        offset = offset + sizeof(m_ERSAssist);
        memcpy(&this->m_DRSAssist, &buffer[offset], sizeof(m_DRSAssist));
        offset = offset + sizeof(m_DRSAssist);
        memcpy(&this->m_dynamicRacingLine, &buffer[offset],
               sizeof(m_dynamicRacingLine));
        offset = offset + sizeof(m_dynamicRacingLine);
        memcpy(&this->m_dynamicRacingLineType, &buffer[offset],
               sizeof(m_dynamicRacingLineType));
        offset = offset + sizeof(m_dynamicRacingLineType);
        memcpy(&this->m_gameMode, &buffer[offset],
               sizeof(m_gameMode));
        offset = offset + sizeof(m_gameMode);
        memcpy(&this->m_ruleSet, &buffer[offset],
               sizeof(m_ruleSet));
        offset = offset + sizeof(m_ruleSet);
        memcpy(&this->m_timeOfDay, &buffer[offset],
               sizeof(m_timeOfDay));
        offset = offset + sizeof(m_timeOfDay);
        memcpy(&this->m_sessionLength, &buffer[offset],
               sizeof(m_sessionLength));
        offset = offset + sizeof(m_sessionLength);
    }

    Json::Value toJSON(Json::Value root){
        root["SessionData"]["weather"] = this->m_weather;
        root["SessionData"]["trackTemperature"] = this->m_trackTemperature;
        root["SessionData"]["airTemperature"] = this->m_airTemperature;
        root["SessionData"]["totalLaps"] = this->m_totalLaps;
        root["SessionData"]["trackLength"] = this->m_trackLength;
        root["SessionData"]["sessionType"] = this->m_sessionType;
        root["SessionData"]["trackId"] = this->m_trackId;
        root["SessionData"]["formula"] = this->m_formula;
        root["SessionData"]["sessionTimeLeft"] = this->m_sessionTimeLeft;
        root["SessionData"]["sessionDuration"] = this->m_sessionDuration;
        root["SessionData"]["pitSpeedLimit"] = this->m_pitSpeedLimit;
        root["SessionData"]["gamePaused"] = this->m_gamePaused;
        root["SessionData"]["isSpectating"] = this->m_isSpectating;
        root["SessionData"]["spectatorCarIndex"] = this->m_spectatorCarIndex;
        root["SessionData"]["sliProNativeSupport"] = this->m_sliProNativeSupport;
        root["SessionData"]["numMarshalZones"] = this->m_numMarshalZones;
        for (int i = 0; i < this->m_numMarshalZones; i++) {
            root["SessionData"]["marshalZones"][i] = this->m_marshalZones[i].toJSON();
        }
        root["SessionData"]["safetyCarStatus"] = this->m_safetyCarStatus;
        root["SessionData"]["networkGame"] = this->m_networkGame;
        root["SessionData"]["numWeatherForecastSamples"] = this->m_numWeatherForecastSamples;
        for (int i = 0; i < this->m_numWeatherForecastSamples; i++) {
            root["SessionData"]["weatherForecastSamples"][i] = this->m_weatherForecastSamples[i].toJSON();
        }
        root["SessionData"]["forecastAccuracy"] = this->m_forecastAccuracy;
        root["SessionData"]["aiDifficulty"] = this->m_aiDifficulty;
        root["SessionData"]["seasonLinkIdentifier"] = this->m_seasonLinkIdentifier;
        root["SessionData"]["weekendLinkIdentifier"] = this->m_weekendLinkIdentifier;
        root["SessionData"]["sessionLinkIdentifier"] = this->m_sessionLinkIdentifier;
        root["SessionData"]["pitStopWindowIdealLap"] = this->m_pitStopWindowIdealLap;
        root["SessionData"]["pitStopWindowLatestLap"] = this->m_pitStopWindowLatestLap;
        root["SessionData"]["pitStopRejoinPosition"] = this->m_pitStopRejoinPosition;
        root["SessionData"]["steeringAssist"] = this->m_steeringAssist;
        root["SessionData"]["brakingAssist"] = this->m_brakingAssist;
        root["SessionData"]["gearboxAssist"] = this->m_gearboxAssist;
        root["SessionData"]["pitAssist"] = this->m_pitAssist;
        root["SessionData"]["pitReleaseAssist"] = this->m_pitReleaseAssist;
        root["SessionData"]["ERSAssist"] = this->m_ERSAssist;
        root["SessionData"]["DRSAssist"] = this->m_DRSAssist;
        root["SessionData"]["dynamicRacingLine"] = this->m_dynamicRacingLine;
        root["SessionData"]["dynamicRacingLineType"] = this->m_dynamicRacingLineType;
        root["SessionData"]["gameMode"] = this->m_gameMode;
        root["SessionData"]["ruleSet"] = this->m_ruleSet;
        root["SessionData"]["timeOfDay"] = this->m_timeOfDay;
        root["SessionData"]["sessionLength"] = this->m_sessionLength;
        
        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(SESSION_PATH, root["SessionData"], frame);

        return root;
    }

    void print() {
        std::wcout << " "
                   << "PacketSessionData {" << std::endl;
        std::wcout << "   "
                   << "m_weather: " << Weather_Type[this->m_weather]
                   << std::endl;
        std::wcout << "   "
                   << "m_trackTemperature: " << this->m_trackTemperature
                   << std::endl;
        std::wcout << "   "
                   << "m_airTemperature: " << this->m_airTemperature
                   << std::endl;
        std::wcout << "   "
                   << "m_totalLaps: " << this->m_totalLaps << std::endl;
        std::wcout << "   "
                   << "m_trackLength: " << this->m_trackLength << std::endl;
        std::wcout << "   "
                   << "m_sessionType: " << Session_Type[this->m_sessionType]
                   << std::endl;
        std::wcout << "   "
                   << "m_trackId: " << Track[this->m_trackId] << std::endl;
        std::wcout << "   "
                   << "m_formula: " << Formula[this->m_formula] << std::endl;
        std::wcout << "   "
                   << "m_sessionTimeLeft: " << this->m_sessionTimeLeft
                   << std::endl;
        std::wcout << "   "
                   << "m_sessionDuration: " << this->m_sessionDuration
                   << std::endl;
        std::wcout << "   "
                   << "m_pitSpeedLimit: " << this->m_pitSpeedLimit << std::endl;
        std::wcout << "   "
                   << "m_gamePaused: " << this->m_gamePaused << std::endl;
        std::wcout << "   "
                   << "m_isSpectating: " << this->m_isSpectating << std::endl;
        std::wcout << "   "
                   << "m_spectatorCarIndex: " << this->m_spectatorCarIndex
                   << std::endl;
        std::wcout << "   "
                   << "m_sliProNativeSupport: " << this->m_sliProNativeSupport
                   << std::endl;
        std::wcout << "   "
                   << "m_numMarshalZones: " << this->m_numMarshalZones
                   << std::endl;

        for (int i = 0; i < this->m_numMarshalZones; i++) {
            std::wcout << "   "
                       << "m_marshalZones[" << i << "]: " << std::endl;
            this->m_marshalZones[i].print();
        }
        std::wcout << "   "
                   << "m_safetyCarStatus: "
                   << SafetyCar[this->m_safetyCarStatus] << std::endl;
        std::wcout << "   "
                   << "m_networkGame: " << this->m_networkGame << std::endl;
        std::wcout << "   "
                   << "m_numWeatherForecastSamples: "
                   << this->m_numWeatherForecastSamples << std::endl;
        for (int i = 0; i < this->m_numWeatherForecastSamples; i++) {
            std::wcout << "   "
                       << "m_weatherForecastSamples[" << i << "]:" << std::endl;
            this->m_weatherForecastSamples[i].print();
        }
        std::wcout << "    "
                   << "m_forecastAccuracy: " << this->m_forecastAccuracy
                   << std::endl;
        std::wcout << "   "
                   << "m_AIDifficulty: " << this->m_aiDifficulty << std::endl;
        std::wcout << "   "
                   << "m_seasonLinkIdentifier: " << this->m_seasonLinkIdentifier
                   << std::endl;
        std::wcout << "   "
                   << "m_weekendLinkIdentifier: "
                   << this->m_weekendLinkIdentifier << std::endl;
        std::wcout << "   "
                   << " m_sessionLinkIdentifier: "
                   << this->m_sessionLinkIdentifier << std::endl;
        std::wcout << "   "
                   << "m_pitStopWindowIdealLap: "
                   << this->m_pitStopWindowIdealLap << std::endl;
        std::wcout << "   "
                   << "m_pitStopWindowLatestLap: "
                   << this->m_pitStopWindowLatestLap << std::endl;
        std::wcout << "   "
                   << "m_pitStopRejoinPosition: "
                   << this->m_pitStopRejoinPosition << std::endl;
        std::wcout << "   "
                   << "m_steeringAssist: " << this->m_steeringAssist
                   << std::endl;
        std::wcout << "   "
                   << "m_brakingAssist: " << this->m_brakingAssist << std::endl;
        std::wcout << "   "
                   << "m_gearboxAssist: " << this->m_gearboxAssist << std::endl;
        std::wcout << "   "
                   << "m_pitAssist: " << this->m_pitAssist << std::endl;
        std::wcout << "   "
                   << "m_pitReleaseAssist: " << this->m_pitReleaseAssist
                   << std::endl;
        std::wcout << "   "
                   << "m_ERSAssist: " << this->m_ERSAssist << std::endl;
        std::wcout << "   "
                   << "m_DRSAssist: " << this->m_DRSAssist << std::endl;
        std::wcout << "   "
                   << "m_dynamicRacingLine: " << this->m_dynamicRacingLine
                   << std::endl;
        std::wcout << "   "
                   << "m_dynamicRacingLineType: "
                   << this->m_dynamicRacingLineType << std::endl;

        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",");
        s.append(
            "Weather,TrackTemperature,AirTemperature,TotalLaps,TrackLength,"
            "SessionType,TrackId,Formula,SessionTimeLeft,SessionDuration,"
            "PitSpeedLimit,GamePaused,IsSpectating,SpectatorCarIndex,"
            "SliProNativeSupport,NumMarshalZones,");
        for (int i = 0; i < 21; i++) {
            s.append(this->m_marshalZones->head_to_string(i));
            s.append(",");
        }
        s.append("SafetyCarStatus,NetworkGame,NumWeatherForecastSamples,");
        for (int i = 0; i < 56; i++) {
            s.append(this->m_weatherForecastSamples->head_to_string(i));
            s.append(",");
        }
        s.append(
            "ForecastAccuracy,AIDifficulty,SeasonLinkIdentifier,"
            "WeekendLinkIdentifier,SessionLinkIdentifier,"
            "PitStopWindowIdealLap,PitStopWindowLatestLap,"
            "PitStopRejoinPosition,SteeringAssist,BrakingAssist,"
            "GearboxAssist,PitAssist,PitReleaseAssist,ERSAssist,"
            "DRSAssist,DynamicRacingLine,DynamicRacingLineType");
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }

        str.append(this->m_header.to_string(false));
        str.append(",");
        str.append(std::to_string(this->m_weather));
        str.append(",");
        str.append(std::to_string(this->m_trackTemperature));
        str.append(",");
        str.append(std::to_string(this->m_airTemperature));
        str.append(",");
        str.append(std::to_string(this->m_totalLaps));
        str.append(",");
        str.append(std::to_string(this->m_trackLength));
        str.append(",");
        str.append(std::to_string(this->m_sessionType));
        str.append(",");
        str.append(std::to_string(this->m_trackId));
        str.append(",");
        str.append(std::to_string(this->m_formula));
        str.append(",");
        str.append(std::to_string(this->m_sessionTimeLeft));
        str.append(",");
        str.append(std::to_string(this->m_sessionDuration));
        str.append(",");
        str.append(std::to_string(this->m_pitSpeedLimit));
        str.append(",");
        str.append(std::to_string(this->m_gamePaused));
        str.append(",");
        str.append(std::to_string(this->m_isSpectating));
        str.append(",");
        str.append(std::to_string(this->m_spectatorCarIndex));
        str.append(",");
        str.append(std::to_string(this->m_sliProNativeSupport));
        str.append(",");
        str.append(std::to_string(this->m_numMarshalZones));
        str.append(",");
        for (int i = 0; i < 21; i++) {
            if (i < this->m_numMarshalZones) {
                str.append(this->m_marshalZones[i].to_string(false));
                str.append(",");
            } else {
                str.append("-,-,");
            }
        }
        str.append(std::to_string(this->m_safetyCarStatus));
        str.append(",");
        str.append(std::to_string(this->m_networkGame));
        str.append(",");
        str.append(std::to_string(this->m_numWeatherForecastSamples));
        str.append(",");
        for (int j = 0; j < 56; j++) {
            if (j < this->m_numWeatherForecastSamples) {
                str.append(this->m_weatherForecastSamples[j].to_string(false));
                str.append(",");
            } else {
                str.append("-,-,-,-,-,-,-,-,");
            }
        }
        str.append(std::to_string(this->m_forecastAccuracy));
        str.append(",");
        str.append(std::to_string(this->m_aiDifficulty));
        str.append(",");
        str.append(std::to_string(this->m_seasonLinkIdentifier));
        str.append(",");
        str.append(std::to_string(this->m_weekendLinkIdentifier));
        str.append(",");
        str.append(std::to_string(this->m_sessionLinkIdentifier));
        str.append(",");
        str.append(std::to_string(this->m_pitStopWindowIdealLap));
        str.append(",");
        str.append(std::to_string(this->m_pitStopWindowLatestLap));
        str.append(",");
        str.append(std::to_string(this->m_pitStopRejoinPosition));
        str.append(",");
        str.append(std::to_string(this->m_steeringAssist));
        str.append(",");
        str.append(std::to_string(this->m_brakingAssist));
        str.append(",");
        str.append(std::to_string(this->m_gearboxAssist));
        str.append(",");
        str.append(std::to_string(this->m_pitAssist));
        str.append(",");
        str.append(std::to_string(this->m_pitReleaseAssist));
        str.append(",");
        str.append(std::to_string(this->m_ERSAssist));
        str.append(",");
        str.append(std::to_string(this->m_DRSAssist));
        str.append(",");
        str.append(std::to_string(this->m_dynamicRacingLine));
        str.append(",");
        str.append(std::to_string(this->m_dynamicRacingLineType));
        str.append("\n");

        return str;
    }

    void to_csv(const char* dirname) {
        std::string filename = std::string(dirname) + "/Session.csv";
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