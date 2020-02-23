/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))}
{
  // Set up all left side motors that work together
  // Set both motors to spin opposite for forward
  // left_master.SetInverted(false);
  // left_slave.SetInverted(false);
  // left_master.SetSensorPhase(true);
  // left_master.SetNeutralMode(NeutralMode::Brake); // Don't coast after movements
  // left_slave.SetNeutralMode(NeutralMode::Brake);
  // left_master.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0);
  
  // Set up all right side motors that work together
  // Set both motors to spin opposite for forward
  // right_master.SetInverted(false);
  // right_slave.SetInverted(false);
  // right_master.SetSensorPhase(false);              // Only if encoders reading backwards
  // right_master.SetNeutralMode(NeutralMode::Brake); // Don't coast after movements
  // right_slave.SetNeutralMode(NeutralMode::Brake);
  // right_master.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0);
  
  ResetGyro();
  ResetEncoders();
}

void DriveSubsystem::Periodic()
{
  // Implementation of subsystem periodic method goes here.
  //double gyroAngle = GetHeading();

  // This Periodic function is called every 20 ms
  //m_odometry.Update(frc::Rotation2d(units::degree_t(gyroAngle)),
    //                units::meter_t(GetMeterDistance(&left_master)),
      //              units::meter_t(GetMeterDistance(&right_master)));
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
  //left_master.SetSelectedSensorPosition(0);
  //right_master.SetSelectedSensorPosition(0);
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
  //double leftVel =(DriveConstants::kEncoderDistancePerPulse * 10 * (double)left_master.GetSelectedSensorVelocity());
  //double rightVel = (DriveConstants::kEncoderDistancePerPulse * 10 * (double)right_master.GetSelectedSensorVelocity());
  //return {units::meters_per_second_t(leftVel), units::meters_per_second_t(rightVel)};
}

void DriveSubsystem::ResetOdometry(const frc::Pose2d& pose, const frc::Rotation2d& newYaw)
{
  ResetEncoders();

  m_odometry.ResetPosition(pose, newYaw);//frc::Rotation2d(units::degree_t(GetHeading())));
}

double DriveSubsystem::GetMeterDistance(rev::CANSparkMax *cansparkmax)
{
 // return DriveConstants::kEncoderDistancePerPulse * (double)talon->GetSelectedSensorPosition();
}
