#pragma once

#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/Command.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Rotation2d.h>

#include "subsystems/Drivetrain.h"

#include "Constants.h"

class RunnableTrajectory : public frc2::CommandHelper<frc2::SequentialCommandGroup, RunnableTrajectory>
{
public:
    RunnableTrajectory(frc::Trajectory& traj);
    void Run();
    bool Done() const;
    void Initialize() override;
    void Execute() override {};
    void End(bool interrupted) override {};
    bool IsFinished() override;
protected:
    frc::Trajectory traj_;
    frc2::RamseteCommand* ramsete_command_;
};