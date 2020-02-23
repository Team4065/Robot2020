#include "subsystems/Intake.h"

// This method will be called once per scheduler run
void Intake::Periodic() {
    m_motor.Set(m_motorSpeed);       //Run in peeriodic loop so that the watchdog timer doesn't reset
}

Intake& Intake::GetInstance()
{
    static Intake instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

void Intake::Suck(){
    m_motorSpeed = kMotorOperatingPercentage;
    std::cout << "Suck" << std::endl;
}

void Intake::DontSuck(){
    m_motorSpeed = 0;
    std::cout << "Don't Suck" << std::endl;
}

void Intake::Retract(){
    m_solenoid.Set(frc::DoubleSolenoid::kForward);
    m_isDeployed = false;
    //rightSolenoid.Set(frc::DoubleSolenoid::kForward);
    std::cout << "Deploy Intake" << std::endl;
}

void Intake::Extend(){
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
    m_isDeployed = true;
    //rightSolenoid.Set(frc::DoubleSolenoid::kReverse);
    std::cout << "Retract Intake" << std::endl;
}