/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanelManipulator.h"

ControlPanelManipulator& ControlPanelManipulator::GetInstance()
{
    static ControlPanelManipulator instance;
    return instance;
}

// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {}
