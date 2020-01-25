#pragma once

#include <units/units.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/TrajectoryConfig.h>

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
        constexpr int kLeftMotorPort = 1;
        constexpr int kRightMotorPort = 2;
        constexpr units::current::ampere_t kMaxCurrentDraw { 30.0 };
        constexpr double kP = 0.0;
        constexpr double kD = 0.0;
        constexpr double kFF = 0.0;
        constexpr units::inch_t kWheelDiameter { 6.0 };
        constexpr units::revolutions_per_minute_t kAllowableShootingVelocityError = 45_rpm; // within 30 rpm of target rate
        constexpr units::revolutions_per_minute_t kAllowableSpinupVelocityError = 30_rpm; // within 30 rpm of target rate
        constexpr units::foot_t kDistanceLowerBound { 10 }; // 10 feet away
        constexpr units::foot_t kDistanceUpperBound { 30 }; // 30 feet away
    }
    namespace drivetrain
    {
        constexpr int kLeftFrontMotorPort = 3; // Inaccurate!
        constexpr int kLeftMiddleMotorPort = 4; // Inaccurate!
        constexpr int kLeftRearMotorPort = 5; // Inaccurate!
        constexpr int kRightFrontMotorPort = 6; // Inaccurate!
        constexpr int kRightMiddleMotorPort = 7; // Inaccurate!
        constexpr int kRightRearMotorPort = 8; // Inaccurate!
        constexpr bool kGyroReversed = true; // Inaccurate!
        constexpr units::current::ampere_t kMaxCurrentDraw { 30.0 };
        constexpr units::inch_t kWheelDiameter { 6.0 };
        constexpr units::inch_t kTrackWidth { 24.0 }; // Maybe 
        constexpr units::volt_t kS { 0.8 }; // Inaccurate!
        constexpr units::unit_t<kv> kV { 0.246 }; // Inaccurate!
        constexpr units::unit_t<ka> kA { 0.0355 }; // Inaccurate!
        constexpr double kPDriveVel = 0.0;
        extern const frc::DifferentialDriveKinematics kDriveKinematics;
        extern const frc::TrajectoryConfig kAutoConfig;
        namespace auto_mode
        {
            constexpr units::feet_per_second_t kMaxVelocity { 2.0 };
            constexpr units::feet_per_second_squared_t kMaxAcceleration { 2.0 };
            constexpr double kRamseteB = 2.0;
            constexpr double kRamseteZeta = 0.7;
        }
    }
    namespace intake
    {
        constexpr int kIntakeMotorPort = 0; // Inaccurate!
        constexpr int kSolenoidPorts[2] = { 0, 0 }; // Inaccurate!
        constexpr units::current::ampere_t kMaxCurrentDraw { 25.0 };
        constexpr float kMotorOperatingPercentage = 0.8f; // 
        constexpr bool kStartSliderReversed = true;
    }
    namespace serializer
    {

    }
    namespace control_panel_manipulator
    {

    }
    namespace limelight
    {
        constexpr units::degree_t kCameraPitch { 30.0 };
    }
}
