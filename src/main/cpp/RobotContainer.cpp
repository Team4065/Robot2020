#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));
  intake_.SetDefaultCommand(IntakeDefaultState(intake_));
  lift_.SetDefaultCommand(LiftDefaultState(lift_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here 
  
  IntakeButton.ToggleWhenPressed(DeployAndSuck(intake_));

  ToggleLiftExtensionButton.ToggleWhenPressed(ExtendLift(lift_));
  LengthenWinchButton.WhenHeld(ShortenWinch(lift_));
  ShortenWinchButton.WhenHeld(LengthenWinch(lift_));
}