/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Serializer.h"

Serializer::Serializer() {}

Serializer& Serializer::GetInstance()
{
    static Serializer instance;
    return instance;
}

// This method will be called once per scheduler run
void Serializer::Periodic() {}
