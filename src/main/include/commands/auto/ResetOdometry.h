/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/InstantCommand.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.h"
/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ResetOdometry
    : public frc2::CommandHelper<frc2::InstantCommand, ResetOdometry> {
 public:
  ResetOdometry(DriveSubsystem* driveSub, const frc::Pose2d& pose, const frc::Rotation2d& angle);

  void Initialize() override;
  private: 
  DriveSubsystem* m_drive;
  const frc::Pose2d& m_pose;
  const frc::Rotation2d& m_angle;
};
