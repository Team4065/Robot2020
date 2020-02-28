/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Lift.h"

#include <units/units.h>

/**
 * Set lift to height and ends when lift reaches height
 */
class MoveLiftToHeight
    : public frc2::CommandHelper<frc2::CommandBase, MoveLiftToHeight> {
public:
  MoveLiftToHeight(units::foot_t height);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  units::foot_t height_;
};
