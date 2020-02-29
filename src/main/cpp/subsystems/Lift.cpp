/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"

Lift::Lift()
{
    lift_master_.RestoreFactoryDefaults();
    lift_master_.ClearFaults();
    lift_slave_.RestoreFactoryDefaults();
    lift_slave_.ClearFaults();

    master_encoder_.SetPositionConversionFactor(constants::lift::kTurnToInches.to<double>() / 12);
    slave_encoder_.SetPositionConversionFactor(constants::lift::kTurnToInches.to<double>() / 12);
    lift_master_.SetSmartCurrentLimit(constants::lift::kMaxCurrentDraw.to<double>());
    lift_slave_.SetSmartCurrentLimit(constants::lift::kMaxCurrentDraw.to<double>());
    lift_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    lift_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    lift_master_.SetInverted(false);
    lift_slave_.SetInverted(false);

    master_pid_.SetP(1);
    slave_pid_.SetP(1);

    // master_encoder_.SetInverted(false);
    // slave_encoder_.SetInverted(false);

    master_pid_.SetSmartMotionAccelStrategy(rev::CANPIDController::AccelStrategy::kSCurve);
    slave_pid_.SetSmartMotionAccelStrategy(rev::CANPIDController::AccelStrategy::kSCurve);
    //master_pid_.SetSmartMotionMaxAccel(constants::lift::kMaxAcceleration * 60)

    solenoid_.Set(frc::DoubleSolenoid::Value::kReverse);

    initial_delta_position_ = GetEncAPos() - GetEncBPos();
    std::cout << "initial_delta_position_ = " << initial_delta_position_ << std::endl;

}

Lift& Lift::GetInstance(){
    static Lift instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
}

// This method will be called once per scheduler run
void Lift::Periodic()
{
    // Add safety check that motors are the same, lead screws can bind and break if they are not within a certain
    // tolerance.
}

void Lift::Extend(){
    solenoid_.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    solenoid_.Set(frc::DoubleSolenoid::kReverse);
}

void Lift::SetHeight(units::foot_t height)
{
    
}

units::foot_t Lift::GetHeight()
{
    return units::foot_t(master_encoder_.GetPosition());
}

void Lift::MovePercent(double percent){
    lift_master_.Set(percent);
    lift_slave_.Set(percent);  
}

void Lift::SetAPosition(double position) {
    master_pid_.SetReference(position, rev::ControlType::kPosition);
}

void Lift::SetBPosition(double position) {
    slave_pid_.SetReference(position - initial_delta_position_, rev::ControlType::kPosition);
}