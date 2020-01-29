#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "subsystems/Shooter.h"
#include "subsystems/Serializer.h"
#include "subsystems/Intake.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/ControlPanelManipulator.h"

#include "commands/drivetrain/TankDrive.h"

#include "Constants.h"

class RobotContainer
{
public:
  RobotContainer();

private:
  Shooter& shooter_ = Shooter::GetInstance();
  Serializer& serializer_ = Serializer::GetInstance();
  Intake& intake_ = Intake::GetInstance();
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  ControlPanelManipulator& control_panel_manipulator_ = ControlPanelManipulator::GetInstance();

  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };

  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
