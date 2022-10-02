#ifndef __Motion_h_
#define __Motion_h_

#include <iostream>

#include "Costants.h"
#include "Header.h"

struct CarMotionData {
    float         m_worldPositionX;           // World space X position
    float         m_worldPositionY;           // World space Y position
    float         m_worldPositionZ;           // World space Z position
    float         m_worldVelocityX;           // Velocity in world space X
    float         m_worldVelocityY;           // Velocity in world space Y
    float         m_worldVelocityZ;           // Velocity in world space Z
    int16         m_worldForwardDirX;         // World space forward X direction (normalised)
    int16         m_worldForwardDirY;         // World space forward Y direction (normalised)
    int16         m_worldForwardDirZ;         // World space forward Z direction (normalised)
    int16         m_worldRightDirX;           // World space right X direction (normalised)
    int16         m_worldRightDirY;           // World space right Y direction (normalised)
    int16         m_worldRightDirZ;           // World space right Z direction (normalised)
    float         m_gForceLateral;            // Lateral G-Force component
    float         m_gForceLongitudinal;       // Longitudinal G-Force component
    float         m_gForceVertical;           // Vertical G-Force component
    float         m_yaw;                      // Yaw angle in radians
    float         m_pitch;                    // Pitch angle in radians
    float         m_roll;                     // Roll angle in radians

    unsigned long get(char* buffer, unsigned long offset) {
        // WorldPosition
        memcpy(&this->m_worldPositionX, &buffer[offset],
               sizeof(m_worldPositionX));
        offset = offset + sizeof(m_worldPositionX);
        memcpy(&this->m_worldPositionY, &buffer[offset],
               sizeof(m_worldPositionY));
        offset = offset + sizeof(m_worldPositionY);
        memcpy(&this->m_worldPositionZ, &buffer[offset],
               sizeof(m_worldPositionZ));
        offset = offset + sizeof(m_worldPositionZ);
        // WorldVelocity
        memcpy(&this->m_worldVelocityX, &buffer[offset],
               sizeof(m_worldVelocityX));
        offset = offset + sizeof(m_worldVelocityX);
        memcpy(&this->m_worldVelocityY, &buffer[offset],
               sizeof(m_worldVelocityY));
        offset = offset + sizeof(m_worldVelocityY);
        memcpy(&this->m_worldVelocityZ, &buffer[offset],
               sizeof(m_worldVelocityZ));
        offset = offset + sizeof(m_worldVelocityZ);
        // WorldForwardDir
        memcpy(&this->m_worldForwardDirX, &buffer[offset],
               sizeof(m_worldForwardDirX));
        offset = offset + sizeof(m_worldForwardDirX);
        memcpy(&this->m_worldForwardDirY, &buffer[offset],
               sizeof(m_worldForwardDirY));
        offset = offset + sizeof(m_worldForwardDirY);
        memcpy(&this->m_worldForwardDirZ, &buffer[offset],
               sizeof(m_worldForwardDirZ));
        offset = offset + sizeof(m_worldForwardDirZ);
        // WorldRightDir
        memcpy(&this->m_worldRightDirX, &buffer[offset],
               sizeof(m_worldRightDirX));
        offset = offset + sizeof(m_worldRightDirX);
        memcpy(&this->m_worldRightDirY, &buffer[offset],
               sizeof(m_worldRightDirY));
        offset = offset + sizeof(m_worldRightDirY);
        memcpy(&this->m_worldRightDirZ, &buffer[offset],
               sizeof(m_worldRightDirZ));
        offset = offset + sizeof(m_worldRightDirZ);
        // gForce
        memcpy(&this->m_gForceLateral, &buffer[offset],
               sizeof(m_gForceLateral));
        offset = offset + sizeof(m_gForceLateral);
        memcpy(&this->m_gForceLongitudinal, &buffer[offset],
               sizeof(m_gForceLongitudinal));
        offset = offset + sizeof(m_gForceLongitudinal);
        memcpy(&this->m_gForceVertical, &buffer[offset],
               sizeof(m_gForceVertical));
        offset = offset + sizeof(m_gForceVertical);
        // Angles
        memcpy(&this->m_yaw, &buffer[offset], sizeof(m_yaw));
        offset = offset + sizeof(m_yaw);
        memcpy(&this->m_pitch, &buffer[offset], sizeof(m_pitch));
        offset = offset + sizeof(m_pitch);
        memcpy(&this->m_roll, &buffer[offset], sizeof(m_roll));
        offset = offset + sizeof(m_roll);

        //
        return offset;
    }

