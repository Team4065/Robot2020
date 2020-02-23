/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <units/units.h>
#include <wpi/math>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
constexpr int kLeftMotor1Port = 1;
constexpr int kLeftMotor2Port = 2;
constexpr int kRightMotor1Port = 3;
constexpr int kRightMotor2Port = 4;

constexpr auto kTrackwidth = 0.6096_m;

extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr int kEncoderCPR = 4096;//ticks_per_rev
constexpr double kWheelDiameterMeters = 0.1524;//wheel size in meters
constexpr double kEncoderDistancePerPulse =
    // Assumes the encoders are directly mounted on the wheel shafts
    (kWheelDiameterMeters * wpi::math::pi) / static_cast<double>(kEncoderCPR);

constexpr bool kGyroReversed = true;

// These are example values only - DO NOT USE THESE FOR YOUR OWN ROBOT!
// These characterization values MUST be determined either experimentally or
// theoretically for *your* robot's drive. The Robot Characterization
// Toolsuite provides a convenient tool for obtaining these values for your
// robot.
constexpr auto ks = 0.86_V;
constexpr auto kv = 3.26 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.687 * 1_V * 1_s * 1_s / 1_m;

// Example value only - as above, this must be tuned for your drive!
constexpr double kPDriveVel = 0.000666;
constexpr double kIDriveVel = 0.0;
constexpr double kDDriveVel = 0.000316;
}  // namespace DriveConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 3_mps;
constexpr auto kMaxAcceleration = 3_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2.0;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
}  // namespace OIConstants
