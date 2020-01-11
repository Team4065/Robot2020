#include "subsystems/Drivetrain.h"

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

Drivetrain& Drivetrain::GetInstance()
{
    static Drivetrain instance;  // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}
