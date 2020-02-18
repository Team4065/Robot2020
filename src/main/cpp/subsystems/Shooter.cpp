#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    right_slave_.Follow(left);
    left_master_.SetInverted(ctre::phoenix::motorcontrol::InvertType::None);
    right.SetInverted(ctre::phoenix::motorcontrol::InvertType::OpposeMaster);

    left_master_.Config_kP(kP);
    left_master_.Config_kI(0);
    left_master_.Config_kD(kD);
    left_master_.Config_kF(kF);

    right_slave_.Config_kP(kP);
    right_slave_.Config_kI(0);
    right_slave_.Config_kD(kD);
    right_slave_.Config_kF(kF);

    left_master_.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::TalonFXFeedbackDevice::IntegratedSensor, 0, 0);
    right_slave_.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::TalonFXFeedbackDevice::IntegratedSensor, 0, 0);
}

double Shooter::GetSensorVelocity(){
    return left.GetSelectedSensorVelocity();
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
    if(angularVelocity == 0_rpm)
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

void Shooter::Periodic()
{

}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;  // Guaranteed to be destroyed.
    return instance;
}