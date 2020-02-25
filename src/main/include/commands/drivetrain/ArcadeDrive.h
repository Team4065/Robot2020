#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include <frc/XboxController.h>

class ArcadeDrive
    : public frc2::CommandHelper<frc2::CommandBase, ArcadeDrive> {
 public:
  ArcadeDrive(frc::XboxController* controller);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  frc::XboxController* controller_;
};
