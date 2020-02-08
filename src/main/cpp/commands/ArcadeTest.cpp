/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArcadeTest.h"
#include <iostream>

ArcadeTest::ArcadeTest(Drivetrain& drivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&drivetrain});
}

// Called when the command is initially scheduled.
void ArcadeTest::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArcadeTest::Execute() {
  std::cout << controller.GetY(frc::GenericHID::kLeftHand) << std::endl;
  Drivetrain::GetInstance().left_front_master_.Set(ControlMode::PercentOutput, controller.GetY(frc::GenericHID::kLeftHand) + controller.GetX(frc::GenericHID::kRightHand));
  Drivetrain::GetInstance().right_front_master_.Set(ControlMode::PercentOutput, controller.GetY(frc::GenericHID::kLeftHand) - controller.GetX(frc::GenericHID::kRightHand));
}

// Called once the command ends or is interrupted.
void ArcadeTest::End(bool interrupted) {}

// Returns true when the command should end.
bool ArcadeTest::IsFinished() { return false; }
