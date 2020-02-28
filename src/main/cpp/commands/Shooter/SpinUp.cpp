/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/SpinUp.h"

#include <iostream>

SpinUp::SpinUp(Shooter& shooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&shooter});
}

// Called when the command is initially scheduled.
void SpinUp::Initialize() {
  spinUpCounts_ = 0;
}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "SpinUp Command Executing" << std::endl;
#endif
  Shooter::GetInstance().EngageFeeder();
  Shooter::GetInstance().SetShooterPercent(0.5);
  spinUpCounts_++;
}

// Called once the command ends or is interrupted.
void SpinUp::End(bool interrupted) {
}

// Returns true when the command should end.
bool SpinUp::IsFinished() { return  (spinUpCounts_ > 50);}
