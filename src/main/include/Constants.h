#pragma once

#include <units/units.h>

namespace constants
{
using Velocity = units::compound_unit<units::length::feet, units::inverse<units::seconds>>;
using Acceleration = units::compound_unit<Velocity, units::inverse<units::seconds>>;
using kv = units::compound_unit<units::volts, units::inverse<Velocity>>;
using ka = units::compound_unit<units::volts, units::inverse<Acceleration>>;
namespace shooter
{
constexpr int kLeftMotorPort = 1;
constexpr int kRightMotorPort = 2;
constexpr units::current::ampere_t kMaxCurrentDraw{30.0};
constexpr double kP = 0.0;
constexpr double kD = 0.0;
constexpr double kFF = 0.0;
constexpr units::inch_t kWheelDiameter{6.0};
constexpr double kAllowableVelocityError = 0.05; // 5% error
} // namespace shooter
namespace drivetrain
{
constexpr int kLeftFrontMotorPort = 3;   // Inaccurate!
constexpr int kLeftMiddleMotorPort = 4;  // Inaccurate!
constexpr int kLeftRearMotorPort = 5;    // Inaccurate!
constexpr int kRightFrontMotorPort = 6;  // Inaccurate!
constexpr int kRightMiddleMotorPort = 7; // Inaccurate!
constexpr int kRightRearMotorPort = 8;   // Inaccurate!
constexpr units::current::ampere_t kMaxCurrentDraw{30.0};
constexpr units::inch_t kWheelDiameter{6.0};
constexpr units::inch_t kWheelBase{28.0}; // Maybe
constexpr units::volt_t kS{0.0};          // Inaccurate!
constexpr units::unit_t<kv> kV{0.0};      // Inaccurate!
constexpr units::unit_t<ka> kA{0.0};      // Inaccurate!
namespace auto_mode
{
constexpr units::feet_per_second_t kMaxVelocity{10.0};
constexpr units::feet_per_second_squared_t kMaxAcceleration{6.0};
constexpr double kRamseteB = 2.0;
constexpr double kRamseteZeta = 0.7;
} // namespace auto_mode
} // namespace drivetrain
namespace intake
{
constexpr int kIntakeMotorPort = 0;            // Inaccurate!
constexpr int kLeftSolenoidPorts[2] = {0, 0};  // Inaccurate!
constexpr int kRightSolenoidPorts[2] = {0, 0}; // Inaccurate!
constexpr units::current::ampere_t kMaxCurrentDraw{25.0};
constexpr float kMotorOperatingPercentage = 0.8f; //
} // namespace intake
namespace serializer
{
}
namespace control_panel_manipulator
{
}
namespace limelight
{
    constexpr double kP = 0.0;
    constexpr double kI = 0.0;
    constexpr double kD = 0.0;
} 