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
    dummy1.Set(frc::DoubleSolenoid::kForward);
    dummy2.Set(frc::DoubleSolenoid::kForward);
}
void Robot::RobotPeriodic()
{ 
    frc4065::ReferencedTunable::UpdateAll();
    frc2::CommandScheduler::GetInstance().Run(); 
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::AutonomousInit()
{
}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
    // m_container.shooter_.EngageKicker();
    // m_container.shooter_.EngageFeeder();
}
void Robot::TeleopPeriodic()
{}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
