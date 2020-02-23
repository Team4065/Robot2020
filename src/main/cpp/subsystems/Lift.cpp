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
void Lift::Periodic() {
    winchMotor.Set(winchMotorSpeed);
    adjustorMotor.Set(adjustorMotorSpeed);
}

void Lift::Extend(){
    m_solenoid.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Lift::ShortenWinch(){
    winchMotorSpeed = -1;
}

void Lift::LengthenWinch(){
    winchMotorSpeed = 1;
}

void Lift::StopWinch(){
    winchMotorSpeed = 0;
}

void Lift::MoveLeft(){
    adjustorMotorSpeed = 1;
}

void Lift::MoveRight(){
    adjustorMotorSpeed = -1;
}

void Lift::DontMove(){
    adjustorMotorSpeed = 0;
}