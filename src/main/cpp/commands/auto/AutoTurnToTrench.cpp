/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoTurnToTrench.h"

AutoTurnToTrench::AutoTurnToTrench(Drivetrain& _drivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_drivetrain});
}

// Called when the command is initially scheduled.
void AutoTurnToTrench::Initialize() {
  Drivetrain::GetInstance().ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurnToTrench::Execute() {
  Drivetrain::GetInstance().TankDrivePercent(-0.1, 0.1);
}

// Called once the command ends or is interrupted.
void AutoTurnToTrench::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoTurnToTrench::IsFinished() { return abs((double)Drivetrain::GetInstance().GetHeading() - targetDirection ) <= allowableError; }
