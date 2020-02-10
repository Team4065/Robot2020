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
#include "commands/Intake/RetractIntake.h"
#include "commands/Intake/DeployAndSuck.h"

#include "commands/Lift/RetractLift.h"
#include "commands/Lift/ExtendLift.h"
#include "commands/Lift/LengthenWinch.h"
#include "commands/Lift/ShortenWinch.h"

#include "frc2\command\button\JoystickButton.h"

#include "commands/test.h"


#include "Constants.h"

class RobotContainer
{
public:
  RobotContainer();
 
  Intake& intake_ = Intake::GetInstance();
private:
  Shooter& shooter_ = Shooter::GetInstance();
  Serializer& serializer_ = Serializer::GetInstance();//V-Belt
  Lift& lift_ = Lift::GetInstance();
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  ControlPanelManipulator& control_panel_manipulator_ = ControlPanelManipulator::GetInstance();

  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };

  frc2::JoystickButton suckIntakeButton { &controller_, 1 };
  frc2::JoystickButton retractIntakeButton { &controller_, 2 };


  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
