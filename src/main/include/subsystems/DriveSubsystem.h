/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <iostream>

#include "Constants.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/SpeedControllerGroup.h>
#include <units/units.h>

#include "rev/CANSparkMax.h"
#include "AHRS.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

  /**
   * Controls each side of the drive directly with a voltage.
   *
   * @param left the commanded left output
   * @param right the commanded right output
   */
  void TankDriveVolts(units::volt_t left, units::volt_t right);

  /**
   * Resets the drive gyro to currently read a angle of 0.
   */
  void ResetGyro();
  
  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   */
  void SetMaxOutput(double maxOutput);

  /**
   * Returns the heading of the robot.
   *
   * @return the robot's heading in degrees, from 180 to 180
   */
  double GetHeading();
  /**
   * Returns the currently-estimated pose of the robot.
   *
   * @return The pose.
   */
  frc::Pose2d GetPose();

  /**
   * Returns the current wheel speeds of the robot.
   *
   * @return The current wheel speeds.
   */
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  /**
   * Resets the odometry to the specified pose.
   *
   * @param pose The pose to which to set the odometry.
   */
  void ResetOdometry(const frc::Pose2d& pose, const frc::Rotation2d& newYaw);

  double GetMeterDistance(rev::CANSparkMax *cansparkmax);


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax left_master {DriveConstants::kLeftMotor1Port, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax left_slave {DriveConstants::kLeftMotor2Port, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax right_master {DriveConstants::kRightMotor1Port, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax right_slave {DriveConstants::kRightMotor2Port, rev::CANSparkMax::MotorType::kBrushless};

  // The motors on the left side of the drive
  frc::SpeedControllerGroup m_leftMotors{left_master, left_slave};

  // The motors on the right side of the drive
  frc::SpeedControllerGroup m_rightMotors{right_master, right_slave};

  // The robot's drive
  frc::DifferentialDrive m_drive{m_leftMotors, m_rightMotors};

  // The gyro sensor
  AHRS m_gyro{frc::SPI::Port::kMXP};
  // Odometry class for tracking robot pose
  frc::DifferentialDriveOdometry m_odometry;
};
