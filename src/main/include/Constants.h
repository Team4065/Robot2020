#pragma once

#include <units/units.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <cmath>

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
        constexpr int kDriverXboxControllerPort = 0;
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

        constexpr double kGearRatio = 9.47;

        const int kVelocityPIDPort = 0;
        const float kVelocityRange = 1000;
        const float kP_Velocity = 0;
        const float kD_Velocity = 0;
        const float kF_Velocity = 0.00125;
        const float kArbiFeedForw = 0;//units are in volts
        const float kMaxAccel = 500;
        const float kMaxVelocity = 100;

        constexpr int kPositionPIDPort = 1;

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
        constexpr int kLeftMotorPort = 1;
        constexpr int kRightMotorPort = 2;
        constexpr int kFeederMotor1Port = 5;
        constexpr int kFeederMotor2Port = 9;

        constexpr int kAllowableVelocityError = 10;
        constexpr double kKickerSpeed = 0.8;
        constexpr double kFeederSpeed = 0.5;

        constexpr units::current::ampere_t kMaxCurrentDraw { 35.0 };
        constexpr units::current::ampere_t kMaxPeakCurrentDraw { 40.0 };
        constexpr units::time::second_t kCurrentLimitingTriggerTime { 0.01 }; // 10ms
        constexpr double kP = 0.08;
        constexpr double kD = 0.0;
        constexpr double kFF = 0.1;
        constexpr units::meter_t kWheelDiameter { 0.1524 };
        constexpr units::revolutions_per_minute_t kAllowableShootingVelocityError = 45_rpm; // within 30 rpm of target rate
        constexpr units::revolutions_per_minute_t kAllowableSpinupVelocityError = 30_rpm; // within 30 rpm of target rate
        constexpr units::foot_t kDistanceLowerBound { 10 }; // 10 feet away
        constexpr units::foot_t kDistanceUpperBound { 30 }; // 30 feet away
    }

    namespace intake
    {
        constexpr int kIntakeMotorID = 10;
        constexpr int kSolenoidPorts[2] = { 2, 6 }; // Inaccurate!
        constexpr units::current::ampere_t kMaxCurrentDraw { 25.0 };
        constexpr float kMotorOperatingPercentage = 0.65f; // 
    }

    namespace lift
    {
        const int kSolenoidPorts[2] = { 3, 7 };

        constexpr int kMasterPort = 8;
        constexpr int kSlavePort = 6;
        constexpr units::inch_t kHeightTolerance { 0.5 };
    } // namespace lift
     
    namespace serializer
    {
        constexpr int kSerializerID = 7;
        constexpr double kIndexingSpeed = 0.5;
        constexpr double kAntiJamSpeed = 0.1;
    }

    namespace control_panel_manipulator
    {

    }

    namespace limelight
    {
        constexpr units::degree_t kCameraPitch { 30.0 };
        constexpr double kAlignKp = 0.001;
        constexpr double kAlignKi = 0.0;
        constexpr double kAlignKd = 0.0;
        constexpr units::degree_t kOffsetTolerance { 1.5 };
    }
}
