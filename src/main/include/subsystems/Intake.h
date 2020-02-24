#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DoubleSolenoid.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <ctre/Phoenix.h>

#include "Constants.h"
#include "util/Macros.h"

using namespace ctre::phoenix::motorcontrol::can;
using namespace constants::intake;
class Intake : public frc2::SubsystemBase
{
public:
  enum SliderState { FORWARD, REVERSE };
  enum RollerState { IDLE, INTAKING };

  void SetSliderState(SliderState state);
  void SetRollerState(RollerState state);

  SliderState GetSliderState() const;
  RollerState GetRollerState() const;
  bool RollerIsActive();
  bool SliderIsForward() const;

  static Intake& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Intake);
  void Periodic();
private:
  Intake() = default;

  SliderState slider_state_ = kStartSliderReversed ? REVERSE : FORWARD;
  RollerState roller_state_ = IDLE;

  frc::DoubleSolenoid slider_solenoid_ { constants::intake::kSolenoidPorts[0], constants::intake::kSolenoidPorts[1] };
  TalonSRX roller_motor_ { constants::intake::kIntakeMotorPort };

};
