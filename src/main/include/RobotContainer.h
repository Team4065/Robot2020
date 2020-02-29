#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/buttons/Trigger.h>

#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"


#include "frc2/command/button/JoystickButton.h"


#include "Constants.h"

class RobotContainer
{
public:
  RobotContainer();

private:

  void ConfigureButtonBindings();
};
