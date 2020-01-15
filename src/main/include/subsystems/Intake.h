#pragma once

#include <frc2/command/SubsystemBase.h>
#include "util/Macros.h"

class Intake : public frc2::SubsystemBase
{
public:
  static Intake& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Intake);
  void Periodic();
private:
  Intake() = default;
};
