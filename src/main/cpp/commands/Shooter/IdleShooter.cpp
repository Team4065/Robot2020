/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/IdleShooter.h"

#include <iostream>

IdleShooter::IdleShooter(Shooter& shooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&shooter});
}

// Called when the command is initially scheduled.
void IdleShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IdleShooter::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "IdleShooter Command Executing" << std::endl;
#endif
  // Shooter::GetInstance().targetVelocity = 0;
  // Shooter::GetInstance().isFeeder1On = false;
  // Shooter::GetInstance().isFeeder2On = false;
}

// Called once the command ends or is interrupted.
void IdleShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool IdleShooter::IsFinished() { return false; }
