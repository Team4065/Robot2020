/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoLimelightOn.h"

AutoLimelightOn::AutoLimelightOn(Drivetrain& _drivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_drivetrain});
}

// Called when the command is initially scheduled.
void AutoLimelightOn::Initialize() {
  pastError = Drivetrain::GetInstance().limelight.GetHorizontalOffset();
}

// Called repeatedly when this Command is scheduled to run
void AutoLimelightOn::Execute() {
  double xOff = Drivetrain::GetInstance().limelight.GetHorizontalOffset();

  error = xOff;
  double deltaError = pastError - error;
  pastError = error;

  double leftOutput = xOff * kp + deltaError * kd;

  Drivetrain::GetInstance().TankDrivePercent(leftOutput, -leftOutput);

}

// Called once the command ends or is interrupted.
void AutoLimelightOn::End(bool interrupted) {
  Drivetrain::GetInstance().TankDrivePercent(0, 0);
}

// Returns true when the command should end.
bool AutoLimelightOn::IsFinished() { return error <= 1; }
