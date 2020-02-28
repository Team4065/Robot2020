/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoDropLift.h"

AutoDropLift::AutoDropLift(Lift& _lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_lift});
}

// Called when the command is initially scheduled.
void AutoDropLift::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoDropLift::Execute() {
  Lift::GetInstance().Retract();
}

// Called once the command ends or is interrupted.
void AutoDropLift::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoDropLift::IsFinished() { return true; }
