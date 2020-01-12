#pragma once

#include <units/units.h>

namespace constants
{
    namespace shooter
    {
        constexpr int kLeftMotorPort = 1;
        constexpr int kRightMotorPort = 2;
        constexpr units::current::ampere_t kMaxCurrentDraw { 30 };
        constexpr double kP = 0.0;
        constexpr double kD = 0.0;
        constexpr double kFF = 0.0;
        constexpr units::inch_t kWheelRadius { 6.0 };
        constexpr double kAllowableVelocityError = 0.05; // 5% error
    }
    namespace drivetrain
    {
        constexpr int kLeftFrontMotorPort = 3;
        constexpr int kLeftMiddleMotorPort = 4;
        constexpr int kLeftRearMotorPort = 5;
        constexpr int kRightFrontMotorPort = 6;
        constexpr int kRightMiddleMotorPort = 7;
        constexpr int kRightRearMotorPort = 8;
    }
}