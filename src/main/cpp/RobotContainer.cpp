#include "RobotContainer.h"
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
    Drivetrain::GetInstance().SetDefaultCommand(ArcadeTest(Drivetrain::GetInstance()));
    //Drivetrain::GetInstance().SetDefaultCommand(TankDrive(Drivetrain::GetInstance()));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  button.WhileHeld(ArcadeTest(Drivetrain::GetInstance()));
}

