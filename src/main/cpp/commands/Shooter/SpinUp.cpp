/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/SpinUp.h"

#include <iostream>

SpinUp::SpinUp(Shooter& shooter, units::revolutions_per_minute_t rpm): rpm_(rpm) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&shooter});
}

// Called when the command is initially scheduled.
void SpinUp::Initialize() {
  Shooter::GetInstance().SetVelocity(rpm_);
  Shooter::GetInstance().SetFeeder(true);
  Shooter::GetInstance().SetKicker(false);
}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute() {
  std::cout << "Shooter spinning up." << std::endl;
}

// Called once the command ends or is interrupted.
void SpinUp::End(bool interrupted) {
  // Shooter::GetInstance().SetVelocity(0);
  // Shooter::GetInstance().SetFeeder(false);
  // Shooter::GetInstance().SetKicker(false);
}

// Returns true when the command should end.
bool SpinUp::IsFinished() { return Shooter::GetInstance().GetVelocity < constants::shooter::kAllowableSpinupVelocityError; }
