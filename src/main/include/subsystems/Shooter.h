#pragma once

#include <cmath>
#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <units/units.h>

#include "Constants.h"
#include "util/Macros.h"

#include "rev/CANSparkMax.h"
//#include "ctre/phoenix/motorcontrol/can/WPI_TalonFX.h"
#include "ctre/Phoenix.h"

/* TODO:
 * - Run numerical analysis on final shooter to get distance -> velocity.
 * - Finish implementation of GetVelocity; needs to get motor data and
 *   convert it to rotations_per_minute_t; currently has a placeholder.
 * 
 * IMPORTANT:
 * We MUST abide by the state machine and always ensure that the necessary
 * state is set in a given function. This will be important later for
 * safety calculations in a Superstructure class. 
**/

class Shooter : public frc2::SubsystemBase
{
public:
  
  /*
  enum State
  {
    IDLE, SPINUP, SHOOTING
  };
  */

  static Shooter& GetInstance();

  void ShootWithDistanceEstimation(units::foot_t distanceToTarget);
  //void SetShooterVelocity(units::revolutions_per_minute_t angularVelocity);

  // units::revolutions_per_minute_t GetVelocity() const;
  // units::revolutions_per_minute_t GetDesiredVelocity() const;
  // units::revolutions_per_minute_t GetVelocityError() const;
  // units::current::ampere_t GetCurrentDraw() const;
  //State GetState() const;

  DISALLOW_COPY_AND_ASSIGN(Shooter);
  void Periodic();

  double GetSensorVelocity();

  double targetVelocity = 0;

 private:
  //State state_ = State::IDLE;

  //units::revolutions_per_minute_t desired_velocity_ { 0.0 };

  bool isFeeder1On = false;
  bool isFeeder2On = false;

  WPI_TalonFX left { constants::shooter::kLeftMotorPort };
  WPI_TalonFX right { constants::shooter::kRightMotorPort };

  rev::CANSparkMax feederMotor1 { constants::shooter::kFeederMotor1Port, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax feederMotor2 { constants::shooter::kFeederMotor2Port, rev::CANSparkMax::MotorType::kBrushless };

  double kP = 0;
  double kD = 0;
  double kF = 0;
  

  Shooter();
};
