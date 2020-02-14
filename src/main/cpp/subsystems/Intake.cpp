#include "subsystems/Intake.h"

// This method will be called once per scheduler run
void Intake::Periodic() {
    motor.Set(motorSpeed);
    if(isDeployed)
        Extend();
    else
        Retract();
}

Intake& Intake::GetInstance()
{
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

void Intake::Suck(){
    motorSpeed = kMotorOperatingPercentage;
}

void Intake::DontSuck(){
    motorSpeed = 0;
}

void Intake::Retract(){
    solenoid.Set(frc::DoubleSolenoid::kForward);
    //rightSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Intake::Extend(){
    solenoid.Set(frc::DoubleSolenoid::kReverse);
    //rightSolenoid.Set(frc::DoubleSolenoid::kReverse);
}