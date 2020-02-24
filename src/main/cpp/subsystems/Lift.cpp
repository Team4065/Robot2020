/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"

Lift::Lift()
{
    // master_encoder_.SetPositionConversionFactor();
    // slave_encoder_.SetPositionConversionFactor();
    master_encoder_.SetInverted(false);
    slave_encoder_.SetInverted(false);
}

Lift& Lift::GetInstance(){
    static Lift instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

// This method will be called once per scheduler run
void Lift::Periodic()
{
    // Add safety check that motors are the same, lead screws can bind and break if they are not within a certain
    // tolerance.
}

void Lift::Extend(){
    solenoid_.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    solenoid_.Set(frc::DoubleSolenoid::kReverse);
}

units::foot_t Lift::GetHeight()
{
    return units::foot_t(master_encoder_.GetPosition());
}