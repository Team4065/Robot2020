#pragma once

#include <frc/trajectory/TrajectoryGenerator.h>

class TrajectoryPoints
{
public:
    TrajectoryPoints(
        const Pose2d& initial,
        const std::vector<Translation2d>& interiorWaypoints,
        const Pose2d& end
    ) : initial_(initial), interiorWaypoints_(interiorWaypoints), end_(end)
    {}
    frc::Trajectory AsGeneratedTrajectory(const TrajectoryConfig& config)
    {
        return frc::TrajectoryGenerator::GenerateTrajectory(
            initial_,
            interiorWaypoints_,
            end_,
            config
        );
    }
private:
    const Pose2d& initial_;
    const std::vector<Translation2d>& interiorWaypoints_;
    const Pose2d& end_;
};