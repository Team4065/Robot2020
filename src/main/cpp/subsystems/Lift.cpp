/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"

Lift& Lift::GetInstance(){
    static Lift instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

// This method will be called once per scheduler run
void Lift::Periodic() {}

void Lift::Extend(){
    left.Set(frc::DoubleSolenoid::kForward);
    right.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    left.Set(frc::DoubleSolenoid::kReverse);
    right.Set(frc::DoubleSolenoid::kReverse);
}

void Lift::ShortenWinch(){
    motor.Set(-1);
}

void Lift::LengthenWinch(){
    motor.Set(1);
}

void Lift::StopWinch(){
    motor.Set(0);
}