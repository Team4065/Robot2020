/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Vision.h"

Vision::Vision() : limelight_("limelight") {}

// This method will be called once per scheduler run
void Vision::Periodic()
{
    std::cout << "Distance Estimation (m.): " << 
    frc4065::Limelight::EstimateTargetDistance(
        constants::limelight::kCameraAngle,
        units::degree_t(limelight_.GetVerticalOffset()),
        constants::limelight::kCameraHeight,
        constants::limelight::kGoalHeight
    ) << std::endl;
}

Vision& Vision::GetInstance()
{
    static Vision instance_;
    return instance_;
}

frc4065::Limelight& Vision::GetLimelight()
{
    return limelight_;
}
