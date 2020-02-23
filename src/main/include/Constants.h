/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define DISPLAY_COMMAND_MESSAGES 1        //Comment this line out when you don't want to display the messages when each command runs

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#include <units/units.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <cmath>

//Abbreviations
//CPM = Control Panel Maniupulator

/*
CAN IDs:
1-4 drivetrain
5-8 shooter
9 intake

11-12 lift
13 serializer
14-... control panel manipulator
*/

/*
Pneumatic IDs:
x,x intake
x,x lift
*/

namespace constants
{
    using Velocity     = units::compound_unit<units::length::feet, units::inverse<units::seconds>>;
    using Acceleration = units::compound_unit<Velocity,            units::inverse<units::seconds>>;
    using kv           = units::compound_unit<units::volts,        units::inverse<Velocity>>;
    using ka           = units::compound_unit<units::volts,        units::inverse<Acceleration>>;
    namespace oi
    {
        constexpr int kDriverXboxControllerPort0 = 0;
        constexpr int kDriverXboxControllerPort1 = 1;
    }
    
    namespace drivetrain
    {
        const int kRightFrontMotorPort = 1; 
        const int kRightMiddleMotorPort = 2;
        const int kLeftFrontMotorPort = 3;
        const int kLeftMiddleMotorPort = 4;

        const bool kGyroReversed = false; // Inaccurate!
        const units::current::ampere_t kMaxCurrentDraw { 30.0 };
        const units::inch_t kWheelDiameter { 6.0 };
        const units::inch_t kTrackWidth { 28.0 }; // Maybe 
        const units::volt_t kS { 0.0 }; // Inaccurate!
        const units::unit_t<kv> kV { 0.0 }; // Inaccurate!
        const units::unit_t<ka> kA { 0.0 }; // Inaccurate!
        const double kPDriveVel = 0.0;
        extern const frc::DifferentialDriveKinematics kDriveKinematics;
        extern const frc::TrajectoryConfig kAutoConfig;

        const int kVelocityPIDPort = 0;
        const float kVelocityRange = 1000;
        const float kP_Velocity = 0;
        const float kD_Velocity = 0;
        const float kF_Velocity = 0.00125;
        const float kArbiFeedForw = 0;//units are in volts
        const float kMaxAccel = 500;
        const float kMaxVelocity = 100;

        constexpr int kPositionPIDPort = 1;

        enum DriveTrainMode_t
        {
            NORMAL
        ,   PRECISION
        };

        namespace auto_mode
        {
            constexpr units::feet_per_second_t kMaxVelocity { 10.0 };
            constexpr units::feet_per_second_squared_t kMaxAcceleration { 6.0 };
            constexpr double kRamseteB = 2.0;
            constexpr double kRamseteZeta = 0.7;
        }
    }

    namespace shooter
    {
        const int kLeftMotorPort = 5;
        const int kRightMotorPort = 6;
        const int kFeederMotor1Port = 7;
        const int kFeederMotor2Port = 8;

        const int kAllowableVelocityError = 10;

        const units::current::ampere_t kMaxCurrentDraw { 30.0 };
        // const double kP = 0.0;
        // const double kD = 0.0;
        // const double kFF = 0.0;
        const units::inch_t kWheelDiameter { 6.0 };
        const units::revolutions_per_minute_t kAllowableShootingVelocityError = 45_rpm; // within 30 rpm of target rate
        const units::revolutions_per_minute_t kAllowableSpinupVelocityError = 30_rpm; // within 30 rpm of target rate
        const units::foot_t kDistanceLowerBound { 10 }; // 10 feet away
        const units::foot_t kDistanceUpperBound { 30 }; // 30 feet away
    }

    namespace intake
    {
        constexpr int kIntakeMotorID = 9;
        constexpr int kSolenoidPorts[2] = { 0, 1 }; // Inaccurate!
        constexpr units::current::ampere_t kMaxCurrentDraw { 25.0 };
        constexpr float kMotorOperatingPercentage = 0.8f; // 
    }

    namespace lift
    {
        const int kSolenoidPorts[2] = { 4, 5 };

        const int kMotorPorts[2] = { 11 , 12 };//winch, adjustor
    } // namespace lift
     
    namespace serializer
    {
        const int kSerializerID = 13;
    }

    namespace control_panel_manipulator
    {
        const units::volt_t ControlPanelCounterClockwiseVoltage=1_V;
        const units::volt_t ControlPanelClockwiseVoltage = -1_V;

        const int kCPMDeployMotorID = -1;    //TODO: set appropriate motor id
        const int DeployPosition = -1;       //TODO: set deploy position
        const int StowPosition = -1;         //TODO: set stow position

        const int kCPMSpinMotorID = -1;      //TODO: set appropriate motor id

        const double Stage2Rotations = 3.5;

        const double DiameterOfControlePanel = 32;   //[in]
        const double DiameterOfDriverWheel = 4;      //[in]

        enum CPMMode_t
        {
            MANUAL
        ,   AUTO_SPIN
        ,   AUTO_COLOR
        };
    }

    namespace limelight
    {
        constexpr units::degree_t kCameraPitch { 30.0 };
    }

    namespace joy_deadband
    {
        inline float deadband(float joyValue)
        {
            
            return (std::abs(joyValue) > 0.15f) ? joyValue : 0.0f;
        }
    }

}
