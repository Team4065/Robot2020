#pragma once

#include <frc2/command/SubsystemBase.h>
#include "util/Macros.h"

#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

#include "Constants.h"

using namespace constants::intake;

class Intake : public frc2::SubsystemBase
{
public:
  static Intake& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Intake);
  void Periodic();

  void Suck();
  void Idle();
  void Retract();
  void Extend();

  bool IsActive() const;
  bool IsDeployed() const;

  bool is_active_ = false;
  bool is_deployed_ = false;
private:
  Intake() = default;

  TalonSRX motor_ { kIntakeMotorID };
  frc::DoubleSolenoid solenoid_ { kSolenoidPorts[0], kSolenoidPorts[1] };
};
