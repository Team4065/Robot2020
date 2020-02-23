/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  //Subsystems

  //Commands
  // m_deployCPMCommand = DeployCPM(m_controlPanelManipulator);

  m_drivetrain.SetDefaultCommand(TankDrive(m_drivetrain));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  //Drivetrain (Non Default Commands)
  m_toggleDrivetrainModeControlButton.WhenPressed([this] {m_drivetrain.DriveTrainMode = (m_drivetrain.DriveTrainMode==drivetrain::NORMAL) ? drivetrain::PRECISION : drivetrain::NORMAL;});

  //Capture & Shoot Balls
  m_collectBallsButton.WhenPressed(&m_CollectBallsCommands);
  m_retractIntakeButton.WhenPressed(m_retractIntake);
  m_shootButton.WhileHeld(&m_spinUpAndShootCommands);
  //sfs: Do you want a way to adjust the shooter speed?

  //Control Panel
  m_toggleCPMDeploymentButton.WhenPressed([this] {(m_controlPanelManipulator.IsDeployed()) ? m_stowCPMCommand.Schedule() : m_deployCPMCommand.Schedule();});
  m_automaticallySpinControlPanelButton.WhenPressed(m_automaticallySpinControlPanelCommand);
  m_toggleSpinControlPanelModeButton.WhenPressed([this] 
    {
      switch(m_controlPanelManipulator.GetMode()){
        case MANUAL:
          m_manuallySpinControlPanelButton.WhileHeld(m_manuallySpinControlPanelCommand);    //
          break;
        case AUTO_SPIN:
          m_automaticallySpinControlPanelCommand.Schedule();    //May
          break;
        case AUTO_COLOR:
        //   m_moveControlPanelToColorCommand.Schedule();
          break;
      }
    });

  //Lift & Balance
  // m_toggleLiftDeploymentButton.WhenPressed([this] {(m_lift.IsDeployed()) ? m_stoyLiftCommand.Schedule() : m_deployLiftCommand.Schedule();});
  // m_toggleLiftDeploymentButton.WhenPressed([this] {(m_lift.IsExtended()) ? m_retractLiftCommand.Schedule() : m_extendLiftCommand.Schedule();});
  m_toggleLiftDeploymentButton.WhenPressed([this] {(m_lift.IsExtended()) ? m_retractLiftCommand.Schedule() : m_extendLiftCommand.Schedule(); m_balanceOnLift.Schedule();});
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
// }
