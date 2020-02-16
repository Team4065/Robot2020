#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));
  //intake_.SetDefaultCommand(Retract_and_DontSuck(intake_));
  // intake_.SetDefaultCommand(DontSuck(intake_));
  serializer_.SetDefaultCommand(VBeltOff(serializer_));
  shooter_.SetDefaultCommand(IdleShooter(shooter_));
  //lift_.SetDefaultCommand(LiftDefaultState(lift_));

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

  toggleIntakeDeploymentStateButton_.WhenPressed(DeployIntake(intake_));

  suckButton_.WhenHeld(Suck(intake_));

  intakeButton_.WhileHeld(CollectBalls(intake_, serializer_, shooter_));    //sfs: I don't think you want the operator to have to hold down the button to keep the intake deployed and/or spinning.

  shooterButton_.WhileHeld(SpinUp_and_Shoot(shooter_));   //sfs: You probably do want to force the operator to hold down the button to shoot so this is correct.
  //sfs: Do you want a way to adjust the shooter speed?

  //Spin Control Panel
  //sfs: Need a command to deploy control panel manipulator
  spinControlPanelButton_.WhenPressed(SpinControlPanel(controlPanelManipulator_));
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