#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/buttons/Trigger.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
//
#include <frc/XboxController.h>
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

#include "commands/Serializer/VBeltForward.h"

#include "commands/Serializer/VBeltOff.h"

#include "commands/TrackThenAlign.h"

#include "commands/lift/IdleLift.h"
#include "commands/lift/MoveDown.h"
#include "commands/lift/MoveUp.h"
#include "commands/lift/ToggleLiftPiston.h"

#include "commands/drivetrain/VisionAlign.h"
#include "commands/TrackThenAlign.h"

#include "frc2/command/button/JoystickButton.h"


#include "Constants.h"

#define GEN_BUTTON(name, controller, btn) frc2::JoystickButton name { &controller, btn }
#define GEN_BUTTON_MAIN_CONTROLLER(name, btn) GEN_BUTTON(name, controller_, btn)

class AxisButton : public frc::Trigger
{
public:
  AxisButton(frc::XboxController* controller, int id, double threshold)
  : controller_(controller), id_(id), threshold_(threshold) {}
  bool Get() override
  {
    return controller_->GetRawAxis(id_) >= threshold_;
  }
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

  GEN_BUTTON_MAIN_CONTROLLER(y_btn_, 4);
  GEN_BUTTON_MAIN_CONTROLLER(a_btn_, 1);
  GEN_BUTTON_MAIN_CONTROLLER(x_btn_, 3);
  GEN_BUTTON_MAIN_CONTROLLER(b_btn_, 2);
  GEN_BUTTON_MAIN_CONTROLLER(rb_btn_, 6);
  GEN_BUTTON_MAIN_CONTROLLER(lb_btn_, 5);
  GEN_BUTTON_MAIN_CONTROLLER(sl_btn_, 9);
  GEN_BUTTON_MAIN_CONTROLLER(sr_btn_, 10);
  GEN_BUTTON_MAIN_CONTROLLER(start_btn_, 8);
  GEN_BUTTON_MAIN_CONTROLLER(back_btn_, 7);
  AxisButton lt_btn_ {&controller_, 2, 0.5};
  AxisButton rt_btn_ {&controller_, 3, 0.5};

  frc2::Command* GetAutonomousCommand();

private:
  frc::SendableChooser<frc2::Command*> chooser_; // Give options for autonomous actions

  void ConfigureButtonBindings();
};
