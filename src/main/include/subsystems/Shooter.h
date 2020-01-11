#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/units.h>

#include "Constants.h"

#include "rev/CANSparkMax.h"

class Shooter : public frc2::SubsystemBase
{
public:
  
  enum State
  {
    IDLE, SPINUP, SHOOTING
  };

  static Shooter& GetInstance();

  void ShootWithDistanceEstimation(units::foot_t distanceToTarget);
  void SetShooterVelocity(units::radians_per_second_t angularVelocity);

  Shooter(Shooter const&)      = delete;
  void operator=(Shooter const&)  = delete;
  void Periodic();

 private:

  rev::CANSparkMax left_ {constants::shooter::kLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax right_ {constants::shooter::kRightMotorPort, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder left_encoder_ { left_.GetEncoder() };
  rev::CANEncoder right_encoder_ { right_.GetEncoder() };

  Shooter();
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
