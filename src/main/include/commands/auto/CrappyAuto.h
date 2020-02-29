/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <commands/auto/AutoDeployIntake.h>
#include <commands/auto/AutoDriveForward.h>
#include <commands/auto/AutoDropLift.h>
#include <commands/auto/AutoFeedFlywheel.h>
#include <commands/auto/AutoLimelightOn.h>
#include <commands/auto/AutoRunIntake.h>
#include <commands/auto/AutoSpinupFlywheel.h>
#include <commands/auto/AutoTurnToTrench.h>

class CrappyAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 CrappyAuto> {
 public:
  CrappyAuto();
};
