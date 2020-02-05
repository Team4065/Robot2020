/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>

using namespace constants::winch;

class Winch : public frc2::SubsystemBase {
 public:
  static Winch& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Winch);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void MoveRight();
  void DontMove();
  void MoveLeft();

 private:
  Winch() = default;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax motor { kMotorPorts[0], rev::CANSparkMax::MotorType::kBrushless};
};
