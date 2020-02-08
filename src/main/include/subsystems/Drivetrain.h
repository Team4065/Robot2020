#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
//#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum DriveMode {
    DRIVER,
    AUTO
  };
  enum TrackingTarget{
    NONE,
    TAPE,
    BALL
  };

  struct State{
    DriveMode driveMode = DriveMode::DRIVER;
    float leftSpeedTarget = 0;
    float rightSpeedTarget = 0;

    TrackingTarget trackingTarget = TrackingTarget::TAPE;
    float targetOffsetX = 0;
    float targetOffsetY = 0;

    double currentTime = 0.0;
    double pastTime = 0.0;
    double pastTrackingError = 0.0;

  };

  

  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  double tv, tx, ty, ta, ts;
  double kp = 0.015;
  double kd = 0;
  double kf = 0.08;

  static Drivetrain& GetInstance();
  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;
  void Periodic();

  void SetLeft(float value, ControlMode);
  void SetRight(float value, ControlMode);
  void SetTrackingTarget(TrackingTarget);
  void Tracking();

  State state;

  TalonSRX left_front_master_ {constants::drivetrain::kLeftFrontMotorPort};
  VictorSPX left_middle_ { constants::drivetrain::kLeftMiddleMotorPort };
  VictorSPX left_rear_ { constants::drivetrain::kLeftRearMotorPort };

  TalonSRX right_front_master_ { constants::drivetrain::kRightFrontMotorPort };
  VictorSPX right_middle_ { constants::drivetrain::kRightMiddleMotorPort };
  VictorSPX right_rear_ { constants::drivetrain::kRightRearMotorPort };

private:
  
  



  Drivetrain();
};
