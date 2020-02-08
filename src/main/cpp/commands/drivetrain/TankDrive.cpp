/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drivetrain/TankDrive.h"

TankDrive::TankDrive(Drivetrain& _drivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&_drivetrain});
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  std::cout << "Tank Drive" << std::endl;
  //Drivetrain::SetLeft(controller.GetY(frc::XboxController::kLeftHand) * constants::drivetrain::kVelocityRange);
  //Drivetrain::SetRight(controller.GetY(frc::XboxController::kRightHand) * constants::drivetrain::kVelocityRange);
  //Drivetrain::SetLeft(0);
  //Drivetrain::SetRight(0);
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() { return false; }
