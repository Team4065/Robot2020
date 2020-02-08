/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/AdjustRight.h"
#include <iostream>

AdjustRight::AdjustRight(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void AdjustRight::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AdjustRight::Execute() {
  std::cout << "Adjusting Right Lift" << std::endl;
  //Lift::GetInstance().MoveRight();
}

// Called once the command ends or is interrupted.
void AdjustRight::End(bool interrupted) {
  //Lift::GetInstance().DontMove();
}

// Returns true when the command should end.
bool AdjustRight::IsFinished() { return false; }
