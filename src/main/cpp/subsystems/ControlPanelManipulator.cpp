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
void ControlPanelManipulator::Periodic() {

}

std::pair<frc::Color, double> GetColorAndConfidence() const
{
    static double confidence_ = 0.0;
    frc::Color detected_ = color_sensor_.GetColor();
    frc::Color matched_color_  color_matcher_.MatchClosestColor(detected_, confidence_);

    return { matched_color_, confidence_ };
}

void ControlPanelManipulator::ControlPanelManipulator() {
    color_matcher_.AddColorMatch(kBlueTarget);
    color_matcher_.AddColorMatch(kYellowTarget);
    color_matcher_.AddColorMatch(kRedTarget);
    color_matcher_.AddColorMatch(kGreenTarget);
}