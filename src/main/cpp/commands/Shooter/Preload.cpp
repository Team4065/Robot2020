/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/Preload.h"

#include <iostream>

Preload::Preload(Shooter& shooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&shooter});
}

// Called when the command is initially scheduled.
void Preload::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Preload::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "Preload Command Executing" << std::endl;
#endif
  //Shooter::GetInstance().isFeeder1On = true;
}

// Called once the command ends or is interrupted.
void Preload::End(bool interrupted) {}

// Returns true when the command should end.
bool Preload::IsFinished() { return false; }
