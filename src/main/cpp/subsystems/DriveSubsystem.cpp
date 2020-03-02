/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include <iostream>
DriveSubsystem::DriveSubsystem() : m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))}
{
  left_master.RestoreFactoryDefaults();
  left_slave.RestoreFactoryDefaults();
  right_master.RestoreFactoryDefaults();
  right_slave.RestoreFactoryDefaults();

  // Set up all left side motors that work together
  // Set both motors to spin opposite for forward
  left_master.SetInverted(false);
  //left_slave.SetInverted(true);

  // Set up all right side motors that work together
  // Set both motors to spin opposite for forward
  right_master.SetInverted(false);
  //right_slave.SetInverted(false);
  left_master.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  left_slave.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  right_master.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  right_slave.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  // left_encoder.SetPositionConversionFactor(DriveConstants::kencoderConstant);
  // right_encoder.SetPositionConversionFactor(DriveConstants::kencoderConstant);
  // left_encoder.SetVelocityConversionFactor(DriveConstants::kencoderConstant / 60);
  // right_encoder.SetVelocityConversionFactor(DriveConstants::kencoderConstant / 60);

  ResetGyro();
  ResetEncoders();
}

void DriveSubsystem::Periodic()
{
  // Implementation of subsystem periodic method goes here.
  // This Periodic function is called every 20 ms
  m_odometry.Update(frc::Rotation2d(units::degree_t(GetHeading())), units::meter_t(left_master.GetEncoder().GetPosition() / 9.47 * 0.1524 * DriveConstants::kPI),
                    -units::meter_t(right_master.GetEncoder().GetPosition() / 9.47 * 0.1524 * DriveConstants::kPI));
                    
std::cout << "left: " << left_master.GetEncoder().GetPosition() / 9.47 * 0.1524  * DriveConstants::kPI << " right: " << right_master.GetEncoder().GetPosition() / 9.47 * 0.1524 * DriveConstants::kPI << std::endl;
m_drive.Feed();
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot)
{
  m_drive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right)
{
  m_leftMotors.SetVoltage(left);
  m_rightMotors.SetVoltage(-right);
}
void DriveSubsystem::ResetGyro()
{
  m_gyro.Reset();
}
void DriveSubsystem::ResetEncoders()
{
  left_encoder.SetPosition(0);
  right_encoder.SetPosition(0);
}

void DriveSubsystem::SetMaxOutput(double maxOutput)
{
  m_drive.SetMaxOutput(maxOutput);
}

double DriveSubsystem::GetHeading()
{
  return std::remainder(m_gyro.GetAngle(), 360.0) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d DriveSubsystem::GetPose()
{
  return m_odometry.GetPose();
}

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds()
{

  return {
      units::meters_per_second_t(left_master.GetEncoder().GetVelocity() / 9.47 * DriveConstants::kPI * 0.1524 / 60),
      -units::meters_per_second_t(right_master.GetEncoder().GetVelocity() / 9.47 * DriveConstants::kPI * 0.1524 / 60)
      };
}
void DriveSubsystem::ResetOdometry(const frc::Pose2d pose)
{
  ResetEncoders();

  m_odometry.ResetPosition(pose, frc::Rotation2d(units::degree_t(GetHeading())));
}