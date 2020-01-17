#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    left_.RestoreFactoryDefaults();
    right_.RestoreFactoryDefaults();

    left_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    right_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    left_.Follow(right_, true);

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
    if (distanceToTarget > constants::shooter::kDistanceUpperBound || distanceToTarget < constants::shooter::kDistanceLowerBound)
        INFO_LOG("Current distance to target is out of bounds.");
    
    units::revolutions_per_minute_t rpm_estimation = 0_rpm;

    SetShooterVelocity(rpm_estimation);
}

void Shooter::SetShooterVelocity(units::revolutions_per_minute_t angularVelocity)
{
    if(angularVelocity == 0)
        state_ = State::IDLE;
    else
        state_ = State::SPINUP;

    // 1. Calculate motor velocity from rpm and wheel radius.
    desired_velocity_ = angularVelocity;
}


Shooter::State Shooter::GetState() const
{
    return state_;
}

units::revolutions_per_minute_t Shooter::GetVelocity() const
{
    return units::revolutions_per_minite_t(0.0);
}

units::revolutions_per_minute_t Shooter::GetDesiredVelocity() const
{
    return desired_velocity_;
}

void Shooter::Periodic()
{

    switch(state_){
        case State::SPINUP:
            // Poll velocity so when we get up to speed we can start shooting.
            if (std::abs( (desired_velocity_ - GetVelocity()).to<double>() ) < constants::shooter::kAllowableVelocityError)
                state_ = State::SHOOTING;
            
            //
            break;

        case State::SHOOTING:
            // Makes sure while shooting we aren't below the allowable velocity error
            if (std::abs( (desired_velocity_ - GetVelocity()).to<double>() ) > constants::shooter::kAllowableVelocityError)
                state_ = State::SPINUP;
            
            break;

        case State::IDLE:
            right_pid_.SetReference(desired_velocity_, rev::ControlType::kVelocity);
            break;

    }
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}