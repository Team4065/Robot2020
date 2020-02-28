/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
    leftSlave.Follow(leftMaster);
    rightSlave.Follow(rightMaster);
    
    leftMaster.RestoreFactoryDefaults();
    rightMaster.RestoreFactoryDefaults();

    ReferencedTunable::Register("left drivetrain percent", leftPercent);
    ReferencedTunable::Register("right drivetrain percent", rightPercent);
    ReferencedTunable::Register("left drivetrain target", leftTarget);
    ReferencedTunable::Register("right drivetrain target", rightTarget);
    ReferencedTunable::Register("Drivetrain control type", controlType);
    ReferencedTunable::Register("Drivetrain inversion", isInverted);
    ReferencedTunable::Register("Drivetrain is percent controlled", isPercentControlled);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {
    leftMaster.SetInverted(!isInverted);
    rightMaster.SetInverted(isInverted);

    if(isPercentControlled){
        leftMaster.Set(leftPercent);
        rightMaster.Set(rightPercent);
    }else{
        leftPID.SetReference(leftTarget, controlType);
        rightPID.SetReference(rightTarget, controlType);
    }
}

float Drivetrain::getLeftEncoder(EncoderDataType type){
    switch(type){
        case EncoderDataType::Velocity:
            return leftEncoder.GetVelocity();
            break;
        case EncoderDataType::Position:
            return leftEncoder.GetPosition();
            break;
    }
}

float Drivetrain::getRightEncoder(EncoderDataType type){
    switch(type){
        case EncoderDataType::Velocity:
            return rightEncoder.GetVelocity();
            break;
        case EncoderDataType::Position:
            return rightEncoder.GetPosition();
            break;
    }
}