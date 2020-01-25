#include "commands/auto/paths/StraightLineTest.h"

StraightLineTest::StraightLineTest() {
  AddRequirements(&Drivetrain::GetInstance());
   Run();
}

frc::Trajectory StraightLineTest::GetTrajectory()
{
  return frc::TrajectoryGenerator::GenerateTrajectory(
    frc::Pose2d(0_ft, 0_ft, frc::Rotation2d(0_deg)),
    {},
    frc::Pose2d(3_ft, 0_ft, frc::Rotation2d(0_deg)),
    constants::drivetrain::kAutoConfig
  );
}

void StraightLineTest::Initialize() { }

bool StraightLineTest::IsFinished() { return Done(); }
