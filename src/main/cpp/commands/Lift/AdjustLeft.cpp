/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/AdjustLeft.h"
#include <iostream>

AdjustLeft::AdjustLeft(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void AdjustLeft::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AdjustLeft::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "AdjustLeft Command Executing" << std::endl;
#endif   
  //Lift::GetInstance().MoveLeft();
}

// Called once the command ends or is interrupted.
void AdjustLeft::End(bool interrupted) {
}

// Returns true when the command should end.
bool AdjustLeft::IsFinished() { return false; }
