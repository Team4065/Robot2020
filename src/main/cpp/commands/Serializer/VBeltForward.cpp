/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Serializer/VBeltForward.h"

#include <iostream>

VBeltForward::VBeltForward(Serializer& serializer) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&serializer});
}

// Called when the command is initially scheduled.
void VBeltForward::Initialize() {
  // Serializer::GetInstance().Forward();
}

// Called repeatedly when this Command is scheduled to run
void VBeltForward::Execute() {
  Serializer::GetInstance().Forward();
  // std::cout << "V-Belt forward." << std::endl;
}

// Called once the command ends or is interrupted.
void VBeltForward::End(bool interrupted) {
  //Serializer::GetInstance().Off();
}

// Returns true when the command should end.
bool VBeltForward::IsFinished() { return true; }
