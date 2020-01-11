#pragma once

#include <frc2/command/SubsystemBase.h>

class Drivetrain : public frc2::SubsystemBase {
 public:

  static Drivetrain& GetInstance()
  {
    static Drivetrain    instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
  }

  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;


  void Periodic();

 private:
  

  Drivetrain(){}
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
