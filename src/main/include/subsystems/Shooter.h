#pragma once

#include <cmath>
#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <units/units.h>

#include "Constants.h"
#include "util/Macros.h"

#include "rev/CANSparkMax.h"

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

  static Shooter& GetInstance();

  void ShootWithDistanceEstimation(units::foot_t distanceToTarget);
  void SetShooterVelocity(units::revolutions_per_minute_t angularVelocity);
  void SetShooterPercent(double percent);
  void EngageKicker();
  void DisableKicker();
  void EngageFeeder();
  void DisableFeeder();

  bool IsKickerActive() const;
  bool IsFeederActive() const;

  units::revolutions_per_minute_t GetVelocity();
  units::revolutions_per_minute_t GetDesiredVelocity();
  units::revolutions_per_minute_t GetVelocityError();
  units::current::ampere_t GetCurrentDraw();
  bool AtDesiredVelocity();
  bool AtDesiredVelocityWithHysteresis();

  DISALLOW_COPY_AND_ASSIGN(Shooter);
  void Periodic();

  double GetSensorVelocity();

 private:

  bool feeder_on_ = false;
  bool kicker_on_ = false;

  units::revolutions_per_minute_t desired_velocity_ { 0.0 };

  WPI_TalonFX left_master_ { constants::shooter::kLeftMotorPort };
  WPI_TalonFX right_slave_ { constants::shooter::kRightMotorPort };

  rev::CANSparkMax feeder_motor_ { constants::shooter::kFeederMotor1Port, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax kicker_motor_ { constants::shooter::kFeederMotor2Port, rev::CANSparkMax::MotorType::kBrushless };

  units::revolutions_per_minute_t TalonNativeUnitsToRPM(double native_units);
  double RPMToTalonNativeUnits(units::revolutions_per_minute_t rpm);

  Shooter();
};