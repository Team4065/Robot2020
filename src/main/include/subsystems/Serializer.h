#pragma once

#include <frc2/command/SubsystemBase.h>
#include "util/Macros.h"

class Serializer : public frc2::SubsystemBase
{
public:
  static Serializer& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Serializer);
  void Periodic();
private:
  Serializer();
};
