#include "commands/auto/paths/RunnableTrajectoryBase.h"

void RunnableTrajectoryBase::Run()
{
    frc2::RamseteCommand ramsete_command_(
        GetTrajectory(), [this]() { return Drivetrain::GetInstance().GetPose(); },
        frc::RamseteController(constants::drivetrain::auto_mode::kRamseteB,
                               constants::drivetrain::auto_mode::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(
            constants::drivetrain::kS, constants::drivetrain::kV, constants::drivetrain::kA),
        constants::drivetrain::kDriveKinematics,
        [this] { return Drivetrain::GetInstance().GetWheelSpeeds(); },
        frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
        frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
        [this](auto left, auto right) { Drivetrain::GetInstance().TankDriveVolts(left, right); },
    {&Drivetrain::GetInstance()});

    command_ = frc2::SequentialCommandGroup(
        std::move(ramsete_command_),
        frc2::InstantCommand([&] { Drivetrain::GetInstance().TankDriveVolts(0_V, 0_V); })
    );
}

bool RunnableTrajectoryBase::Done() const
{
    return command_.IsFinished();
}