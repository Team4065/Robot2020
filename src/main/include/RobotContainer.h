/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
//subsystem
#include "subsystems/DriveSubsystem.h"

//commands
#include "commands/auto/RamseteFollower.h"
#include "commands/auto/routines/SixBallsRoutine.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  
 private:
  // The driver's controller
  frc::XboxController m_driverController{OIConstants::kDriverControllerPort};

  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  DriveSubsystem m_drive;

  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  //commands auto
  SixBallsRoutine m_sixBallsRoutine{&m_drive};

  RamseteFollower m_noAuto{
    frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
    {}, 
    frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)), 
    &m_drive
  };

  void ConfigureButtonBindings();
};
