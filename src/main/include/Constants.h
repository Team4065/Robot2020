#pragma once

#include <units/units.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <cmath>

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
    namespace shooter
    {
        const int kLeftMotorPort = 1;
        const int kRightMotorPort = 2;
        const units::current::ampere_t kMaxCurrentDraw { 30.0 };
        const double kP = 0.0;
        const double kD = 0.0;
        const double kFF = 0.0;
        const units::inch_t kWheelDiameter { 6.0 };
        const units::revolutions_per_minute_t kAllowableShootingVelocityError = 45_rpm; // within 30 rpm of target rate
        const units::revolutions_per_minute_t kAllowableSpinupVelocityError = 30_rpm; // within 30 rpm of target rate
        const units::foot_t kDistanceLowerBound { 10 }; // 10 feet away
        const units::foot_t kDistanceUpperBound { 30 }; // 30 feet away
    }
    namespace drivetrain
    {
        const int kLeftFrontMotorPort = 3;
        const int kLeftMiddleMotorPort = 4; 
        //const int kLeftRearMotorPort = 5; // Inaccurate!
        const int kRightFrontMotorPort = 1; 
        const int kRightMiddleMotorPort = 2; 
        //const int kRightRearMotorPort = 8; // Inaccurate!
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

        namespace auto_mode
        {
            constexpr units::feet_per_second_t kMaxVelocity { 10.0 };
            constexpr units::feet_per_second_squared_t kMaxAcceleration { 6.0 };
            constexpr double kRamseteB = 2.0;
            constexpr double kRamseteZeta = 0.7;
        }
    }
    namespace intake
    {
        constexpr int kIntakeMotorID = 10; // Inaccurate!
        constexpr int kLeftSolenoidPorts[2] = { 0, 1 }; // Inaccurate!
        constexpr int kRightSolenoidPorts[2] = { 2, 3 }; // Inaccurate!
        constexpr units::current::ampere_t kMaxCurrentDraw { 25.0 };
        constexpr float kMotorOperatingPercentage = 0.8f; // 
    }
    namespace lift
    {
        const int kLeftSolenoidPorts[2] = { 4, 5 };
        const int kRightSolenoidPorts[2] = { 6, 7 };
        const int kMotorPorts[1] = { 11 };
    } // namespace lift
    
    namespace serializer
    {

    }
    namespace control_panel_manipulator
    {
       const units::volt_t ControlPanelCounterClockwiseVoltage=1_V;
       const units::volt_t ControlPanelClockwiseVoltage = -1_V;

       const double Rotations =3.5;

       const double DiameterOfControlePanel = 32; 
       const double DiameterOfDriverWheel = 4;
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
