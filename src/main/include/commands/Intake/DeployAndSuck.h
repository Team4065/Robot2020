/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/PrintCommand.h>

#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/Suck.h"

class DeployAndSuck
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 DeployAndSuck> {
 public:
  DeployAndSuck(Intake& intake);
};
