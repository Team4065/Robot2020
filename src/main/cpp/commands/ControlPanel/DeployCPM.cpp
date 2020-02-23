/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanel/DeployCPM.h"
using namespace constants::control_panel_manipulator;

DeployCPM::DeployCPM(ControlPanelManipulator& controlPanelManipulator) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&controlPanelManipulator});
}

// Called when the command is initially scheduled.
void DeployCPM::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void DeployCPM::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "DeployCPM Command Executing" << std::endl;
#endif    
  ControlPanelManipulator::GetInstance().setPosition(DeployPosition);
}

// Called once the command ends or is interrupted.
void DeployCPM::End(bool interrupted) {}

// Returns true when the command should end.
bool DeployCPM::IsFinished() { return true; }
