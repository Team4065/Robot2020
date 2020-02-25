#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  lift_up_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  lift_down_btn_.WhenPressed(new MoveDown()).WhenReleased(new IdleLift());
  spinup_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  vbelt_.WhileHeld(new VBeltForward());
}