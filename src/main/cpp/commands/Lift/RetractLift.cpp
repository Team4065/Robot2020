/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/RetractLift.h"

RetractLift::RetractLift(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void RetractLift::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RetractLift::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "RetractLift Command Executing" << std::endl;
#endif 
  //Lift::GetInstance().Retract();
}

// Called once the command ends or is interrupted.
void RetractLift::End(bool interrupted) {}

// Returns true when the command should end.
bool RetractLift::IsFinished() { return false; }
