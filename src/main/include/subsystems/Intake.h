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

  bool IsDeployed(){return m_isDeployed;}
 
private:
  bool m_isDeployed = false;

  Intake() = default;

  WPI_TalonSRX m_motor { kIntakeMotorID };
  double m_motorSpeed = 0;

  frc::DoubleSolenoid m_solenoid { constants::intake::kSolenoidPorts[0], constants::intake::kSolenoidPorts[1] };
  //frc::DoubleSolenoid rightSolenoid { kRightSolenoidPorts[0], kRightSolenoidPorts[1] };


};
