/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Filler.h"

Filler::Filler() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Filler::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Filler::Execute() {}

// Called once the command ends or is interrupted.
void Filler::End(bool interrupted) {}

// Returns true when the command should end.
bool Filler::IsFinished() { return false; }
