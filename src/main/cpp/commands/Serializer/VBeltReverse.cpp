/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Serializer/VBeltReverse.h"

#include <iostream>

VBeltReverse::VBeltReverse(Serializer& serializer) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&serializer});
}

// Called when the command is initially scheduled.
void VBeltReverse::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VBeltReverse::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "VBeltReverse Command Executing" << std::endl;
#endif 
  //Serializer::GetInstance().Reverse();
}

// Called once the command ends or is interrupted.
void VBeltReverse::End(bool interrupted) {
  //Serializer::GetInstance().Off();
}

// Returns true when the command should end.
bool VBeltReverse::IsFinished() { return false; }
