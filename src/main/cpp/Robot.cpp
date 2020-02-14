//TODO test shaped drivetraindecceleration
//TODO set up singleton lift
//TODO make lift commands
#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include <frc/controller/SimpleMotorFeedforward.h>

void Robot::RobotInit() {}
void Robot::RobotPeriodic()
{ 
    frc4065::ReferencedTunable::UpdateAll();
    frc2::CommandScheduler::GetInstance().Run(); 

    //std::cout << std::boolalpha << m_container.intake_.isDeployed << std::endl;
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