    Json::Value toJSON(){
        Json::Value root;
        root["worldPositionX"] = this->m_worldPositionX;
        root["worldPositionY"] = this->m_worldPositionY;
        root["worldPositionZ"] = this->m_worldPositionZ;

        root["worldVelocityX"] = this->m_worldVelocityX;
        root["worldVelocityY"] = this->m_worldVelocityY;
        root["worldVelocityZ"] = this->m_worldVelocityZ;

        root["worldForwardDirX"] = this->m_worldForwardDirX;
        root["worldForwardDirY"] = this->m_worldForwardDirY;
        root["worldForwardDirZ"] = this->m_worldForwardDirZ;

        root["worldRightDirX"] = this->m_worldRightDirX;
        root["worldRightDirY"] = this->m_worldRightDirY;
        root["worldRightDirZ"] = this->m_worldRightDirZ;

        root["gForceLateral"] = this->m_gForceLateral;
        root["gForceLongitudinal"] = this->m_gForceLongitudinal;
        root["gForceVertical"] = this->m_gForceVertical;

        root["yaw"] = this->m_yaw;
        root["pitch"] = this->m_pitch;
        root["roll"] = this->m_roll;

        return root;
    }

    void print() {
        std::wcout << " "
                   << "CarMotionData {" << std::endl;
        // WorldPosition
        std::wcout << "   "
                   << "m_worldPositionX: " << this->m_worldPositionX
                   << std::endl;
        std::wcout << "   "
                   << "m_worldPositionY: " << this->m_worldPositionY
                   << std::endl;
        std::wcout << "   "
                   << "m_worldPositionZ: " << this->m_worldPositionZ
                   << std::endl;
        // WorldVelocity
        std::wcout << "   "
                   << "m_worldVelocityX: " << this->m_worldVelocityX
                   << std::endl;
        std::wcout << "   "
                   << "m_worldVelocityY: " << this->m_worldVelocityY
                   << std::endl;
        std::wcout << "   "
                   << "m_worldVelocityZ: " << this->m_worldVelocityZ
                   << std::endl;
        // WorldForwardDir
        std::wcout << "   "
                   << "m_worldForwardDirX: " << this->m_worldForwardDirX
                   << std::endl;
        std::wcout << "   "
                   << "m_worldForwardDirY: " << this->m_worldForwardDirY
                   << std::endl;
        std::wcout << "   "
                   << "m_worldForwardDirZ: " << this->m_worldForwardDirZ
                   << std::endl;
        // WorldRightDir
        std::wcout << "   "
                   << "m_worldRightDirX: " << this->m_worldRightDirX
                   << std::endl;
        std::wcout << "   "
                   << "m_worldRightDirY: " << this->m_worldRightDirY
                   << std::endl;
        std::wcout << "   "
                   << "m_worldRightDirZ: " << this->m_worldRightDirZ
                   << std::endl;
        // gForce
        std::wcout << "   "
                   << "m_gForceLateral: " << this->m_gForceLateral << std::endl;
        std::wcout << "   "
                   << "m_gForceLongitudinal: " << this->m_gForceLongitudinal
                   << std::endl;
        std::wcout << "   "
                   << "m_gForceVertical: " << this->m_gForceVertical
                   << std::endl;
        // Angles
        std::wcout << "   "
                   << "m_yaw: " << this->m_yaw << std::endl;
        std::wcout << "   "
                   << "m_pitch: " << this->m_pitch << std::endl;
        std::wcout << "   "
                   << "m_roll: " << this->m_roll << std::endl;
        //
        std::wcout << " "
                   << "}" << std::endl;
    }

    std::string head_to_string() {
        return "WorldPositionX,WorldPositionY,WorldPositionZ,WorldVelocityX,"
               "WorldVelocityY,WorldVelocityZ,WorldForwardDirX,"
               "WorldForwardDirY,WorldForwardDirZ,WorldRightDirX,"
               "WorldRightDirY,WorldRightDirZ,gForceLateral,gForceLongitudinal,"
               "gForceVertical,Yaw,Pitch,Roll";
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }
        str.append(std::to_string(this->m_worldPositionX));
        str.append(",");
        str.append(std::to_string(this->m_worldPositionY));
        str.append(",");
        str.append(std::to_string(this->m_worldPositionZ));
        str.append(",");
        str.append(std::to_string(this->m_worldVelocityX));
        str.append(",");
        str.append(std::to_string(this->m_worldVelocityY));
        str.append(",");
        str.append(std::to_string(this->m_worldVelocityZ));
        str.append(",");
        str.append(std::to_string(this->m_worldForwardDirX));
        str.append(",");
        str.append(std::to_string(this->m_worldForwardDirY));
        str.append(",");
        str.append(std::to_string(this->m_worldForwardDirZ));
        str.append(",");
        str.append(std::to_string(this->m_worldRightDirX));
        str.append(",");
        str.append(std::to_string(this->m_worldRightDirY));
        str.append(",");
        str.append(std::to_string(this->m_worldRightDirZ));
        str.append(",");
        str.append(std::to_string(this->m_gForceLateral));
        str.append(",");
        str.append(std::to_string(this->m_gForceLongitudinal));
        str.append(",");
        str.append(std::to_string(this->m_gForceVertical));
        str.append(",");
        str.append(std::to_string(this->m_yaw));
        str.append(",");
        str.append(std::to_string(this->m_pitch));
        str.append(",");
        str.append(std::to_string(this->m_roll));

