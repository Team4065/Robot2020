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
#include "commands/auto/paths/TrajectoryPoints.h"

#include "Constants.h"

class RunnableTrajectory : public frc2::CommandHelper<frc2::SequentialCommandGroup, RunnableTrajectory>
{
public:
    RunnableTrajectory(TrajectoryPoints& traj_pts);
protected:
    TrajectoryPoints traj_pts_;
    frc2::RamseteCommand* ramsete_command_;
};