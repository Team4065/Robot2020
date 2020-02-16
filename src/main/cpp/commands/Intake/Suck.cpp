/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/Suck.h"

Suck::Suck(Intake& intake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&intake});
}

// Called when the command is initially scheduled.
void Suck::Initialize() {
  // Intake::GetInstance().Suck();
}

// Called repeatedly when this Command is scheduled to run
void Suck::Execute() {
  Intake::GetInstance().Suck();
  // std::cout << "Suck" << std::endl;
}

// Called once the command ends or is interrupted.
void Suck::End(bool interrupted) {
  //Intake::GetInstance().DontSuck();
}

// Returns true when the command should end.
bool Suck::IsFinished() { return true; }
