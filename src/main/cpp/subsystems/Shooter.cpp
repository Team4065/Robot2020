/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
    leftFlywheel.ConfigFactoryDefault();
    rightFlywheel.ConfigFactoryDefault();

    leftFlywheel.SetInverted(true);
    rightFlywheel.SetInverted(false);

    ReferencedTunable::Register("Shooter left target", leftTarget);
    ReferencedTunable::Register("Shooter right target", rightTarget);
    ReferencedTunable::Register("Shooter control mode", controlMode);
}

// This method will be called once per scheduler run
void Shooter::Periodic() {
    leftFlywheel.Set(controlMode, leftTarget);
    rightFlywheel.Set(controlMode, rightTarget);

    feederMotor.Set(feederPercent);
    kickerMotor.Set(kickerPercent);
}
