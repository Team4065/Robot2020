#include "subsystems/Intake.h"

Intake::Intake()
{
    solenoid_.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Intake::Periodic()
{}

Intake& Intake::GetInstance()
{
    static Intake instance;
    return instance;
}

void Intake::Suck()
{
    is_active_ = true;
    motor_.Set(ControlMode::PercentOutput, constants::intake::kMotorOperatingPercentage);
}

void Intake::Idle()
{
    is_active_ = false;
    motor_.Set(ControlMode::PercentOutput, 0.0);
}

void Intake::Reverse()
{
    is_active_ = true;
    motor_.Set(ControlMode::PercentOutput, -0.15);
}

void Intake::Retract()
{
    is_deployed_ = false;
    solenoid_.Set(frc::DoubleSolenoid::kReverse);
}

void Intake::Extend()
{
    is_deployed_ = true;
    solenoid_.Set(frc::DoubleSolenoid::kForward);
}

bool Intake::IsActive() const
{
    return is_active_;
}

bool Intake::IsDeployed() const
{
    return is_deployed_;
}