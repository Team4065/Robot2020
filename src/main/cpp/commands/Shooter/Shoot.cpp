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
void Shoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "Shoot Command Executing" << std::endl;
#endif
  double shooterPercentage;
  frc4065::ReferencedTunable::Register("Shooter Percentage", shooterPercentage);
  Shooter::GetInstance().EngageFeeder();
  Shooter::GetInstance().EngageKicker();
  Shooter::GetInstance().SetShooterPercent(shooterPercentage);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {
  Shooter::GetInstance().DisableFeeder();
  Shooter::GetInstance().DisableKicker();
  Shooter::GetInstance().SetShooterPercent(0.0);
}

// Returns true when the command should end.
bool Shoot::IsFinished() { return false; }
