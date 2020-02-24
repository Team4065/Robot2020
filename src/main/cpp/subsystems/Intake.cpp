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
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}