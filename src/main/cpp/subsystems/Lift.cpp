/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"
#include "util/Macros.h"
#include <iostream>
#include "util/ReferencedTunable.h"

using namespace frc4065;
using namespace constants;
using namespace std;

Lift::Lift()
{
    lift_master_.RestoreFactoryDefaults();
    lift_master_.ClearFaults();
    lift_slave_.RestoreFactoryDefaults();
    lift_slave_.ClearFaults();

    // master_encoder_.SetPositionConversionFactor(constants::lift::kTurnToInches.to<double>() / 12);
    // slave_encoder_.SetPositionConversionFactor(constants::lift::kTurnToInches.to<double>() / 12);
    lift_master_.SetSmartCurrentLimit(constants::lift::kMaxCurrentDraw.to<double>());
    lift_slave_.SetSmartCurrentLimit(constants::lift::kMaxCurrentDraw.to<double>());
    lift_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    lift_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    lift_master_.SetInverted(false);
    lift_slave_.SetInverted(false);

    kP_ = 0.3;
    kI_ = 0.00;
    ReferencedTunable::Register("Lift Move Down kI", kI_);

    master_pid_.SetP(kP_);
    slave_pid_.SetP(kP_);
    master_pid_.SetI(kI_);
    slave_pid_.SetI(kI_);

    // master_encoder_.SetInverted(false);
    // slave_encoder_.SetInverted(false);

    // master_pid_.SetSmartMotionAccelStrategy(rev::CANPIDController::AccelStrategy::kSCurve);
    // slave_pid_.SetSmartMotionAccelStrategy(rev::CANPIDController::AccelStrategy::kSCurve);
    // master_pid_.SetSmartMotionMaxAccel(constants::lift::kMaxAcceleration * 60);

    solenoid_.Set(frc::DoubleSolenoid::Value::kReverse);
    is_extended_ = false;

    initial_delta_position_ = GetEncAPos() - GetEncBPos();

    DEBUG_LOG("Lift Initial Delta Position = " + to_string(initial_delta_position_));
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

bool Lift::IsExtended() const
{
    return is_extended_;
}

void Lift::Extend(){
    is_extended_ = true;
    solenoid_.Set(frc::DoubleSolenoid::kForward);
}

void Lift::Retract(){
    is_extended_ = false;
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

void Lift::MoveLift(double kP, bool moveUp) {
    // SetA(percentCommand);
    double MAX_ERROR = 1.0;     //Revolutions
    if(kP != kP_) {
        kP_ = kP;
        master_pid_.SetP(kP_);
        slave_pid_.SetP(kP_);
    }

    double deltaPos = (GetEncAPos() - GetEncBPos()) - initial_delta_position_;

    SetAPosition(GetEncAPos() - deltaPos/2 + ((moveUp == true) ? 1 : - 1) * MAX_ERROR);
    SetBPosition(GetEncBPos() + deltaPos/2 + ((moveUp == true) ? 1 : - 1) * MAX_ERROR);

    DEBUG_LOG("Lift Enc A Pos = " + to_string(GetEncAPos()));
    // DEBUG_LOG("Lift Enc B Pos = " + to_string(GetEncBPos()));
    // DEBUG_LOG("Lift Delta Position = " + to_string(deltaPos));
}

void Lift::SetAPosition(double position) {
    master_pid_.SetReference(position, rev::ControlType::kPosition, 0, 0);
}

void Lift::SetBPosition(double position) {
    slave_pid_.SetReference(position, rev::ControlType::kPosition, 0, 0);
}

void Lift::SetAPosition(double position, double feedForward) {
    master_pid_.SetReference(position, rev::ControlType::kPosition, 0, feedForward * 12/*to percent*/);
}

void Lift::SetBPosition(double position, double feedForward) {
    slave_pid_.SetReference(position, rev::ControlType::kPosition, 0, feedForward * 12);
}

void Lift::SetA(double percent)
{
    lift_master_.Set(percent);
}

void Lift::SetB(double percent)
{
    lift_slave_.Set(percent);
}

double Lift::GetInitialDeltaPosition()
{
    return initial_delta_position_;
}