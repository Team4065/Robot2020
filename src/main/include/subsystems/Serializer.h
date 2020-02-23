#pragma once

#include <frc2/command/SubsystemBase.h>
#include "util/Macros.h"

#include <rev/CANSparkMax.h>

#include "Constants.h"

//V-Belt
class Serializer : public frc2::SubsystemBase
{
public:
  static Serializer& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Serializer);
  void Periodic();
  void Forward();
  void Idle();
  void Reverse();

private:
  Serializer();

  rev::CANSparkMax motor_ { constants::serializer::kSerializerID, rev::CANSparkMax::MotorType::kBrushless };
};
