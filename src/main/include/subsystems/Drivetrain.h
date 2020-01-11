#pragma once

#include <frc2/command/SubsystemBase.h>

//#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum Mode {
    DRIVER,
    AUTO
  };

  Mode mode = Mode::DRIVER;

  float targetLeft = 0;
  float targetRight = 0;



  static Drivetrain& GetInstance();
  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;
  void Periodic();

private:
  
  TalonSRX left_front_master_ {constants::drivetrain::kLeftFrontMotorPort};
  TalonSRX left_middle_ { constants::drivetrain::kLeftMiddleMotorPort };
  TalonSRX left_rear_ { constants::drivetrain::kLeftRearMotorPort };

  TalonSRX right_front_master_ { constants::drivetrain::kRightFrontMotorPort };
  TalonSRX right_middle_ { constants::drivetrain::kRightMiddleMotorPort };
  TalonSRX right_rear_ { constants::drivetrain::kRightRearMotorPort };

  Drivetrain();

  void SetLeft(float value, ControlMode);
  void SetRight(float value, ControlMode);
};
