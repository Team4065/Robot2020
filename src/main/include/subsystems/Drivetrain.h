#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/units.h>
#include <AHRS.h>
#include "subsystems/ReferencedTunable.h"
#include <ctre/Phoenix.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  static Drivetrain& GetInstance();
  void Periodic();
  void TankDriveVolts(units::volt_t left, units::volt_t right);
void DriveVelocity(units::feet_per_second_t left, units::feet_per_second_t);
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();
  frc::Pose2d GetPose() const;
  units::degree_t GetHeading();
  units::foot_t GetLeftEncoderDistance();
  units::foot_t GetRightEncoderDistance();
  void ZeroEncoders();
 private:
  TalonSRX front_left_ {1};
  TalonSRX back_left_ {3};
  TalonSRX back_right_ {4};
  TalonSRX front_right_ {2};
  AHRS gyro_ { frc::SPI::Port::kMXP };
  frc::DifferentialDriveOdometry odometry_;
  double kp = 1.0;
};
