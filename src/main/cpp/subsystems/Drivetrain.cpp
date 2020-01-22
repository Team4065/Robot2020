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
    switch(mode){
        case Mode::DRIVER:
            SetLeft(this->targetLeft, ControlMode::PercentOutput);
            SetRight(this->targetRight, ControlMode::PercentOutput);
            break;
    }

}

Drivetrain& Drivetrain::GetInstance()
{
    static Drivetrain instance;  // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Drivetrain::SetLeft(float value, ControlMode _controlMode){
    left_front_master_.Set(_controlMode, value);
}

void Drivetrain::SetRight(float value, ControlMode _controlMode){
    right_front_master_.Set(_controlMode, value);
}