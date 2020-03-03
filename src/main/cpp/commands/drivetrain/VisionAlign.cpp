/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drivetrain/VisionAlign.h"
#include <iostream>

VisionAlign::VisionAlign() : pid_controller_(constants::limelight::kAlignKp, constants::limelight::kAlignKi, constants::limelight::kAlignKd)
{
  AddRequirements({ &Drivetrain::GetInstance(), &Vision::GetInstance() });
  pid_controller_.SetTolerance(constants::limelight::kOffsetTolerance.to<double>());
}

// Called when the command is initially scheduled.
void VisionAlign::Initialize()
{
  exit_flag_ = false;
  frc4065::Limelight* limelight_ = &Vision::GetInstance().GetLimelight();
  limelight_->SetPipeline(constants::limelight::pipes::TRACKING);
  limelight_->SetLEDMode(frc4065::Limelight::LEDMode::ON);
  limelight_->SetCamMode(frc4065::Limelight::CamMode::PROCESSING);
  if (!limelight_->HasActiveTarget())
  {
    frc2::CommandScheduler::GetInstance().Schedule(new BlinkVisionTimed(3_s));
    exit_flag_ = true;
  }
  else
  {
    pid_controller_.SetSetpoint(Drivetrain::GetInstance().GetHeading().to<double>() + limelight_->GetHorizontalOffset());
  }
}

// Called repeatedly when this Command is scheduled to run
void VisionAlign::Execute()
{
  double turn = pid_controller_.Calculate(Drivetrain::GetInstance().GetHeading().to<double>());
  std::cout << "Turn: " << turn << " Error: " << pid_controller_.GetPositionError() << " Offset: " << Drivetrain::GetInstance().GetHeading().to<double>() << std::endl;
  units::volt_t min_command_volts_ = constants::drivetrain::kMinTurnVoltage * ((turn > 0) ? 1 : -1);
  Drivetrain::GetInstance().TankDriveVolts(units::volt_t(turn) + min_command_volts_, -units::volt_t(turn) - min_command_volts_);
}

// Called once the command ends or is interrupted.
void VisionAlign::End(bool interrupted) {std::cout << "ending\n";}

// Returns true when the command should end.
bool VisionAlign::IsFinished() { return exit_flag_ /*|| pid_controller_.AtSetpoint()*/; }
