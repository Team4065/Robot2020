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

#include "commands/Intake/Suck.h"
#include "commands/Intake/DontSuck.h"
#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/IntakeDefaultState.h"
#include "commands/Intake/DeployAndSuck.h"

#include "commands/Lift/RetractLift.h"
#include "commands/Lift/ExtendLift.h"
#include "commands/Lift/LengthenWinch.h"
#include "commands/Lift/ShortenWinch.h"
#include "commands/Lift/LiftDefaultState.h"

#include "Constants.h"

class RobotContainer
{
public:
  RobotContainer();

private:
  Shooter& shooter_ = Shooter::GetInstance();
  Serializer& serializer_ = Serializer::GetInstance();
  Intake& intake_ = Intake::GetInstance();
  Lift& lift_ = Lift::GetInstance();
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  ControlPanelManipulator& control_panel_manipulator_ = ControlPanelManipulator::GetInstance();

  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };

  frc2::JoystickButton IntakeButton { &controller_, 0 };

  frc2::JoystickButton ToggleLiftExtensionButton { &controller_, 2 };
  frc2::JoystickButton LengthenWinchButton { &controller_, 3 };
  frc2::JoystickButton ShortenWinchButton { &controller_, 4 };


  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
