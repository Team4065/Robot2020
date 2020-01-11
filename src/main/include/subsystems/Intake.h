#pragma once

#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase
{
public:
  
  static Intake& GetInstance();

  Intake(Intake const&)       = delete;
  void operator=(Intake const&)  = delete;
  void Periodic();
private:
  Intake() = default;
};
