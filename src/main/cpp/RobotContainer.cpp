#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  y_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  a_btn_.WhenPressed(new MoveDown()).WhenReleased(new IdleLift());
  //x_btn_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  x_btn_.WhenPressed(new VBeltForward()).WhenReleased(new VBeltOff());
  b_btn_.WhenPressed(new TimedShoot(4000_rpm, 5_s));
  rb_btn_.WhenPressed(new ToggleIntake());

  Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller_));
}