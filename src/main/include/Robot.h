#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/Compressor.h>
<<<<<<< HEAD
=======
#include <frc/DoubleSolenoid.h>
>>>>>>> 02fb7851db9dc30a6522605a3b3cbdf744f7c77a

#include "RobotContainer.h"
#include "util/ReferencedTunable.h"

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
<<<<<<< HEAD
=======
  frc::DoubleSolenoid dummy1 { 0, 1 };
  frc::DoubleSolenoid dummy2 { 4, 5 };
>>>>>>> 02fb7851db9dc30a6522605a3b3cbdf744f7c77a
};