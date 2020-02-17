#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  //Drivetrain (Non Default Commands)
  //sfs: You may want a slower drivetrain for lining up shoots.
  //sfs: You could use a button to toggle in and out of a slower response drivetrain mode

  //Capture & Shoot Balls
  collectBallsButton_.WhenPressed(CollectBalls(intake_, serializer_, shooter_));
  collectBallsButton_.WhenReleased(DontSuck(intake_));
  retractIntakeButton_.WhenPressed(RetractIntake(intake_));

  shooterButton_.WhileHeld(SpinUp_and_Shoot(shooter_));
  //sfs: Do you want a way to adjust the shooter speed?

  //Spin Control Panel
  //sfs: Need a command to deploy control panel manipulator
  toggleCPMDeploymentButton_.WhenPressed(SpinControlPanel(controlPanelManipulator_));
  //sfs: Need manual control of the control panel spinning, this is in addition to the fixed revolutions control.
  //sfs: Do we want to have an automatic mode to move the control panel to a particular color?

  //Lift & Balance
  //sfs: Deploy (Extend) Lift
  //ToggleLiftExtensionButton.ToggleWhenPressed(ExtendLift(lift_));
  //sfs: Raise Robot
  //LengthenWinchButton.WhenHeld(ShortenWinch(lift_));
  //ShortenWinchButton.WhenHeld(LengthenWinch(lift_));
  //sfs: Balance Activator Switch (Balance on bar)  
  
}