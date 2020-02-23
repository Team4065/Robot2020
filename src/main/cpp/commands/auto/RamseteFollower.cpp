/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/RamseteFollower.h"

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/controller/PIDController.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>

RamseteFollower::RamseteFollower(
    const frc::Pose2d &startingPos,
    const std::vector<frc::Translation2d> &translationPos,
    const frc::Pose2d &endingPos,
    DriveSubsystem *m_drive)
    : m_startingPos(startingPos),
      m_translationPos(translationPos),
      m_endingPos(endingPos),
      m_drivetrain(m_drive)
{

  // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks,
          DriveConstants::kv,
          DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed, AutoConstants::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

  // An example trajectory to follow.  All units in meters.
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      m_startingPos,
      // Pass through these two interior waypoints
      m_translationPos,
      // End meters
      m_endingPos,
      // Pass the config
      config);

  frc2::PIDController leftController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);
  frc2::PIDController rightController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);

  frc2::RamseteCommand ramseteCommand(
      //start path
      exampleTrajectory, [this]() { return m_drivetrain->GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return m_drivetrain->GetWheelSpeeds(); },
      leftController,
      rightController,
      [this](auto left, auto right) { m_drivetrain->TankDriveVolts(left, right); },
      {m_drive});
  //End path
  AddCommands(std::move(ramseteCommand), frc2::InstantCommand([this] { m_drivetrain->TankDriveVolts(0_V, 0_V); },
                                                              {}));
}
