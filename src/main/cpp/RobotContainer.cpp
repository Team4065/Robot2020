#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));
  intake_.SetDefaultCommand(DontSuck(intake_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here 
  SuckButton.WhenHeld(Suck(intake_));
  ToggleIntakeDeploymentStateButton.WhenPressed(DeployIntake(intake_));
}