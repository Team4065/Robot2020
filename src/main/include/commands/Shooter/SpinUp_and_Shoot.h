/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Shooter/Shoot.h"
#include "commands/Shooter/SpinUp.h"

#include "subsystems/Shooter.h"

class SpinUp_and_Shoot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 SpinUp_and_Shoot> {
 public:
  SpinUp_and_Shoot(Shooter& shooter);
};
