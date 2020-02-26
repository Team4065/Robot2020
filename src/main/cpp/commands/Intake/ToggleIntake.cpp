/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/ToggleIntake.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ToggleIntake::ToggleIntake()
{
  AddRequirements({&Intake::GetInstance()});
}

// Called when the command is initially scheduled.
void ToggleIntake::Initialize()
{
  static Intake& instance_ = Intake::GetInstance();
  if (instance_.IsDeployed())
  {
    instance_.Retract();
    instance_.Idle();
  }
  else
  {
    instance_.Extend();
    instance_.Suck();
  }
}
