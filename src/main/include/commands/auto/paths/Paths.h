#pragma once

#include "commands/auto/paths/RunnableTrajectory.h"
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include "commands/auto/paths/TrajectoryPoints.h"

TrajectoryPoints kStraightLinePath(
    frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
    {
        frc::Translation2d(0.5_m, 0_m)
    },
    frc::Pose2d(1_m, 0_m, frc::Rotation2d(0_deg))
);