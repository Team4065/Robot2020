#include "commands/shooter/TimedShoot.h"
#include <iostream>

TimedShoot::TimedShoot(units::revolutions_per_minute_t rpm, units::second_t time)
  : rpm_(rpm), time_(time), start_time_(units::second_t(frc::Timer::GetFPGATimestamp()))
{
  AddRequirements({&Shooter::GetInstance(), &Serializer::GetInstance()});
}

void TimedShoot::Initialize()
{
  Shooter::GetInstance().SetShooterVelocity(rpm_);
  std::cout << "Starting!\n";
  timer_started_ = false;
}

void TimedShoot::Execute()
{
  if (Shooter::GetInstance().AtDesiredVelocity() && !hysteresis_flag_)
  {
    if (!timer_started_)
    {
      timer_.Start();
      timer_started_ = true;
    }
    Shooter::GetInstance().EngageFeeder();
    Shooter::GetInstance().EngageKicker();
    Serializer::GetInstance().Forward();
  }
  if (!Shooter::GetInstance().AtDesiredVelocityWithHysteresis() && hysteresis_flag_)
  {
    Serializer::GetInstance().Idle();
    Shooter::GetInstance().DisableFeeder();
    Shooter::GetInstance().DisableKicker();
  }
}

// Called once the command ends or is interrupted.
void TimedShoot::End(bool interrupted)
{
  Shooter::GetInstance().DisableFeeder();
  Shooter::GetInstance().DisableKicker();
  Serializer::GetInstance().Idle();
  Shooter::GetInstance().SetShooterVelocity(0.0_rpm);
  std::cout << "Ending!\n";
}

// Returns true when the command should end.
bool TimedShoot::IsFinished()
{
  std::cout << (units::second_t(frc::Timer::GetFPGATimestamp()) - start_time_).to<double>() << std::endl;
  // return units::second_t(frc::Timer::GetFPGATimestamp()) - start_time_ >= time_;
  return timer_.HasPeriodPassed(time_.to<double>());
}
