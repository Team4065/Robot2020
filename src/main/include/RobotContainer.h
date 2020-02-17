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
#include "commands/ControlPanel/SpinControlPanel.h"

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
 
private:
  //Subsystems
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  Intake& intake_ = Intake::GetInstance();
  Serializer& serializer_ = Serializer::GetInstance();//V-Belt
  Shooter& shooter_ = Shooter::GetInstance();
  ControlPanelManipulator& controlPanelManipulator_ = ControlPanelManipulator::GetInstance();
  Lift& lift_ = Lift::GetInstance();

  //Controller(s)
  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };

  //Button Mapping(s)
  frc2::JoystickButton retractIntakeButton_ { &controller_, (int)XboxController::Button::kX };
  frc2::JoystickButton collectBallsButton_ { &controller_, (int)XboxController::Button::kBumperRight };   //Deploy (if not deployed / Suck balls / Move ball to shooter)

  //sfs: Limelight drivetrain control (hold down button)
  //sfs: Add toggle button for low speed drivetrain for lining up shot
  frc2::JoystickButton shootBallsButton_ { &controller_, (int)XboxController::Button::kBumperLeft };
  //sfs: adjust shooter speed based on distance or with manual control
  
  frc2::JoystickButton toggleCPMDeploymentButton_ { &controller_, (int)XboxController::Button::kY };
  frc2::JoystickButton spinControlPanelButton_ { &controller_, (int)XboxController::Button::kA };
  //sfs: Manual control of CPM with trigger right and left
  //right trigger = clockwise
  //left trigger = counter clockwise
  //sfs: automatically move to color, need button
  
  //sfs: Use B to Deploy Lift / Stow Lift
  frc2::JoystickButton toggleLiftDeploymentButton_ { &controller_, (int)XboxController::Button::kB };
  //sfs: POV Up extends Lift, POV down retracts
  //sfs: POV right & left to move robot balancer wheel

  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
