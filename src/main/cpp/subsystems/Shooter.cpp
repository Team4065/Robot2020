#include "subsystems/Shooter.h"

// This method will be called once per scheduler run
void Shooter::Periodic() {}

void Shooter::On(){
    left.Set(0.1);
    //right.Set(0); keep off until final testing to prevent the motor from fighting
}

void Shooter::Off(){
    left.Set(0);
    //right.Set(0);
}