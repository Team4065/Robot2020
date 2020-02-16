#include "subsystems/Intake.h"

// This method will be called once per scheduler run
void Intake::Periodic() {
    motor.Set(motorSpeed);       //Run in peeriodic loop so that the watchdog timer doesn't reset
}

Intake& Intake::GetInstance()
{
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

void Intake::Suck(){
    motorSpeed = kMotorOperatingPercentage;
    std::cout << "Suck" << std::endl;
}

void Intake::DontSuck(){
    motorSpeed = 0;
    std::cout << "Don't Suck" << std::endl;
}

void Intake::Retract(){
    solenoid.Set(frc::DoubleSolenoid::kForward);
    isDeployed_ = false;
    //rightSolenoid.Set(frc::DoubleSolenoid::kForward);
    std::cout << "Deploy Intake" << std::endl;
}

void Intake::Extend(){
    solenoid.Set(frc::DoubleSolenoid::kReverse);
    isDeployed_ = true;
    //rightSolenoid.Set(frc::DoubleSolenoid::kReverse);
    std::cout << "Retract Intake" << std::endl;
}