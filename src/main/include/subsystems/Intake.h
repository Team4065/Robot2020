#pragma once

#include <frc2/command/SubsystemBase.h>
#include "util/Macros.h"

#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

#include <Constants.h>

using namespace constants::intake;

class Intake : public frc2::SubsystemBase
{
public:
  static Intake& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Intake);
  void Periodic();

  void Suck();
  void DontSuck();

  void Retract();
  void Extend();

  bool isDeployed = false;
private:
  Intake() = default;

  WPI_TalonSRX motor { kIntakeMotorID };
  frc::DoubleSolenoid leftSolenoid { kLeftSolenoidPorts[0], kLeftSolenoidPorts[1] };
  frc::DoubleSolenoid rightSolenoid { kRightSolenoidPorts[0], kRightSolenoidPorts[1] };


};
