#include "commands/auto/paths/RunnableTrajectory.h"
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>

RunnableTrajectory::RunnableTrajectory(TrajectoryPoints& traj_pts) : traj_pts_(std::move(traj_pts))
{
    AddRequirements({&Drivetrain::GetInstance()});
}

void RunnableTrajectory::Initialize()
{
    frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          constants::drivetrain::kS,
          constants::drivetrain::kV,
          constants::drivetrain::kA),
      constants::drivetrain::kDriveKinematics,
      10_V);

    frc::TrajectoryConfig config(constants::drivetrain::auto_mode::kMaxVelocity, constants::drivetrain::auto_mode::kMaxAcceleration);
    // Add kinematics to ensure max speed is actually obeyed
    config.SetKinematics(constants::drivetrain::kDriveKinematics);
    // Apply the voltage constraint
    config.AddConstraint(autoVoltageConstraint);

    ramsete_command_ = new frc2::RamseteCommand(
        traj_pts_.AsGeneratedTrajectory(config), [&]() { return Drivetrain::GetInstance().GetPose(); },
        frc::RamseteController(constants::drivetrain::auto_mode::kRamseteB,
                               constants::drivetrain::auto_mode::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(
            constants::drivetrain::kS, constants::drivetrain::kV, constants::drivetrain::kA),
        constants::drivetrain::kDriveKinematics,
        [&] { return Drivetrain::GetInstance().GetWheelSpeeds(); },
        frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
        frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
        [&](auto left, auto right) { Drivetrain::GetInstance().TankDriveVolts(left, right); },
    {&Drivetrain::GetInstance()});

    AddCommands(
        std::move(*ramsete_command_),
        frc2::InstantCommand([&] { Drivetrain::GetInstance().TankDriveVolts(0_V, 0_V); })
    );
}

bool RunnableTrajectory::IsFinished()
{
    return ramsete_command_->IsFinished();
}