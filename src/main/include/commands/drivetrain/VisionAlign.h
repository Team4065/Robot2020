#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Vision.h"
#include "subsystems/Drivetrain.h"

#include "commands/BlinkVisionTimed.h"

class VisionAlign
    : public frc2::CommandHelper<frc2::CommandBase, VisionAlign>
    {
public:
  VisionAlign();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;
private:
  frc2::PIDController pid_controller_;
  bool exit_flag_ = false;
};
