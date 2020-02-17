/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanel/StowCPM.h"
using namespace constants::control_panel_manipulator::control_panel_manipulator;

StowCPM::StowCPM(ControlPanelManipulator& controlPanelManipulator) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&controlPanelManipulator});
}

// Called when the command is initially scheduled.
void StowCPM::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void StowCPM::Execute() {
    ControlPanelManipulator::GetInstance().setPosition(StowPosition);
}

// Called once the command ends or is interrupted.
void StowCPM::End(bool interrupted) {}

// Returns true when the command should end.
bool StowCPM::IsFinished() { return true; }
