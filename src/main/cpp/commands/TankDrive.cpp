/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TankDrive.h"
#include <iostream>

TankDrive::TankDrive(Drivetrain& drivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&drivetrain});
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {
  Drivetrain::GetInstance().state.driveMode = Drivetrain::DriveMode::DRIVER;
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  Drivetrain::GetInstance().state.leftSpeedTarget = controller.GetY(frc::XboxController::JoystickHand::kLeftHand);
  Drivetrain::GetInstance().state.rightSpeedTarget = controller.GetY(frc::XboxController::JoystickHand::kRightHand);
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() { return false; }
