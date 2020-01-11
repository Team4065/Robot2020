#include "RobotContainer.h"
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  Drivetrain::GetInstance().SetDefaultCommand(TankDrive(Drivetrain::GetInstance(), controller));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

