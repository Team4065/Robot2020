/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "subsystems/Intake.h"
#include "subsystems/Serializer.h"
#include "subsystems/Shooter.h"

#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/Suck.h"
#include "commands/Intake/Deploy_and_Suck.h"
#include "commands/Serializer/VBeltForward.h"
#include "commands/Shooter/Preload.h"

class CollectBalls
    : public frc2::CommandHelper<frc2::ParallelCommandGroup, CollectBalls> {
 public:
  CollectBalls(Intake& intake, Serializer& serializer, Shooter& shooter);
  CollectBalls(DeployIntake& deployintake, Suck& suck, VBeltForward& vBeltForwardCommand, Preload& preloadCommand);  
};
