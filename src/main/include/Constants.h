#pragma once

#include <units/units.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <cmath>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <units/units.h>
#include <wpi/math>

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

namespace DriveConstants {
constexpr int kLeftMotor1Port = 1;
constexpr int kLeftMotor2Port = 2;
constexpr int kRightMotor1Port = 4;
constexpr int kRightMotor2Port = 3;

constexpr auto kTrackwidth = 0.6356_m;

extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr double kGearRatio = 9.47;
constexpr double kWheelDiameterMeters = 0.1524;
constexpr double kPI = wpi::math::pi;

constexpr bool kGyroReversed = true;

constexpr auto ks = 0.1235_V;
constexpr auto kv = 2.46 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.161 * 1_V * 1_s * 1_s / 1_m;

constexpr double kPDriveVel = 6.44;
constexpr double kIDriveVel = 0.0;
constexpr double kDDriveVel = 0;

constexpr double kencoderConstant =  kWheelDiameterMeters * wpi::math::pi / kGearRatio;

} 

namespace AutoConstants {
constexpr auto kMaxSpeed = 0.5_mps;
constexpr auto kMaxAcceleration = 0.5_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2.0;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

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
        const int kRightFrontMotorPort = 4; 
        const int kRightMiddleMotorPort = 3;
        const int kLeftFrontMotorPort = 1;
        const int kLeftMiddleMotorPort = 2;

        constexpr units::volt_t kNominalVoltage { 12.0 };
        const bool kGyroReversed = true; // Inaccurate!
        const units::current::ampere_t kMaxCurrentDraw { 30.0 };
        const units::meter_t kWheelDiameter { 0.1524 };
        const units::inch_t kTrackWidth { 0.6356 }; // Maybe 
        const units::volt_t kS { 0.1235 }; // Inaccurate!
        const units::unit_t<kv> kV { 2.46 }; // Inaccurate!
        const units::unit_t<ka> kA { 0.161 }; // Inaccurate!
        const double kPDriveVel = 6.44;
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

        constexpr units::volt_t kMinTurnVoltage { 0.5 };

        namespace auto_mode
        {
            constexpr units::meters_per_second_t kMaxVelocity { 3.5 };
            constexpr units::meters_per_second_squared_t kMaxAcceleration { 5.0 };
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

        constexpr units::current::ampere_t kMaxCurrentDraw { 45.0 };
        constexpr units::current::ampere_t kMaxPeakCurrentDraw { 45.0 };
        constexpr units::time::second_t kCurrentLimitingTriggerTime { 0.01 }; // 10ms
        constexpr double kP = 0.1;
        constexpr double kD = 0.0;
        constexpr double kFF = 0.12;
        constexpr units::meter_t kWheelDiameter { 0.1524 };
        constexpr units::revolutions_per_minute_t kAllowableShootingVelocityError = 45_rpm; // within 30 rpm of target rate
        constexpr units::revolutions_per_minute_t kAllowableSpinupVelocityError = 30_rpm; // within 30 rpm of target rate
        constexpr units::foot_t kDistanceLowerBound { 10 }; // 10 feet away
        constexpr units::foot_t kDistanceUpperBound { 30 }; // 30 feet away
    }

    namespace intake
    {
        constexpr int kIntakeMotorID = 10;
        constexpr int kSolenoidPorts[2] = { 7, 3 }; 
        constexpr units::current::ampere_t kMaxCurrentDraw { 25.0 };
        constexpr float kMotorOperatingPercentage = 0.65f; // 
    }

    namespace lift
    {
        const int kSolenoidPorts[2] = { 6, 2 };

        constexpr int kMasterPort = 8;
        constexpr int kSlavePort = 6;
        constexpr units::inch_t kHeightTolerance { 0.5 };
        constexpr units::inch_t kTurnToInches { 0.0 };
        constexpr units::current::ampere_t kMaxCurrentDraw { 40.0 };
        constexpr units::feet_per_second_t kMaxVelocity { 0.6 };
        constexpr units::feet_per_second_squared_t kMaxAcceleration { 1.2 };
        constexpr double kP = 0.001;
        constexpr double kI = 0.0;
        constexpr double kD = 0.0;
        constexpr double kF = 0.0;
        constexpr units::foot_t kSoftLimitHeight { 0.0 };
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
        constexpr units::degree_t kCameraAngle { 30.0 };
        constexpr units::meter_t kCameraHeight { 0.0 };
        constexpr units::meter_t kGoalHeight { 0.0 };
        constexpr double kAlignKp = 0.007;
        constexpr double kAlignKi = 0.0;
        constexpr double kAlignKd = 0.00;
        constexpr units::degree_t kOffsetTolerance { 1.5 };
        enum pipes
        {
            NO_TRACKING, TRACKING
        };
    }
}
