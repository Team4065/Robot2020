#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <rev/CANSparkMax.h>
#include <rev/CANPIDController.h>
#include <rev/CANSparkMaxHeartbeat.h>

#include "RobotContainer.h"



class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;

  RobotContainer m_container;

  rev::CANSparkMax left1 { 1 };
  rev::CANSparkMax left2 { 2 };

  rev::CANSparkMax right1 { 3 };
  rev::CANSparkMax right2 { 4 };

  frc::XboxController controller { 0 };
};