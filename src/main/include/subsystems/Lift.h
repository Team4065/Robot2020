/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DoubleSolenoid.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>

#include <Constants.h>

using namespace constants::lift;

class Lift : public frc2::SubsystemBase {
 public:
  Lift();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void Extend();
  void Retract();

  void ShortenWinch();
  void LengthenWinch();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::DoubleSolenoid left { kLeftSolenoidPorts[0], kLeftSolenoidPorts[1] };
  frc::DoubleSolenoid right { kRightSolenoidPorts[0], kRightSolenoidPorts[1] };

  rev::CANSparkMax motor { kMotorPorts[0], rev::CANSparkMax::MotorType::kBrushless};
};
