#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>

#include <units/units.h>

#include "subsystems/Vision.h"

class BlinkVisionTimed
    : public frc2::CommandHelper<frc2::CommandBase, BlinkVisionTimed> {
public:
  BlinkVisionTimed(units::second_t time);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  units::second_t start_time_;
  units::second_t time_;
};
