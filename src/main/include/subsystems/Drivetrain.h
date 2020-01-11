#pragma once

#include <frc2/command/SubsystemBase.h>

#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum drivetrainMode {
    driverControl,
    autonomousControl
  };

  drivetrainMode mode = drivetrainMode::driver_control;

  float targetSpeed = 0;



  static Drivetrain& GetInstance();
  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;
  void Periodic();

private:
  
  TalonSRX left_front_master_ {constants::drivetrain::kLeftFrontMotorPort};
  TalonSRX left_middle_ { constants::drivetrain::kLeftMiddleMotorPort };
  TalonSRX left_rear_ { constants::drivetrain::kLeftRearMotorPorts };
  TalonSRX right_front_master_ { constants::drivetrain::kRightFrontMotorPort };
  TalonSRX right_middle_ { constants::drivetrain::kRightMiddleMotorPort };
  TalonSRX right_rear_ { constants::drivetrain::kRightRearMotorPort };

  Drivetrain(){}

  void SetLeft(float value, controlMode)
};
