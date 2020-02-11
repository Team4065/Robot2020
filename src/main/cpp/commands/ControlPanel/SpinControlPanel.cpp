/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanel/SpinControlPanel.h"
using namespace constants::control_panel_manipulator;

SpinControlPanel::SpinControlPanel(ControlPanelManipulator& controlPanelManipulator) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&controlPanelManipulator});
}

// Called when the command is initially scheduled.
void SpinControlPanel::Initialize() {
   initialPosition_ = ControlPanelManipulator::GetInstance().read_encoder_position();
}
// Called repeatedly when this Command is scheduled to run
void SpinControlPanel::Execute() {
    //double currentPosition = ControlPanelManipulator::GetInstance().read_encoder_position();
    double X = Rotations * DiameterOfControlePanel/DiameterOfDriverWheel;

    double FinalPosition = initialPosition_ + X;

    ControlPanelManipulator::GetInstance().setPosition(FinalPosition);
}

// Called once the command ends or is interrupted.
void SpinControlPanel::End(bool interrupted) {}

// Returns true when the command should end.
bool SpinControlPanel::IsFinished() { return false; }
