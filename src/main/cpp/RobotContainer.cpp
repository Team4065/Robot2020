#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));
  intake_.SetDefaultCommand(DontSuck(intake_));
  lift_.SetDefaultCommand(RetractLift(lift_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here 
  SpinControlPanelButton.WhenPressed(SpinControlPanel(control_panel_manipulator_));
  SuckButton.WhenHeld(Suck(intake_));
  ToggleIntakeDeploymentStateButton.WhenPressed(DeployIntake(intake_));
}