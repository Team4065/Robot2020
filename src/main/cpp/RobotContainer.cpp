#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  y_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  a_btn_.WhenPressed(new MoveDown()).WhenReleased(new IdleLift());
  x_btn_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  b_btn_.WhenPressed(new PreSpinup(60_rpm)).WhenReleased(new PreSpinup(0_rpm));

  Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller_));
}