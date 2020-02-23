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
    m_motorpid.SetD(0.0, 0);
    m_motorpid.SetI(0.0, 0);
    m_motorpid.SetP(1.0, 0);

    m_isDeployed = false;
}

// void ControlPanelManipulator::move_m_motorclockwise() {
//     m_motor.SetVoltage(constants::control_panel_manipulator::ControlPanelClockwiseVoltage);
// }

// void ControlPanelManipulator::move_m_motorcounterclockwise() {
//     m_motor.SetVoltage(constants::control_panel_manipulator::ControlPanelCounterClockwiseVoltage);
// }

void ControlPanelManipulator::DeployCPM() {
    // deployMotorPID_.SetReference(control_panel_manipulator.DeployPosition, rev::ControlType::kPosition, 0, 0);
    m_isDeployed = true;
}

void ControlPanelManipulator::StowCPM() {
    // deployMotorPID_.SetReference(control_panel_manipulator.StowPosition, rev::ControlType::kPosition, 0, 0);
    m_isDeployed = false;
}

double ControlPanelManipulator::read_encoder_position() {
    return(m_encoder.GetPosition());
}

void ControlPanelManipulator::setPosition(double position) {
    m_motorpid.SetReference(position, rev::ControlType::kPosition, 0, 0);
}