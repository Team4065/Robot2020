#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  drivetrain_.SetDefaultCommand(TankDrive(drivetrain_));
  intake_.SetDefaultCommand(Retract_and_DontSuck(intake_));
  serializer_.SetDefaultCommand(VBeltOff(serializer_));
  shooter_.SetDefaultCommand(IdleShooter(shooter_));
  //lift_.SetDefaultCommand(LiftDefaultState(lift_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here 

  intakeButton.WhileHeld(CollectBalls(intake_, serializer_, shooter_));
  shooterButton.WhileHeld(SpinUp_and_Shoot(shooter_));


  //ToggleLiftExtensionButton.ToggleWhenPressed(ExtendLift(lift_));
  //LengthenWinchButton.WhenHeld(ShortenWinch(lift_));
  //ShortenWinchButton.WhenHeld(LengthenWinch(lift_));
}