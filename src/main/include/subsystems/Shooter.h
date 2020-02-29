/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>

#include "util/ReferencedTunable.h"
#include "Constants.h"

using namespace constants::shooter;
using namespace rev;

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();


  float leftTarget = 0;
  float rightTarget = 0;
  float feederPercent = 0;
  float kickerPercent = 0;

  ctre::phoenix::motorcontrol::ControlMode controlMode;

 private:
  TalonFX leftFlywheel {kLeftMotorPort};
  TalonFX rightFlywheel {kRightMotorPort};

  CANSparkMax feederMotor {kFeederMotor1Port};
  CANSparkMax kickerMotor {kFeederMotor2Port};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
