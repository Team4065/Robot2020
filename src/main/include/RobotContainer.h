#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "subsystems/Shooter.h"
#include "subsystems/Serializer.h"
#include "subsystems/Intake.h"
#include "subsystems/Lift.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/ControlPanelManipulator.h"

#include "commands/drivetrain/TankDrive.h"

#include "commands/Intake/ToggleIntake.h"

#include "commands/Serializer/VBeltOff.h"

#include "frc2/command/button/JoystickButton.h"


#include "Constants.h"

#define GEN_BUTTON(name, controller, btn) frc2::JoystickButton name { &controller, btn }
#define GEN_BUTTON_MAIN_CONTROLLER(name, btn) GEN_BUTTON(name, controller_, btn)

class RobotContainer
{
public:
  RobotContainer();
 
  Intake& intake_ = Intake::GetInstance();
  Shooter& shooter_ = Shooter::GetInstance();
  Serializer& serializer_ = Serializer::GetInstance();//V-Belt
  Lift& lift_ = Lift::GetInstance();
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  ControlPanelManipulator& control_panel_manipulator_ = ControlPanelManipulator::GetInstance();

  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };

  GEN_BUTTON_MAIN_CONTROLLER(intake_button_, 1);

private:
  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
