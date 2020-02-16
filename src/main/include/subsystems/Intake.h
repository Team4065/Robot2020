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
 
private:
  bool isDeployed_ = false;

  Intake() = default;

  WPI_TalonSRX motor_ { kIntakeMotorID };
  double motorSpeed_ = 0;

  frc::DoubleSolenoid solenoid_ { kSolenoidPorts[0], kSolenoidPorts[1] };
  //frc::DoubleSolenoid rightSolenoid { kRightSolenoidPorts[0], kRightSolenoidPorts[1] };


};
