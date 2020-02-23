/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/routines/SixBallsRoutine.h"
#include "commands/auto/RamseteFollower.h"
#include "commands/auto/ResetOdometry.h"
#include "frc2/command/ParallelCommandGroup.h"
#include "frc2/command/WaitUntilCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
SixBallsRoutine::SixBallsRoutine(DriveSubsystem* driveSub) : m_drive(driveSub) {
  // Add your commands here, e.g.

  frc::Pose2d startPos;//starting pose
  startPos = frc::Pose2d(0_m,0_m, frc::Rotation2d(0_deg));

  RamseteFollower examplePath{
  startPos,
  {frc::Translation2d(0_m, 0_m) , frc::Translation2d(0_m, 0_m)},
  frc::Pose2d(0_m,0_m, frc::Rotation2d(0_deg)), m_drive
  };

  RamseteFollower toTrench{
  startPos,
  {frc::Translation2d(0_m, 0_m)},
  frc::Pose2d(0_m,0_m, frc::Rotation2d(0_deg)), m_drive
  };


AddCommands(
  ResetOdometry(m_drive, startPos, frc::Rotation2d(units::degree_t(m_drive->GetHeading()))),
  std::move(toTrench)
  );
}