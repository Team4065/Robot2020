/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/PreSpinup.h"

PreSpinup::PreSpinup(units::revolutions_per_minute_t rpm) : rpm_(rpm)
{
  AddRequirements({&Shooter::GetInstance()});
}

void PreSpinup::Initialize()
{
  Shooter::GetInstance().SetShooterVelocity(rpm_);
}

void PreSpinup::Execute() {}

void PreSpinup::End(bool interrupted) {}

// Returns true when the command should end.
bool PreSpinup::IsFinished() { return Shooter::GetInstance().AtDesiredVelocity(); }
