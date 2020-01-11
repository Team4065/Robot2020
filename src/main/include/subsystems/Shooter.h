#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

#include "rev/CANSparkMax.h"

class Shooter : public frc2::SubsystemBase
{
public:
  
  enum state {
    SPINNING_UP,
    SHOOTING,
    IDLE
  }

  static Shooter& GetInstance();

  Shooter(Shooter const&)      = delete;
  void operator=(Shooter const&)  = delete;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void On();
  void Off();

  void Shoot()

 private:

  rev::CANSparkMax left {constants::shooter::kLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax right {constants::shooter::kRightMotorPort, rev::CANSparkMax::MotorType::kBrushless};

  Shooter() {}
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
