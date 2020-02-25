/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drivetrain/VisionAlign.h"

VisionAlign::VisionAlign() : pid_controller_(constants::limelight::kAlignKp, constants::limelight::kAlignKi, constants::limelight::kAlignKd)
{
  AddRequirements({ &Drivetrain::GetInstance(), &Vision::GetInstance() });
}

// Called when the command is initially scheduled.
void VisionAlign::Initialize()
{
  frc4065::Limelight* limelight_ = &Vision::GetInstance().GetLimelight();
  if (!limelight_->HasActiveTarget())
  {
    
    exit_flag_ = true;
  }
  else
  {
    limelight_->SetLEDMode(frc4065::Limelight::LEDMode::ON);
  }
}

// Called repeatedly when this Command is scheduled to run
void VisionAlign::Execute() {}

// Called once the command ends or is interrupted.
void VisionAlign::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionAlign::IsFinished() { return exit_flag_; }
