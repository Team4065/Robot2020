#pragma once

#include <memory>
#include <cmath>

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <units/units.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <AHRS.h>

#include "Constants.h"
#include "util/Macros.h"
#include <iostream>
#include "util/ReferencedTunable.h"

#include "commands/drivetrain/ArcadeDrive.h"

#include "rev/CANSparkMax.h"

#include "util/Limelight.h"



class Drivetrain : public frc2::SubsystemBase
{
public:


  void ArcadeDrive(double fwd, double rot);
  void TankDriveVolts(units::volt_t left, units::volt_t right);
  void TankDrivePercent(double left, double right);

  units::volt_t GetLeftVolts() const;
  units::volt_t GetRightVolts() const;

  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();
  frc::Pose2d GetPose() const;
  units::degree_t GetHeading();
  units::meter_t GetLeftEncoderDistance();
  units::meter_t GetRightEncoderDistance();
  
  void ResetEncoders();
  void ResetOdometry(frc::Pose2d pose);
  void ResetGyro();
  void NeutralMode(bool isEnabled);

  static Drivetrain& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Drivetrain);
  void Periodic();

  frc4065::Limelight limelight {"limelight"};

private:

  rev::CANSparkMax left_front_master_ { constants::drivetrain::kLeftFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax left_middle_slave_ { constants::drivetrain::kLeftMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANEncoder  left_encoder_      { left_front_master_.GetEncoder() };
  rev::CANPIDController left_pid_     { left_front_master_.GetPIDController() };

  rev::CANSparkMax right_front_master_ { constants::drivetrain::kRightFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax right_middle_slave_ { constants::drivetrain::kRightMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANEncoder  right_encoder_      { right_front_master_.GetEncoder() };
  rev::CANPIDController right_pid_     { right_front_master_.GetPIDController() };

  frc::SpeedControllerGroup left_motors_ { left_front_master_, left_middle_slave_ };
  frc::SpeedControllerGroup right_motors_ { right_front_master_, right_middle_slave_ };

  frc::DifferentialDrive drive_ { left_motors_, right_motors_ };

  AHRS gyro_ { frc::SPI::Port::kMXP };

  frc::DifferentialDriveOdometry odometry_;

  Drivetrain();
};
