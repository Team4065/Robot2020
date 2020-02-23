/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/LengthenWinch.h"

LengthenWinch::LengthenWinch(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void LengthenWinch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LengthenWinch::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "LengthenWinch Command Executing" << std::endl;
#endif 
  //Lift::GetInstance().LengthenWinch();
}

// Called once the command ends or is interrupted.
void LengthenWinch::End(bool interrupted) {
  //Lift::GetInstance().StopWinch();
}

// Returns true when the command should end.
bool LengthenWinch::IsFinished() { return false; }
