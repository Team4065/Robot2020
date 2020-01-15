#pragma once

#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/Command.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/Trajectory.h>

#include "subsystems/Drivetrain.h"

#include "Constants.h"

class RunnableTrajectoryBase
{
public:
    RunnableTrajectoryBase() = default;
    void Run();
    bool Done() const;
protected:
    virtual frc::Trajectory GetTrajectory() = 0;
private:
    frc2::Command* command_;
};