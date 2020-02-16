/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"

Lift::Lift(){
    heightMotorLeftPID.SetSmartMotionMaxVelocity(1);
    heightMotorRightPID.SetSmartMotionMaxVelocity(1);

    heightMotorLeftPID.SetSmartMotionMaxAccel(1);
    heightMotorRightPID.SetSmartMotionMaxAccel(1);

    heightMotorLeftPID.SetP(1);
    heightMotorRightPID.SetP(1);

    heightMotorLeftPID.SetI(0);
    heightMotorRightPID.SetI(0);

    heightMotorLeftPID.SetD(0);
    heightMotorRightPID.SetD(0);

    heightMotorLeftPID.SetFF(0);
    heightMotorRightPID.SetFF(0);
}

Lift& Lift::GetInstance(){
    static Lift instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

// This method will be called once per scheduler run
void Lift::Periodic() {
    heightMotorLeftPID.SetReference(liftTargetHeight, rev::kSmartMotion);
    heightMotorRightPID.SetReference(liftTargetHeight, rev::kSmartMotion);
    //adjustorMotor.Set(adjustorMotorSpeed);
}

void Lift::Extend(){
    solenoid.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    solenoid.Set(frc::DoubleSolenoid::kReverse);
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