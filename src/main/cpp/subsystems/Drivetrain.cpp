#include "subsystems/Drivetrain.h"
#include "iostream"

Drivetrain::Drivetrain(){

    left_front_master_.Config_kP(0, 1);
    left_front_master_.Config_kI(0, 0);
    left_front_master_.Config_kD(0, 0);
    left_front_master_.Config_kF(0, 0);

    right_front_master_.Config_kP(0, 1);
    right_front_master_.Config_kI(0, 0);
    right_front_master_.Config_kD(0, 0);
    right_front_master_.Config_kF(0, 0);

    left_front_master_.SelectProfileSlot(0, 0);
    right_front_master_.SelectProfileSlot(0, 0);

    left_front_master_.SetInverted(true);
    left_middle_.Follow(left_front_master_);
    left_rear_.Follow(left_front_master_);

    right_middle_.Follow(left_front_master_);
    right_rear_.Follow(left_front_master_);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {
    state.pastTime = state.currentTime;
    state.currentTime = frc::Timer::GetFPGATimestamp();

    state.targetOffsetX = table->GetNumber("tx", 0.0);
    state.targetOffsetY = table->GetNumber("ty", 0.0);

    switch(state.driveMode){
        case DriveMode::DRIVER:
            left_front_master_.Set(ControlMode::PercentOutput, state.leftSpeedTarget);
            right_front_master_.Set(ControlMode::PercentOutput, state.rightSpeedTarget);
            break;
    }

}

Drivetrain& Drivetrain::GetInstance()
{
    static Drivetrain instance;  // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Drivetrain::SetLeft(float value, ControlMode _controlMode){
    state.leftSpeedTarget = value;
}

void Drivetrain::SetRight(float value, ControlMode _controlMode){
    state.rightSpeedTarget = value;
}

void Drivetrain::SetTrackingTarget(TrackingTarget target){
    state.trackingTarget = target;
}