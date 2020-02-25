/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Serializer.h"

Serializer::Serializer() {
    motor_.SetInverted(true);
}

Serializer& Serializer::GetInstance()
{
    static Serializer instance;
    return instance;
}

void Serializer::Periodic() {}

void Serializer::Forward(){
    motor_.Set(constants::serializer::kIndexingSpeed);
}

void Serializer::Idle()
{
    motor_.Set(0.0);
}

void Serializer::Reverse()
{
    motor_.Set(constants::serializer::kAntiJamSpeed);
}