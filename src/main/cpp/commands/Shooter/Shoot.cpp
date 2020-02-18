/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/Shoot.h"

Shoot::Shoot(Shooter& shooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&shooter});
}

// Called when the command is initially scheduled.
void Shoot::Initialize() {
  Shooter::GetInstance().SetVelocity();
  Shooter::GetInstance().SetFeeder(true);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
  std::cout << "Is shooting." << std::endl;
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {
  Shooter::GetInstance().SetVelocity(0);
  Shooter::GetInstance().SetFeeder();
  Shooter::GetInstance().SetKicker();
}

// Returns true when the command should end.
bool Shoot::IsFinished() { return false; }
