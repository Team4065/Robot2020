#include "subsystems/Intake.h"

Intake::Intake()
{
    roller_motor_.ConfigContinuousCurrentLimit(kMaxCurrentDraw.to<double>());
    roller_motor_.ConfigPeakCurrentLimit(kMaxCurrentDraw.to<double>());
    roller_motor_.EnableCurrentLimit(true);

    slider_solenoid_.Set(kStartSliderReversed ? frc::DoubleSolenoid::kReverse : frc::DoubleSolenoid::kForward);
}

void Intake::SetSliderState(SliderState state)
{
    slider_state_ = state;
}

void Intake::SetRollerState(RollerState state)
{
    roller_state_ = state;
}

Intake::SliderState Intake::GetSliderState() const
{
    return slider_state_;
}

Intake::RollerState Intake::GetRollerState() const
{
    return roller_state_;
}

bool Intake::RollerIsActive()
{
    return roller_state_ != IDLE;
}

bool Intake::SliderIsForward() const
{
    return slider_state_ == FORWARD;
}

void Intake::Periodic()
{
    switch(slider_state_)
    {
        case FORWARD:
            slider_solenoid_.Set(frc::DoubleSolenoid::kForward);
            break;
        case REVERSE:
            slider_solenoid_.Set(frc::DoubleSolenoid::kReverse);
            break;
        default:
            INFO_LOG("This should never be reached! Invalid state!");
    }
    switch(roller_state_)
    {
        case INTAKING:

    }
}

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

void Intake::Retract()
{
    is_deployed_ = false;
    solenoid_.Set(frc::DoubleSolenoid::kForward);
}

void Intake::Extend()
{
    is_deployed_ = true;
    solenoid_.Set(frc::DoubleSolenoid::kReverse);
}

bool Intake::IsActive() const
{
    return is_active_;
}

bool Intake::IsDeployed() const
{
    return is_deployed_;
}