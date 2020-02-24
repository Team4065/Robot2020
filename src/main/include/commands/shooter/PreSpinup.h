#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <units/units.h>

#include "subsystems/Shooter.h"
/**
 * Spins up the shooter to the desired RPM. Ends when shooter reaches desired RPM.
 */
class PreSpinup
    : public frc2::CommandHelper<frc2::CommandBase, PreSpinup> {
 public:
  PreSpinup(units::revolutions_per_minute_t rpm);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;
private:
  units::revolutions_per_minute_t rpm_;
};
