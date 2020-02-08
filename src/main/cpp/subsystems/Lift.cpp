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
    leftPiston.Set(frc::DoubleSolenoid::kForward);
    rightPiston.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    leftPiston.Set(frc::DoubleSolenoid::kReverse);
    rightPiston.Set(frc::DoubleSolenoid::kReverse);
}

void Lift::ShortenWinch(){
    winchMotor.Set(-1);
}

void Lift::LengthenWinch(){
    winchMotor.Set(1);
}

void Lift::StopWinch(){
    winchMotor.Set(0);
}

void Lift::MoveLeft(){
    adjustorMotor.Set(1);
}

void Lift::MoveRight(){
    adjustorMotor.Set(-1);
}

void Lift::DontMove(){
    adjustorMotor.Set(0);
}