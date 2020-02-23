/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanel/AutomaticallySpinControlPanel.h"
using namespace constants::control_panel_manipulator;

AutomaticallySpinControlPanel::AutomaticallySpinControlPanel(ControlPanelManipulator& controlPanelManipulator) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&controlPanelManipulator});
}

// Called when the command is initially scheduled.
void AutomaticallySpinControlPanel::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void AutomaticallySpinControlPanel::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "AutomaticallySpinControlPanel Command Executing" << std::endl;
#endif
  double currentPosition = ControlPanelManipulator::GetInstance().read_encoder_position();
  double desiredMotorRotations = Stage2Rotations * DiameterOfControlePanel/DiameterOfDriverWheel;

  double FinalPosition = currentPosition + desiredMotorRotations;

  ControlPanelManipulator::GetInstance().setPosition(FinalPosition);
}

// Called once the command ends or is interrupted.
void AutomaticallySpinControlPanel::End(bool interrupted) {}

// Returns true when the command should end.
bool AutomaticallySpinControlPanel::IsFinished() { return true; }
