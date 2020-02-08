#include "subsystems/Intake.h"

// This method will be called once per scheduler run
void Intake::Periodic() {}

Intake& Intake::GetInstance()
{
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

void Intake::Suck(){
    motor.Set(kMotorOperatingPercentage);
}

void Intake::DontSuck(){
    motor.Set(0);
}

void Intake::Retract(){
    leftSolenoid.Set(frc::DoubleSolenoid::kForward);
    rightSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Intake::Extend(){
    leftSolenoid.Set(frc::DoubleSolenoid::kReverse);
    rightSolenoid.Set(frc::DoubleSolenoid::kReverse);
}