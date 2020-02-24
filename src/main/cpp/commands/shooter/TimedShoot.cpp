#include "commands/shooter/TimedShoot.h"

TimedShoot::TimedShoot(units::revolutions_per_minute_t rpm, units::second_t time)
  : rpm_(rpm), time_(time), start_time_(units::second_t(frc::Timer::GetFPGATimestamp()))
{
  AddRequirements({&Shooter::GetInstance()});
}

void TimedShoot::Initialize()
{
  Shooter::GetInstance().SetShooterVelocity(rpm_);
}

void TimedShoot::Execute()
{
  if (Shooter::GetInstance().AtDesiredVelocity() && !hysteresis_flag_)
  {
    Shooter::GetInstance().EngageFeeder();
    Shooter::GetInstance().EngageKicker();
  }
  if (!Shooter::GetInstance().AtDesiredVelocityWithHysteresis() && hysteresis_flag_)
  {
    Shooter::GetInstance().DisableFeeder();
    Shooter::GetInstance().DisableKicker();
  }
}

// Called once the command ends or is interrupted.
void TimedShoot::End(bool interrupted)
{
  Shooter::GetInstance().DisableFeeder();
  Shooter::GetInstance().DisableKicker();
  Shooter::GetInstance().SetShooterVelocity(0.0_rpm);
}

// Returns true when the command should end.
bool TimedShoot::IsFinished() { return (units::second_t(frc::Timer::GetFPGATimestamp()) - start_time_) < time_; }
