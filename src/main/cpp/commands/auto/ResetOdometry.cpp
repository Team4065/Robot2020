/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/ResetOdometry.h"

ResetOdometry::ResetOdometry(DriveSubsystem* driveSub, const frc::Pose2d& pose, const frc::Rotation2d& angle) : m_drive(driveSub), m_pose(pose), m_angle(angle) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drive);
}

// Called when the command is initially scheduled.
void ResetOdometry::Initialize() {

  m_drive->ResetOdometry(m_pose, m_angle);
}
