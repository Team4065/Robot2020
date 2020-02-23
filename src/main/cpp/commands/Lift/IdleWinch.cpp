/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/IdleWinch.h"

IdleWinch::IdleWinch(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void IdleWinch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IdleWinch::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "IdleWinch Command Executing" << std::endl;
#endif 
  //Lift::GetInstance().StopWinch();
}

// Called once the command ends or is interrupted.
void IdleWinch::End(bool interrupted) {}

// Returns true when the command should end.
bool IdleWinch::IsFinished() { return false; }
