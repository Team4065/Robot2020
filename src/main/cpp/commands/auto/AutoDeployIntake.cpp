/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoDeployIntake.h"

AutoDeployIntake::AutoDeployIntake(Intake& _intake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_intake});
}

// Called when the command is initially scheduled.
void AutoDeployIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoDeployIntake::Execute() {
  Intake::GetInstance().Extend();
}

// Called once the command ends or is interrupted.
void AutoDeployIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoDeployIntake::IsFinished() { return true; }
