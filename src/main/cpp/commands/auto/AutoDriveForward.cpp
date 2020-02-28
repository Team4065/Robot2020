/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoDriveForward.h"

AutoDriveForward::AutoDriveForward(Drivetrain& _drivetrain, double _distance) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_drivetrain});
  distance = _distance;
}

// Called when the command is initially scheduled.
void AutoDriveForward::Initialize() {
  Drivetrain::GetInstance().ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
  Drivetrain::GetInstance().TankDrivePercent(0.1, 0.1);
}

// Called once the command ends or is interrupted.
void AutoDriveForward::End(bool interrupted) {
  Drivetrain::GetInstance().TankDrivePercent(0, 0);
}

// Returns true when the command should end.
bool AutoDriveForward::IsFinished() { return abs((double)Drivetrain::GetInstance().GetLeftEncoderDistance() - distance) < 0.1 || abs((double)Drivetrain::GetInstance().GetRightEncoderDistance() - distance) < 0.1; }
