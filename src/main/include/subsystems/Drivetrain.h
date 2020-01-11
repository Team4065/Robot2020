#pragma once

#include <frc2/command/SubsystemBase.h>

#include "rev/CANSparkMax.h"

class Drivetrain : public frc2::SubsystemBase
{
public:

  enum WantedState {

  }

  static Drivetrain& GetInstance();
  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;
  void Periodic();

private:
  

  Drivetrain(){}
};
