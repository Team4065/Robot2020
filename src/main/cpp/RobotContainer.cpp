#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{
  Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // y_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  y_btn_.WhileHeld(new MoveUp()).WhenReleased(new IdleLift());
  a_btn_.WhileHeld(new MoveDown()).WhenReleased(new IdleLift());
  // y_btn_.WhileHeld(new MoveUp());
  // a_btn_.WhileHeld(new MoveDown());
  //x_btn_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  x_btn_.WhenPressed(new VBeltForward()).WhenReleased(new VBeltOff());
  b_btn_.WhenPressed(new ToggleLiftPiston());
  rb_btn_.WhenPressed(new ToggleIntake());
  //lb_btn_.WhenPressed(new TimedShoot(4000_rpm, 6_s));
  lb_btn_.WhileHeld(new TimedShoot(4000_rpm, 10_s));
  // sl_btn_.WhenPressed();
  // sr_btn_.WhenPressed();
  start_btn_.WhenPressed(new VisionAlign());
  // back_btn_.WhenPressed();
  // lt_btn_.WhenPressed();
  // rt_btn_.WhenPressed();


  
}