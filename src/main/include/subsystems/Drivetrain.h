#pragma once

#include <memory>

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/units.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <AHRS.h>

#include "Constants.h"
#include "util/Macros.h"
#include <iostream>

#include "rev/CANSparkMax.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum Mode { DRIVERCONTROL, TARGETING, IDLE };

  void ArcadeDrive(double fwd, double rot);
  void TankDriveVolts(units::volt_t left, units::volt_t right);

  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();
  frc::Pose2d GetPose() const;
  units::degree_t GetHeading();
  units::foot_t GetLeftEncoderDistance() const;
  units::foot_t GetRightEncoderDistance() const;

  void ResetEncoders();
  void ResetOdometry(frc::Pose2d pose);

  void NeutralMode(bool isEnable);

  static Drivetrain& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Drivetrain);
  void Periodic();

  static void SetLeft(double value);
  static void SetRight(double value);

private:
  Mode mode_ = Mode::IDLE;

  rev::CANSparkMax left_front_master_ { constants::drivetrain::kLeftFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax left_middle_slave_ { constants::drivetrain::kLeftMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax left_rear_slave_   { constants::drivetrain::kLeftRearMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANEncoder  left_encoder_      { left_front_master_.GetEncoder() };
  rev::CANPIDController left_pid_     { left_front_master_.GetPIDController() };

  rev::CANSparkMax right_front_master_ { constants::drivetrain::kRightFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax right_middle_slave_ { constants::drivetrain::kRightMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax right_rear_slave_   { constants::drivetrain::kRightRearMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANEncoder  right_encoder_      { right_front_master_.GetEncoder() };
  rev::CANPIDController right_pid_     { right_front_master_.GetPIDController() };

  AHRS gyro_ { frc::SPI::Port::kMXP };

  frc::DifferentialDriveOdometry odometry_;

  Drivetrain();

  void Tracking();
};
