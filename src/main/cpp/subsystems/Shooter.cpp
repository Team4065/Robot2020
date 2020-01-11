#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    left_.RestoreFactoryDefaults();
    right_.RestoreFactoryDefaults();

    left_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    right_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);


}

void Shooter::Periodic() {}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}