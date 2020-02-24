/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

//Subsystems
#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Serializer.h"
#include "subsystems/Intake.h"
#include "subsystems/Lift.h"
#include "subsystems/ControlPanelManipulator.h"

//Commands
#include "commands/drivetrain/TankDrive.h"

#include "commands/Intake/Suck.h"
#include "commands/Intake/DontSuck.h"
#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/RetractIntake.h"
#include "commands/Intake/Deploy_And_Suck.h"
#include "commands/Intake/Retract_and_DontSuck.h"
#include "commands/CollectBalls.h"

#include "commands/Serializer/VBeltOff.h"

#include "commands/Shooter/SpinUp.h"
#include "commands/Shooter/Shoot.h"
#include "commands/Shooter/SpinUp_and_Shoot.h"
#include "commands/Shooter/IdleShooter.h"

#include "commands/ControlPanel/DeployCPM.h"
#include "commands/ControlPanel/StowCPM.h"
#include "commands/ControlPanel/AutomaticallySpinControlPanel.h"
#include "commands/ControlPanel/ManuallySpinControlPanel.h"

#include "commands/Lift/RetractLift.h"
#include "commands/Lift/ExtendLift.h"
#include "commands/Lift/LengthenWinch.h"
#include "commands/Lift/ShortenWinch.h"
#include "commands/Lift/BalanceOnLift.h"


using namespace frc;
using namespace constants;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  // frc2::Command* GetAutonomousCommand();

 private:

  ///////////////////////////////////////////////////////////////////////////////////////
  //Controller(s)
  ///////////////////////////////////////////////////////////////////////////////////////
  frc::XboxController m_controller_0 { constants::oi::kDriverXboxControllerPort0 };
  frc::XboxController m_controller_1 { constants::oi::kDriverXboxControllerPort1 };

  ///////////////////////////////////////////////////////////////////////////////////////
  //Subsystems (Use Singleton Method for Instantiations)
  ///////////////////////////////////////////////////////////////////////////////////////
  Drivetrain& m_drivetrain = Drivetrain::GetInstance();
  Intake& m_intake = Intake::GetInstance();
  Serializer& m_serializer = Serializer::GetInstance();//V-Belt
  Shooter& m_shooter = Shooter::GetInstance();
  ControlPanelManipulator& m_controlPanelManipulator = ControlPanelManipulator::GetInstance();
  Lift& m_lift = Lift::GetInstance();

  ///////////////////////////////////////////////////////////////////////////////////////
  //Commands
  ///////////////////////////////////////////////////////////////////////////////////////

  //Collect & Shoot
  DeployIntake m_deployIntake {m_intake};
  Suck m_suck {m_intake};
  VBeltForward m_vBeltForwardCommand {m_serializer};
  Preload m_preloadCommand {m_shooter};
  CollectBalls m_CollectBallsCommands {m_intake, m_serializer, m_shooter};   //Parallel Command Group
  SpinUp m_spinUp {m_shooter};  
  Shoot m_shoot {m_shooter};
  SpinUp_and_Shoot m_spinUpAndShootCommands {m_spinUp, m_shoot};    //Sequential Command Group
  RetractIntake m_retractIntake {m_intake};

  DeployCPM m_deployCPMCommand {m_controlPanelManipulator};
  StowCPM m_stowCPMCommand {m_controlPanelManipulator};
  AutomaticallySpinControlPanel m_automaticallySpinControlPanelCommand {m_controlPanelManipulator};
  ManuallySpinControlPanel m_manuallySpinControlPanelCommand {m_controlPanelManipulator, m_controller_0};
  // MoveControlPanelToColor m_moveControlPanelToColorCommand {m_controlPanelManipulator};

  //Lift
  // DeployLift m_deployLiftCommand {m_lift};
  // StoyLift m_stoyLiftCommand {m_lift};
  ExtendLift m_extendLiftCommand {m_lift};
  RetractLift m_retractLiftCommand {m_lift};
  BalanceOnLift m_balanceOnLift {m_lift};

  ///////////////////////////////////////////////////////////////////////////////////////
  //Buttons
  ///////////////////////////////////////////////////////////////////////////////////////
  //Drivetrain (Non Default Commands)
  //sfs: You may want a slower drivetrain for lining up shoots.
  //sfs: You could use a button to toggle in and out of a slower response drivetrain mode
  frc2::JoystickButton m_toggleDrivetrainModeControlButton { &m_controller_0, (int)XboxController::Button::kB };   //Toggle button to switch between normal and precision mode

  //Collect & Shoot Balls
  frc2::JoystickButton m_collectBallsButton { &m_controller_1, (int)XboxController::Button::kBumperRight };   //Deploy (if not deployed / Suck balls / Move ball to shooter)
  frc2::JoystickButton m_retractIntakeButton { &m_controller_1, (int)XboxController::Button::kX };
  frc2::JoystickButton m_enableLimeLightDrivetrainControlButton { &m_controller_0, (int)XboxController::Button::kA };   //Hold down button
  frc2::JoystickButton m_shootButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };
  // frc2::JoystickButton m_manuallyAdjustShooterSpeedButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };
  // frc2::JoystickButton m_automaticallyAdjustShooterSpeedButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };

  //Spin Control Panel
  frc2::JoystickButton m_toggleCPMDeploymentButton { &m_controller_1, (int)XboxController::Button::kY };
  frc2::JoystickButton m_toggleSpinControlPanelModeButton { &m_controller_1, (int)XboxController::Button::kA };    //Toggle between manual control and automatic control
  frc2::JoystickButton m_manuallySpinControlPanelButton { &m_controller_1, (int)XboxController::Button::kA };    //right trigger = clockwise, left trigger = counter clockwise
  frc2::JoystickButton m_automaticallySpinControlPanelButton { &m_controller_1, (int)XboxController::Button::kA };
  // frc2::JoystickButton m_moveControlPanelToColorButton_ { &m_controller_1, (int)XboxController::Button::kA };
  
  //Lift
  frc2::JoystickButton m_toggleLiftDeploymentButton { &m_controller_1, (int)XboxController::Button::kY };
  frc2::JoystickButton m_moveLiftUpDownButton { &m_controller_1, (int)XboxController::Button::kY };     //POV Up extends Lift, POV down retracts
  frc2::JoystickButton m_moveLiftSide2SideButton { &m_controller_1, (int)XboxController::Button::kY };  //POV right & left to move robot balancer wheel

  void ConfigureButtonBindings();
};
