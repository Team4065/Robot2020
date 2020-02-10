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
  //Shooter::GetInstance().targetVelocity = value to be calculated or preset
}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute() {
  std::cout << "Shooter spinning up." << std::endl;
}

// Called once the command ends or is interrupted.
void SpinUp::End(bool interrupted) {
  //Shooter::GetInstance().targetVelocity = 0;
  //Shooter::GetInstance().isFeeder1On = false;
  //Shooter::GetInstance().isFeeder2On = false;
}

// Returns true when the command should end.
bool SpinUp::IsFinished() { return constants::shooter::kAllowableVelocityError > abs(Shooter::GetInstance().GetSensorVelocity() - Shooter::GetInstance().targetVelocity); }
