/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EngageVisionTracking.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
EngageVisionTracking::EngageVisionTracking() {
  AddRequirements({ &Vision::GetInstance(), &Drivetrain::GetInstance() });
}

// Called when the command is initially scheduled.
void EngageVisionTracking::Initialize()
{
  Vision::GetInstance().GetLimelight().SetPipeline(constants::limelight::pipes::TRACKING);
  Vision::GetInstance().GetLimelight().SetLEDMode(frc4065::Limelight::LEDMode::ON);
  Vision::GetInstance().GetLimelight().SetCamMode(frc4065::Limelight::CamMode::PROCESSING);
  Drivetrain::GetInstance().TankDriveVolts(0_V, 0_V);
}
