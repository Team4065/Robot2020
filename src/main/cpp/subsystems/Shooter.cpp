#include "subsystems/Shooter.h"

// This method will be called once per scheduler run
void Shooter::Periodic() {}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}