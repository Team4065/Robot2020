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
constexpr int kRightMotor1Port = 4;
constexpr int kRightMotor2Port = 3;

constexpr auto kTrackwidth = 0.6356_m;

extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr double kGearRatio = 9.47;
constexpr double kWheelDiameterMeters = 0.1524;
constexpr double kPI = wpi::math::pi;

constexpr bool kGyroReversed = true;

constexpr auto ks = 0.1235_V;
constexpr auto kv = 2.46 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.161 * 1_V * 1_s * 1_s / 1_m;

constexpr double kPDriveVel = 6.44;
constexpr double kIDriveVel = 0.0;
constexpr double kDDriveVel = 0;

constexpr double kencoderConstant =  kWheelDiameterMeters * wpi::math::pi / kGearRatio;

} 

namespace AutoConstants {
constexpr auto kMaxSpeed = 1_mps;
constexpr auto kMaxAcceleration = 1_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2.0;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
}  // namespace OIConstants
