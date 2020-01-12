#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    left_.RestoreFactoryDefaults();
    right_.RestoreFactoryDefaults();

    left_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    right_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    left_.SetSmartCurrentLimit(constants::shooter::kMaxCurrentDraw.to<unsigned int>()); 
    right_.SetSmartCurrentLimit(constants::shooter::kMaxCurrentDraw.to<unsigned int>()); 

    left_pid_.SetP(constants::shooter::kP);
    left_pid_.SetI(0.0); // Disable
    left_pid_.SetD(constants::shooter::kD);
    left_pid_.SetFF(constants::shooter::kFF);
}

void Shooter::ShootWithDistanceEstimation(units::foot_t distanceToTarget)
{
    // 1. Turn a distance into a velocity using numerical analysis.
    // 2. Set shooter to that velocity.
}

void Shooter::SetShooterVelocity(units::radians_per_second_t angularVelocity)
{
    state_ = State::SPINUP;
    // 1. Calculate motor velocity from rad/s and wheel radius.
}

Shooter::State Shooter::GetState() const
{
    return state_;
}

// units::radians_per_second_t Shooter::GetVelocity() const
// {
// }

units::radians_per_second_t Shooter::GetDesiredVelocity() const
{
    return desired_velocity_;
}

void Shooter::Periodic()
{
    if (state_ == SPINUP)
        if (std::abs(desired_velocity_.to<double>() - GetVelocity().to<double>())
            / (desired_velocity_.to<double>() + GetVelocity().to<double>()) / 2 < constants::shooter::kAllowableVelocityError)
            state_ = State::SHOOTING;
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}