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
  pid_controller_.SetTolerance(constants::limelight::kOffsetTolerance.to<double>());
}

// Called when the command is initially scheduled.
void VisionAlign::Initialize()
{
  frc4065::Limelight* limelight_ = &Vision::GetInstance().GetLimelight();
  limelight_->SetLEDMode(frc4065::Limelight::LEDMode::ON);
  limelight_->SetCamMode(frc4065::Limelight::CamMode::PROCESSING);
  Drivetrain::GetInstance().TankDrivePercent(0.0, 0.0);
  if (!limelight_->HasActiveTarget())
  {
    frc2::CommandScheduler::GetInstance().Schedule(new BlinkVisionTimed(3_s));
    exit_flag_ = true;
  }
  pid_controller_.SetSetpoint(Drivetrain::GetInstance().GetHeading().to<double>() + limelight_->GetHorizontalOffset());
}

// Called repeatedly when this Command is scheduled to run
void VisionAlign::Execute()
{
  double turn = pid_controller_.Calculate(Drivetrain::GetInstance().GetHeading().to<double>());
  Drivetrain::GetInstance().TankDrivePercent(turn, -turn);
}

// Called once the command ends or is interrupted.
void VisionAlign::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionAlign::IsFinished() { return exit_flag_ || pid_controller_.AtSetpoint(); }
