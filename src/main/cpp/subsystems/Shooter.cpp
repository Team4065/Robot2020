#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    right_slave_.Follow(left_master_);
    left_master_.SetInverted(ctre::phoenix::motorcontrol::InvertType::None);
    right_slave_.SetInverted(ctre::phoenix::motorcontrol::InvertType::InvertMotorOutput);

    left_master_.ConfigOpenloopRamp(1.2);
    right_slave_.ConfigOpenloopRamp(1.2);

    left_master_.Config_kP(0, constants::shooter::kP);
    left_master_.Config_kI(0, 0);
    left_master_.Config_kD(0, constants::shooter::kD);
    left_master_.Config_kF(0, constants::shooter::kFF);

    right_slave_.Config_kP(0, constants::shooter::kP);
    right_slave_.Config_kI(0, 0);
    right_slave_.Config_kD(0, constants::shooter::kD);
    right_slave_.Config_kF(0, constants::shooter::kFF);

    left_master_.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 0);
    right_slave_.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 0);
}

double Shooter::GetSensorVelocity(){
    return left_master_.GetSelectedSensorVelocity();
}

void Shooter::ShootWithDistanceEstimation(units::foot_t distanceToTarget)
{   
    /*
    // 1. Turn a distance into a velocity using numerical analysis.
    // 2. Set shooter to that velocity.
    if (distanceToTarget > constants::shooter::kDistanceUpperBound || distanceToTarget < constants::shooter::kDistanceLowerBound)
        INFO_LOG("Current distance to target is out of bounds.");
    
    units::revolutions_per_minute_t rpm_estimation = 0_rpm;

    SetShooterVelocity(rpm_estimation);
    */
}

void Shooter::SetShooterVelocity(units::revolutions_per_minute_t angularVelocity)
{
    // 1. Calculate motor velocity from rpm and wheel radius.
    desired_velocity_ = angularVelocity;
    left_master_.Set(ControlMode::Velocity, angularVelocity.to<double>() * 2048 / 60 / 100);
}

void Shooter::DisableKicker()
{
    kicker_on_ = false;
    kicker_motor_.Set(0.0);
}

void Shooter::EngageKicker()
{
    kicker_on_ = true;
    kicker_motor_.Set(constants::shooter::kKickerSpeed);
}

void Shooter::EngageFeeder()
{
    feeder_on_ = true;
    feeder_motor_.Set(constants::shooter::kFeederSpeed);
}

void Shooter::DisableFeeder()
{
    feeder_on_ = false;
    feeder_motor_.Set(0.0);
}

bool Shooter::IsFeederActive() const
{
    return feeder_on_;
}

bool Shooter::IsKickerActive() const
{
    return kicker_on_;
}

units::revolutions_per_minute_t Shooter::GetVelocityError() const
{
    return units::revolutions_per_minute_t( std::abs((desired_velocity_ - GetVelocity()).to<double>()) );
}

units::revolutions_per_minute_t Shooter::GetVelocity() const
{
    return 0_rpm;
}

units::revolutions_per_minute_t Shooter::GetDesiredVelocity() const
{
    return desired_velocity_;
}

bool Shooter::AtDesiredVelocity() const
{
    return GetVelocityError() < constants::shooter::kAllowableSpinupVelocityError;
}

bool Shooter::AtDesiredVelocityWithHysteresis() const
{
    return GetVelocityError() < constants::shooter::kAllowableShootingVelocityError;
}

void Shooter::Periodic()
{
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}