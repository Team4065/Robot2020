/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoFeedFlywheel.h"

AutoFeedFlywheel::AutoFeedFlywheel(Shooter& _shooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_shooter});
}

// Called when the command is initially scheduled.
void AutoFeedFlywheel::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoFeedFlywheel::Execute() {
  Shooter::GetInstance().EngageFeeder();
  Shooter::GetInstance().EngageKicker();
  Shooter::GetInstance().SetShooterPercent(0.1);
}

// Called once the command ends or is interrupted.
void AutoFeedFlywheel::End(bool interrupted) {
    Shooter::GetInstance().DisableFeeder();
  Shooter::GetInstance().DisableKicker();
  Shooter::GetInstance().SetShooterPercent(0);
}

// Returns true when the command should end.
bool AutoFeedFlywheel::IsFinished() { return false; }
