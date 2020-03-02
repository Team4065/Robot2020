//TODO test shaped drivetraindecceleration
//TODO set up singleton lift
//TODO make lift commands
#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include <frc/controller/SimpleMotorFeedforward.h>

#include "commands/auto/paths/RunnableTrajectory.h"
#include "commands/auto/paths/Paths.h"

void Robot::RobotInit() {
    compressor.Start();
}
void Robot::RobotPeriodic()
{ 
    frc4065::ReferencedTunable::UpdateAll();
    frc2::CommandScheduler::GetInstance().Run(); 
}
void Robot::DisabledInit() {m_container.drivetrain_.NeutralMode(false);}
void Robot::DisabledPeriodic() {}
void Robot::AutonomousInit()
{
    m_container.drivetrain_.NeutralMode(true);
    m_autonomousCommand = m_container.GetAutonomousCommand();

    if (m_autonomousCommand != nullptr)
        m_autonomousCommand->Schedule();
}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
    // m_container.shooter_.EngageKicker();
    // m_container.shooter_.EngageFeeder();
    m_container.drivetrain_.NeutralMode(true);
}
void Robot::TeleopPeriodic()
{}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
