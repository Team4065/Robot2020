#pragma once

#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
 public:
  

  static Intake& GetInstance()
  {
    static Intake    instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
  }

  Intake(Intake const&)       = delete;
  void operator=(Intake const&)  = delete;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  Intake(){}

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
