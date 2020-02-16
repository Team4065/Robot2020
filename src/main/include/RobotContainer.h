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
#include "commands/Intake/Deploy_And_Suck.h"
#include "commands/Intake/Retract_and_DontSuck.h"

#include "commands/Lift/RetractLift.h"
#include "commands/Lift/ExtendLift.h"
#include "commands/Lift/LengthenWinch.h"
#include "commands/Lift/ShortenWinch.h"

#include "commands/Serializer/VBeltOff.h"

#include "commands/Shooter/SpinUp_and_Shoot.h"
#include "commands/Shooter/IdleShooter.h"

#include "frc2\command\button\JoystickButton.h"

#include "commands/CollectBalls.h"


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

  frc2::JoystickButton intakeButton { &controller_, 1 };
  frc2::JoystickButton shooterButton { &controller_, 2 };
  frc2::JoystickButton liftButton { &controller_, 3 };

  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
