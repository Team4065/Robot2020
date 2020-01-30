#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Constants.h"

class RobotContainer
{
public:
  RobotContainer();

private:

  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
