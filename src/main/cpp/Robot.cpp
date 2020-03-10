//TODO test shaped drivetraindecceleration
//TODO set up singleton lift
//TODO make lift commands
#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include <frc/controller/SimpleMotorFeedforward.h>
#include <cscore.h>
#include <cameraserver/CameraServer.h>

#include "commands/auto/paths/RunnableTrajectory.h"
#include "commands/auto/paths/Paths.h"

void Robot::RobotInit() {
    compressor.Start();
    cs::UsbCamera camera_;
    camera_ = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    camera_.SetFPS(40);
    camera_.SetResolution(320, 240);

    m_chooser.AddOption("Left", Pos::LEFT);
    m_chooser.AddOption("Right", Pos::RIGHT);
    m_chooser.AddOption("Center", Pos::CENTER);
    m_chooser.SetDefaultOption("No Auto", Pos::NONE);

    //frc::SmartDashboard::PutData("Auto Modes", &m_container.chooser_);
    // m_container.chooser_.AddOption(kRightRendevousAuto, kRightRendevousAuto);
    // m_container.chooser_.AddOption(kLeftRendevousAuto, kLeftRendevousAuto);
    // m_container.chooser_.AddOption(kTrenchAuto, kTrenchAuto);

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

    Pos startPos = m_chooser.GetSelected();
    switch (startPos)
    {
    case LEFT:
        m_autonomousCommand = m_container.GetTrenchAuto();
        break;

    case RIGHT:
        m_autonomousCommand = m_container.GetRightRendevousAuto();
        break;

    case CENTER:
        m_autonomousCommand = m_container.GetLeftRendevousAuto();
        break;

    default:
        m_autonomousCommand = m_container.GetNoAuto();
        break;
    }

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
