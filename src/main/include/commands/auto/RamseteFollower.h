/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>

#include <frc2/command/SequentialCommandGroup.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Translation2d.h>
#include "subsystems/DriveSubsystem.h"
#include "Constants.h"
#include <vector>

class RamseteFollower
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, RamseteFollower> {
 public:
  RamseteFollower(const frc::Pose2d& startingPos, const std::vector<frc::Translation2d>& translationPos, const frc::Pose2d& endingPos, DriveSubsystem* m_drive);
  const frc::Pose2d& m_startingPos;
  const std::vector<frc::Translation2d>& m_translationPos;
  const frc::Pose2d& m_endingPos;
  DriveSubsystem* m_drivetrain;
  void resetPose();
};
