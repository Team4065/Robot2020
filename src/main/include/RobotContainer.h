#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/buttons/Trigger.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/PrintCommand.h>
//
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>

//
#include "subsystems/Shooter.h"
#include "subsystems/Serializer.h"
#include "subsystems/Intake.h"
#include "subsystems/Lift.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/ControlPanelManipulator.h"

#include "commands/drivetrain/TankDrive.h"

#include "commands/shooter/PreSpinup.h"
#include "commands/shooter/TimedShoot.h"

#include "commands/Intake/ToggleIntake.h"
#include "commands/Intake/IdleIntake.h"
#include "commands/Intake/ReverseIntake.h"
#include "commands/Intake/ToggleSuckState.h"
#include "commands/Intake/ToggleDeployState.h"

#include "commands/Serializer/VBeltForward.h"

#include "commands/Serializer/VBeltOff.h"

#include "commands/TrackThenAlign.h"

#include "commands/lift/IdleLift.h"
#include "commands/lift/MoveDown.h"
#include "commands/lift/MoveUp.h"
#include "commands/lift/ToggleLiftPiston.h"
#include "commands/lift/DeployLift.h"
#include "commands/lift/StowLift.h"

#include "commands/drivetrain/VisionAlign.h"
#include "commands/TrackThenAlign.h"

#include "frc2/command/button/JoystickButton.h"


#include "Constants.h"

#define GEN_BUTTON(name, controller, btn) frc2::JoystickButton name { &controller, btn }
#define GEN_BUTTON_MAIN_CONTROLLER(name, btn) GEN_BUTTON(name, controller_, btn)
//#define GEN_BUTTON_SECONDARY_CONTROLLER(name, btn) GEN_BUTTON(name, controller2_, btn)

class AxisButton : public frc2::Button
{
public:
  AxisButton(frc::XboxController* controller, int id, double threshold)
  : Button([&]{ return controller->GetRawAxis(id) >= threshold; }),
  controller_(controller), id_(id), threshold_(threshold) {}
private:
  frc::XboxController* controller_;
  int id_;
  double threshold_;
};

class RobotContainer
{
public:
  RobotContainer();
  Intake& intake_ = Intake::GetInstance();
  Shooter& shooter_ = Shooter::GetInstance(); 
  Serializer& serializer_ = Serializer::GetInstance();//V-Belt
  Lift& lift_ = Lift::GetInstance();
  Drivetrain& drivetrain_ = Drivetrain::GetInstance();
  ControlPanelManipulator& control_panel_manipulator_ = ControlPanelManipulator::GetInstance();

  frc::XboxController controller_ { constants::oi::kDriverXboxControllerPort };
  frc::Joystick buttonBox_ {constants::oi::kBottonBox};

  //frc::XboxController controller2_ {1};

  GEN_BUTTON_MAIN_CONTROLLER(y_btn_, (int)frc::XboxController::Button::kY);
  GEN_BUTTON_MAIN_CONTROLLER(a_btn_, (int)frc::XboxController::Button::kA);
  GEN_BUTTON_MAIN_CONTROLLER(x_btn_, (int)frc::XboxController::Button::kX);
  GEN_BUTTON_MAIN_CONTROLLER(b_btn_, (int)frc::XboxController::Button::kB);
  GEN_BUTTON_MAIN_CONTROLLER(rb_btn_, (int)frc::XboxController::Button::kBumperRight);
  GEN_BUTTON_MAIN_CONTROLLER(lb_btn_, (int)frc::XboxController::Button::kBumperLeft);
  GEN_BUTTON_MAIN_CONTROLLER(sl_btn_, (int)frc::XboxController::Button::kStickLeft);
  GEN_BUTTON_MAIN_CONTROLLER(sr_btn_, (int)frc::XboxController::Button::kStickRight);
  GEN_BUTTON_MAIN_CONTROLLER(start_btn_, (int)frc::XboxController::Button::kStart);
  GEN_BUTTON_MAIN_CONTROLLER(back_btn_, (int)frc::XboxController::Button::kBack);
  AxisButton lt_btn_ {&controller_, 2, 0.5};
  AxisButton rt_btn_ {&controller_, 3, 0.5};

  //Button Box
  // frc2::JoystickButton blueRight_ { &controller, btn }
  GEN_BUTTON(moveLiftUp_, buttonBox_, (int)constants::button_box::blueRight);
  GEN_BUTTON(moveLiftDown_, buttonBox_, (int)constants::button_box::blueLeft);
  GEN_BUTTON(deployLift_, buttonBox_, (int)constants::button_box::greenRight);
  GEN_BUTTON(stowLift_, buttonBox_, (int)constants::button_box::greenLeft);
  GEN_BUTTON(spinCntrlPanelContinuously_, buttonBox_, (int)constants::button_box::yellowRight);
  GEN_BUTTON(spinCntrlPanelFixedRevs_, buttonBox_, (int)constants::button_box::yellowLeft);
  GEN_BUTTON(increaseShooterSpeed_, buttonBox_, (int)constants::button_box::redRight);
  GEN_BUTTON(decreaseShooterSpeed_, buttonBox_, (int)constants::button_box::redLeft);

  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_y_btn_, 4);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_a_btn_, 1);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_x_btn_, 3);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_b_btn_, 2);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_rb_btn_, 6);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_lb_btn_, 5);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_sl_btn_, 9);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_sr_btn_, 10);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_start_btn_, 8);
  // GEN_BUTTON_SECONDARY_CONTROLLER(sec_back_btn_, 7);

  frc2::Command* GetAutonomousCommand();
  std::string kLeftRendevousAuto = "Left Rendevous Auto (5 ball)";
  std::string kRightRendevousAuto = "Right Rendevous Auto (5 ball)";
  std::string kTrenchAuto = "Trench Auto (6 ball)";
  std::string kNoAuto = "No Auto (0 ball)";
  frc::SendableChooser<std::string> chooser_; 
  frc2::InstantCommand NoAuto {};
  frc2::Command* GetLeftRendevousAuto();
  frc2::Command* GetRightRendevousAuto();
  frc2::Command* GetTrenchAuto();
  frc2::Command* GetNoAuto();
private:
  
  void ConfigureButtonBindings();
};
