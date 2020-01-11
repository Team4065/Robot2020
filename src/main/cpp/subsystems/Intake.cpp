#include "subsystems/Intake.h"

// This method will be called once per scheduler run
void Intake::Periodic() {}

Intake& Intake::GetInstance()
{
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}