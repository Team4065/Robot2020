#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/auto/paths/RunnableTrajectoryBase.h"

class StraightLineTest
    : public frc2::CommandHelper<frc2::CommandBase, StraightLineTest>, public RunnableTrajectoryBase {
 public:
  StraightLineTest();

  frc::Trajectory GetTrajectory() override;

  void Initialize() override;
  void Execute() override {};
  void End(bool interrupted) override {};
  bool IsFinished() override;
};
