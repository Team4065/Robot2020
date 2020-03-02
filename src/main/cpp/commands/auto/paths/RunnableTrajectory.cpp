#include "commands/auto/paths/RunnableTrajectory.h"
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <iostream>
#include <frc2/command/PrintCommand.h>

RunnableTrajectory::RunnableTrajectory(TrajectoryPoints& traj_pts) : traj_pts_(std::move(traj_pts))
{
    Drivetrain* inst = &Drivetrain::GetInstance();
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

    frc::Trajectory traj_ = frc::TrajectoryGenerator::GenerateTrajectory(
        frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
        {},
        frc::Pose2d(1_m, 0_m, frc::Rotation2d(0_deg)),
        config
    );

    AddCommands(
        frc2::PrintCommand("Ramsete starting actually..."),
        frc2::RamseteCommand(
            traj_, [inst]() { return inst->GetPose(); },
            frc::RamseteController(constants::drivetrain::auto_mode::kRamseteB,
                                constants::drivetrain::auto_mode::kRamseteZeta),
            frc::SimpleMotorFeedforward<units::meters>(
                constants::drivetrain::kS, constants::drivetrain::kV, constants::drivetrain::kA),
            constants::drivetrain::kDriveKinematics,
            [inst] { return inst->GetWheelSpeeds(); },
            frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
            frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
            [inst](auto left, auto right) { std::cout << "Setting voltage\n";inst->TankDriveVolts(left, right); },
        {inst}),
        frc2::PrintCommand("Ramsete done..."),
        frc2::InstantCommand([&] { Drivetrain::GetInstance().TankDriveVolts(0_V, 0_V); })
    );
    std::cout << "Running Ramsete..." << std::endl;
}