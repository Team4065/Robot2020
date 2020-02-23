/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/DeployIntake.h"

DeployIntake::DeployIntake(Intake& intake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&intake});
}

// Called when the command is initially scheduled.
void DeployIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DeployIntake::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "DeployIntake Command Executing" << std::endl;
#endif 
  Intake::GetInstance().Extend();
}

// Called once the command ends or is interrupted.
void DeployIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool DeployIntake::IsFinished() { return true; }
