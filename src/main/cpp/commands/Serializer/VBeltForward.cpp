#include "commands/Serializer/VBeltForward.h"

#include <iostream>

VBeltForward::VBeltForward() {
  AddRequirements({&Serializer::GetInstance()});
}

// Called when the command is initially scheduled.
void VBeltForward::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VBeltForward::Execute() {
  Serializer::GetInstance().Forward();
  std::cout << "V-Belt forward." << std::endl;
}

// Called once the command ends or is interrupted.
void VBeltForward::End(bool interrupted) {
  Serializer::GetInstance().Idle();
}

// Returns true when the command should end.
bool VBeltForward::IsFinished() { return false; }
