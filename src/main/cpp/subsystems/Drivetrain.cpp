#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{
    left_front_master_.RestoreFactoryDefaults();
    left_middle_slave_.RestoreFactoryDefaults();
    left_rear_slave_.RestoreFactoryDefaults();
    right_front_master_.RestoreFactoryDefaults();
    right_middle_slave_.RestoreFactoryDefaults();
    right_rear_slave_.RestoreFactoryDefaults();

    left_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    left_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    left_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    
    right_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    right_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    right_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    
    left_middle_slave_.Follow(left_front_master_, false);
    left_rear_slave_.Follow(left_front_master_, false);

    right_middle_slave_.Follow(right_front_master_, false);
    right_rear_slave_.Follow(right_front_master_, false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

Drivetrain& Drivetrain::GetInstance()
{
    static Drivetrain instance;  // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}
