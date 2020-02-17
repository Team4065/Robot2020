/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanelManipulator.h"

using namespace constants;

ControlPanelManipulator& ControlPanelManipulator::GetInstance()
{
    static ControlPanelManipulator instance;
    return instance;
}

// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {


}

// std::pair<frc::Color, double> GetColorAndConfidence()
// {
//     static double confidence_ = 0.0;
//     frc::Color detected_ = color_sensor_.GetColor();
//     frc::Color matched_color_  color_matcher_.MatchClosestColor(detected_, confidence_);

//     return { matched_color_, confidence_ };
// }

ControlPanelManipulator::ControlPanelManipulator() {
    // color_matcher_.AddColorMatch(kBlueTarget);
    // color_matcher_.AddColorMatch(kYellowTarget);
    // color_matcher_.AddColorMatch(kRedTarget);
    // color_matcher_.AddColorMatch(kGreenTarget);
    motor_pid_.SetD(0.0, 0);
    motor_pid_.SetI(0.0, 0);
    motor_pid_.SetP(1.0, 0);
}

// void ControlPanelManipulator::move_motor_clockwise() {
//     motor_.SetVoltage(constants::control_panel_manipulator::ControlPanelClockwiseVoltage);
// }

// void ControlPanelManipulator::move_motor_counterclockwise() {
//     motor_.SetVoltage(constants::control_panel_manipulator::ControlPanelCounterClockwiseVoltage);
// }

void DeployCPM() {
    deployMotorPID_.SetReference(control_panel_manipulator.DeployPosition, rev::ControlType::kPosition, 0, 0);
}

void RetractCPM() {
    deployMotorPID_.SetReference(control_panel_manipulator.StowPosition, rev::ControlType::kPosition, 0, 0);
}

double ControlPanelManipulator::read_encoder_position() {
    return(encoder_.GetPosition());
}

void ControlPanelManipulator::setPosition(double position) {
    motor_pid_.SetReference(position, rev::ControlType::kPosition, 0, 0);
}