#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

#include "rev/CANSparkMax.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum State
  {
    TRACKING, OPENLOOP, VELOCITY
  };

  static Drivetrain& GetInstance();
  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;
  void Periodic();

private:
  
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

  Drivetrain();
};
