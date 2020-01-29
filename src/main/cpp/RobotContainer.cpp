#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here 
}