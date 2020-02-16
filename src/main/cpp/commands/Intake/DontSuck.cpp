/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/DontSuck.h"

DontSuck::DontSuck(Intake& intake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&intake});
}

// Called when the command is initially scheduled.
void DontSuck::Initialize() {
  //Intake::GetInstance().DontSuck();
}

// Called repeatedly when this Command is scheduled to run
void DontSuck::Execute() {
  Intake::GetInstance().DontSuck();
  // std::cout << "Dont Suck" << std::endl;
}

// Called once the command ends or is interrupted.
void DontSuck::End(bool interrupted) {}

// Returns true when the command should end.
bool DontSuck::IsFinished() { return true; }
