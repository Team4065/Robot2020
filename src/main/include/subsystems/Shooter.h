#pragma once

#include <frc2/command/SubsystemBase.h>

class Shooter : public frc2::SubsystemBase
{
public:
  


  static Shooter& GetInstance();

  Shooter(Shooter const&)      = delete;
  void operator=(Shooter const&)  = delete;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:

  Shooter() {}
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
