/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/PrintCommand.h>

#include "subsystems/Drivetrain.h"
#include "commands/auto/paths/StraightLineTest.h"
#include <iostream>
#include "subsystems/ReferencedTunable.h"


void Robot::RobotInit() {
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
}

frc::Trajectory Robot::GetTrajectory()
{
  return frc::TrajectoryGenerator::GenerateTrajectory(
    frc::Pose2d(0_ft, 0_ft, frc::Rotation2d(0_deg)),
    {
      frc::Translation2d(2_ft, 2_ft),
      frc::Translation2d(6_ft, -2_ft)
    },
    frc::Pose2d(8_ft, 0_ft, frc::Rotation2d(0_deg)),
    constants::drivetrain::kAutoConfig
  );
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  frc2::RamseteCommand ramsete_command_(
        GetTrajectory(), [&]() { return Drivetrain::GetInstance().GetPose(); },
        frc::RamseteController(constants::drivetrain::auto_mode::kRamseteB,
                               constants::drivetrain::auto_mode::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(
            constants::drivetrain::kS, constants::drivetrain::kV, constants::drivetrain::kA),
        constants::drivetrain::kDriveKinematics,
        [&] { return Drivetrain::GetInstance().GetWheelSpeeds(); std::cout << "Getting wheel speeds...\n"; },
        frc2::PIDController(1.8, 0, 0),
        frc2::PIDController(1.8, 0, 0),
        [&](auto left, auto right) { Drivetrain::GetInstance().TankDriveVolts(left, right); std::cout << "Running...\n"; },
    {&Drivetrain::GetInstance()});

  auto command_ = new frc2::SequentialCommandGroup(
    frc2::PrintCommand("Starting Ramsete..."),
    std::move(ramsete_command_),
    frc2::PrintCommand("Ending Ramsete... Stopping!"),
    frc2::InstantCommand([&] { Drivetrain::GetInstance().TankDriveVolts(0_V, 0_V); })
  );

  command_->Schedule();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  frc4065::ReferencedTunable::UpdateAll();
  frc::SmartDashboard::PutNumber("LeftEncoder", Drivetrain::GetInstance().GetLeftEncoderDistance().to<double>());
  //std::cout << Drivetrain::GetInstance().GetLeftEncoderDistance().to<double>() << std::endl;
  frc::SmartDashboard::PutNumber("RightEncoder", Drivetrain::GetInstance().GetRightEncoderDistance().to<double>());
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
