#include "commands/BlinkVisionTimed.h"

BlinkVisionTimed::BlinkVisionTimed(units::second_t time) : time_(time)
{
  AddRequirements({ &Vision::GetInstance() });
}

// Called when the command is initially scheduled.
void BlinkVisionTimed::Initialize()
{
  start_time_ = units::second_t(frc::Timer::GetFPGATimestamp());
  Vision::GetInstance().GetLimelight().SetLEDMode(frc4065::Limelight::LEDMode::BLINKING);
}

void BlinkVisionTimed::Execute() {}

void BlinkVisionTimed::End(bool interrupted)
{
  Vision::GetInstance().GetLimelight().SetLEDMode(frc4065::Limelight::LEDMode::ON);
}

// Returns true when the command should end.
bool BlinkVisionTimed::IsFinished() { return frc::Timer::GetFPGATimestamp() - start_time_.to<double>() >= time_.to<double>(); }