        return str;
    }
};


struct PacketMotionData {
    PacketHeader    m_header;               	// Header

    CarMotionData   m_carMotionData[22];    	// Data for all cars on track

    // Extra player car ONLY data
    float         m_suspensionPosition[4];       // Note: All wheel arrays have the following order:
    float         m_suspensionVelocity[4];       // RL, RR, FL, FR
    float         m_suspensionAcceleration[4];	// RL, RR, FL, FR
    float         m_wheelSpeed[4];           	// Speed of each wheel
    float         m_wheelSlip[4];                // Slip ratio for each wheel
    float         m_localVelocityX;         	// Velocity in local space
    float         m_localVelocityY;         	// Velocity in local space
    float         m_localVelocityZ;         	// Velocity in local space
    float         m_angularVelocityX;		// Angular velocity x-component
    float         m_angularVelocityY;            // Angular velocity y-component
    float         m_angularVelocityZ;            // Angular velocity z-component
    float         m_angularAccelerationX;        // Angular velocity x-component
    float         m_angularAccelerationY;	// Angular velocity y-component
    float         m_angularAccelerationZ;        // Angular velocity z-component
    float         m_frontWheelsAngle;            // Current front wheels angle in radians

    void get(char* buffer) {
        // WorldPosition
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++) {
            offset = this->m_carMotionData[i].get(buffer, offset);
        }
        // Suspensions
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionPosition[i], &buffer[offset],
                   sizeof(this->m_suspensionPosition[i]));
            offset = offset + sizeof(this->m_suspensionPosition[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionVelocity[i], &buffer[offset],
                   sizeof(this->m_suspensionVelocity[i]));
            offset = offset + sizeof(this->m_suspensionVelocity[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionAcceleration[i], &buffer[offset],
                   sizeof(this->m_suspensionAcceleration[i]));
            offset = offset + sizeof(this->m_suspensionAcceleration[i]);
        }
        // Wheels
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_wheelSpeed[i], &buffer[offset],
                   sizeof(this->m_wheelSpeed[i]));
            offset = offset + sizeof(this->m_wheelSpeed[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_wheelSlip[i], &buffer[offset],
                   sizeof(this->m_wheelSlip[i]));
            offset = offset + sizeof(this->m_wheelSlip[i]);
        }
        // localVelocity
        memcpy(&this->m_localVelocityX, &buffer[offset],
               sizeof(m_localVelocityX));
        offset = offset + sizeof(m_localVelocityX);
        memcpy(&this->m_localVelocityY, &buffer[offset],
               sizeof(m_localVelocityY));
        offset = offset + sizeof(m_localVelocityY);
        memcpy(&this->m_localVelocityZ, &buffer[offset],
               sizeof(m_localVelocityZ));
        offset = offset + sizeof(m_localVelocityZ);
        // angularVelocity
        memcpy(&this->m_angularVelocityX, &buffer[offset],
               sizeof(m_angularVelocityX));
        offset = offset + sizeof(m_angularVelocityX);
        memcpy(&this->m_angularVelocityY, &buffer[offset],
               sizeof(m_angularVelocityY));
        offset = offset + sizeof(m_angularVelocityY);
        memcpy(&this->m_angularVelocityZ, &buffer[offset],
               sizeof(m_angularVelocityZ));
        offset = offset + sizeof(m_angularVelocityZ);
        // angularAcceleration
        memcpy(&this->m_angularAccelerationX, &buffer[offset],
               sizeof(m_angularAccelerationX));
        offset = offset + sizeof(m_angularAccelerationX);
        memcpy(&this->m_angularAccelerationY, &buffer[offset],
               sizeof(m_angularAccelerationY));
        offset = offset + sizeof(m_angularAccelerationY);
        memcpy(&this->m_angularAccelerationZ, &buffer[offset],
               sizeof(m_angularAccelerationZ));
        offset = offset + sizeof(m_angularAccelerationZ);

        memcpy(&this->m_frontWheelsAngle, &buffer[offset],
               sizeof(m_frontWheelsAngle));
        offset = offset + sizeof(m_frontWheelsAngle);
    }

    Json::Value toJSON(Json::Value root){
        // Car Motion Data
        for (int i = 0; i < 22; i++) {
            root["MotionData"]["carMotionData"][i] = this->m_carMotionData[i].toJSON();
        }
        
        // Suspensions
        for (int i = 0; i < 4; i++) {
            root["MotionData"]["suspensionPosition"][TyrePosition[i]] = this->m_suspensionPosition[i];
        }
        for (int i = 0; i < 4; i++) {
            root["MotionData"]["suspensionVelocity"][TyrePosition[i]] = this->m_suspensionVelocity[i];
        }
        for (int i = 0; i < 4; i++) {
            root["MotionData"]["suspensionAcceleration"][TyrePosition[i]] = this->m_suspensionAcceleration[i];
        }
        
        // Wheels
        for (int i = 0; i < 4; i++) {
            root["MotionData"]["wheelSpeed"][TyrePosition[i]] = this->m_wheelSpeed[i];
        }
        for (int i = 0; i < 4; i++) {
            root["MotionData"]["wheelSlip"][TyrePosition[i]] = this->m_wheelSlip[i];
        }
        
        // localVelocity
        root["MotionData"]["localVelocityX"] = this->m_localVelocityX;
        root["MotionData"]["localVelocityY"] = this->m_localVelocityY;
        root["MotionData"]["localVelocityZ"] = this->m_localVelocityZ;
        
        // angularVelocity
        root["MotionData"]["angularVelocityX"] = this->m_angularVelocityX;
        root["MotionData"]["angularVelocityY"] = this->m_angularVelocityY;
        root["MotionData"]["angularVelocityZ"] = this->m_angularVelocityZ;
        
        // angularAcceleration
        root["MotionData"]["angularAccelerationX"] = this->m_angularAccelerationX;
        root["MotionData"]["angularAccelerationY"] = this->m_angularAccelerationY;
        root["MotionData"]["angularAccelerationZ"] = this->m_angularAccelerationZ;

        // frontWheelsAngle
        root["MotionData"]["frontWheelsAngle"] = this->m_frontWheelsAngle;


        uint32 frame = this->m_header.m_frameIdentifier;
        writeJsonDataToFile(MOTION_PATH, root["MotionData"], frame);

        return root;
    }

    void print() {
        std::wcout << " "
                   << "PacketMotionData {" << std::endl;
        for (int i = 0; i < 22; i++)  // 22 = this->m_carMotionData.size()
        {
            std::wcout << "   "
                       << "m_carMotionData[" << i << "]: " << std::endl;
            this->m_carMotionData->print();
        }

        // Suspensions
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    std::wcout << "  Wheel Rear Left" << std::endl;
                    break;
                case 1:
                    std::wcout << "  Wheel Rear Right" << std::endl;
                    break;
                case 2:
                    std::wcout << "  Wheel Front Left" << std::endl;
                    break;
                case 3:
                    std::wcout << "  Wheel Front Right" << std::endl;
                    break;
                default:
                    std::wcout << "  Wheel None" << std::endl;
                    break;
            }
            std::wcout << "   m_suspensionPosition[" << i
                       << "]: " << this->m_suspensionPosition[i] << std::endl;
            std::wcout << "   m_suspensionVelocity[" << i
                       << "]: " << this->m_suspensionVelocity[i] << std::endl;
            std::wcout << "   m_suspensionAcceleration[" << i
                       << "]: " << this->m_suspensionAcceleration[i]
                       << std::endl;
        }
        // Wheels
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    std::wcout << "  Wheel Rear Left" << std::endl;
                    break;
                case 1:
                    std::wcout << "  Wheel Rear Right" << std::endl;
                    break;
                case 2:
                    std::wcout << "  Wheel Front Left" << std::endl;
                    break;
                case 3:
                    std::wcout << "  Wheel Front Right" << std::endl;
                    break;
                default:
                    std::wcout << "  Wheel None" << std::endl;
                    break;
            }
            std::wcout << "   m_wheelSpeed[" << i
                       << "]: " << this->m_wheelSpeed[i] << std::endl;
            std::wcout << "   m_wheelSlip[" << i
                       << "]: " << this->m_wheelSlip[i] << std::endl;
        }
        // localVelocity
        std::wcout << "   m_localVelocityX: " << this->m_localVelocityX
                   << std::endl;
        std::wcout << "   m_localVelocityY: " << this->m_localVelocityY
                   << std::endl;
        std::wcout << "   m_localVelocityZ: " << this->m_localVelocityZ
                   << std::endl;
        // angularVelocity
        std::wcout << "   m_angularVelocityX: " << this->m_angularVelocityX
                   << std::endl;
        std::wcout << "   m_angularVelocityY: " << this->m_angularVelocityY
                   << std::endl;
        std::wcout << "   m_angularVelocityZ: " << this->m_angularVelocityZ
                   << std::endl;
        // angularAcceleration
        std::wcout << "   m_angularAccelerationX: "
                   << this->m_angularAccelerationX << std::endl;
        std::wcout << "   m_angularAccelerationY: "
                   << this->m_angularAccelerationY << std::endl;
        std::wcout << "   m_angularAccelerationZ: "
                   << this->m_angularAccelerationZ << std::endl;

        std::wcout << "   m_frontWheelsAngle: " << this->m_frontWheelsAngle
                   << std::endl;

        std::wcout << " "
                   << "}" << std::endl;
    }
    
    std::string head_to_string() {
        std::string s;
        s.append(this->m_header.head_to_string());
        s.append(",");
        s.append(
            "CarIndex,"
            "RLSuspensionPosition,RRSuspensionPosition,FLSuspensionPosition,FRSuspensionPosition,"
            "RLSuspensionVelocity,RRSuspensionVelocity,FLSuspensionVelocity,FRSuspensionVelocity,"
            "RLSuspensionAcceleration,RRSuspensionAcceleration,FLSuspensionAcceleration,FRSuspensionAcceleration,"
            "RLWheelSpeed,RRWheelSpeed,FLWheelSpeed,FRWheelSpeed,"
            "RLWheelSlip,RRWheelSlip,FLWheelSlip,FRWheelSlip,"
            "LocalVelocityX,LocalVelocityY,LocalVelocityZ,"
            "AngularVelocityX,AngularVelocityY,AngularVelocityZ,"
            "AngularAccelerationX,AngularAccelerationY,AngularAccelerationZ,"
            "FrontWheelsAngle");
        s.append(",");
        s.append(this->m_carMotionData->head_to_string());
        return s;
    }

    std::string to_string(bool flag) {
        std::string str;
        if (flag) {
            str.append(this->head_to_string());
            str.append("\n");
        }
        for (int i = 0; i < 22; i++)  // 22 = this->m_carMotionData.size()
        {
            str.append(this->m_header.to_string(false));
            str.append(",");
            str.append(std::to_string(i));
            str.append(",");
            str.append(std::to_string(this->m_suspensionPosition[0]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionPosition[1]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionPosition[2]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionPosition[3]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionVelocity[0]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionVelocity[1]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionVelocity[2]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionVelocity[3]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionAcceleration[0]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionAcceleration[1]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionAcceleration[2]));
            str.append(",");
            str.append(std::to_string(this->m_suspensionAcceleration[3]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSpeed[0]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSpeed[1]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSpeed[2]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSpeed[3]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSlip[0]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSlip[1]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSlip[2]));
            str.append(",");
            str.append(std::to_string(this->m_wheelSlip[3]));
            str.append(",");
            str.append(std::to_string(this->m_localVelocityX));
            str.append(",");
            str.append(std::to_string(this->m_localVelocityY));
            str.append(",");
            str.append(std::to_string(this->m_localVelocityZ));
            str.append(",");
            str.append(std::to_string(this->m_angularVelocityX));
            str.append(",");
            str.append(std::to_string(this->m_angularVelocityY));
            str.append(",");
            str.append(std::to_string(this->m_angularVelocityZ));
            str.append(",");
            str.append(std::to_string(this->m_angularAccelerationX));
            str.append(",");
            str.append(std::to_string(this->m_angularAccelerationY));
            str.append(",");
            str.append(std::to_string(this->m_angularAccelerationZ));
            str.append(",");
            str.append(std::to_string(this->m_frontWheelsAngle));
            str.append(",");
            str.append(this->m_carMotionData[i].to_string(false));
            str.append("\n");
        }
        return str;
    }

    void to_csv(const char * dirname){
        std::string filename = std::string(dirname)+"/Motion.csv";
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