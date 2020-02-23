/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>
#include <Constants.h>

#include "subsystems/Drivetrain.h"

/**
 * NOTE: This class is NOT finished.
 */

class TankDrive
    : public frc2::CommandHelper<frc2::CommandBase, TankDrive> {
public:
  TankDrive(Drivetrain&);
  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;
};
