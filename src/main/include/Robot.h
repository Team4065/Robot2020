#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include "RobotContainer.h"
#include "util/ReferencedTunable.h"
#include <frc/SmartDashboard/SendableChooser.h>

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
  RobotContainer m_container;
 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;
  frc::Compressor compressor;
  frc::DoubleSolenoid dummy1 { 0, 1 };
  frc::DoubleSolenoid dummy2 { 4, 5 };
  // enum Pos {LEFT, CENTER, RIGHT, NONE};  //pick auto
  
  
  // const std::string kAutoDefault = "Default";
	// const std::string kAutoLeft = "My Auto Left";
	// const std::string kAutoMiddle = "My Auto Middle";
	// const std::string kAutoRight = "My Auto Right";
	// std::string m_autoSelected;
};