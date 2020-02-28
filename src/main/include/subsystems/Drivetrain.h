/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/CANPIDController.h>
#include <rev/CANEncoder.h>
#include <rev/ControlType.h>
#include <Constants.h>

using namespace constants::drivetrain;
using namespace frc4065;
using namespace rev;

enum EncoderDataType {
  Position,
  Velocity
};

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  bool isPercentControlled = true;
  bool isInverted = false;

  float leftPercent = 0;
  float rightPercent = 0;
  float leftTarget = 0;
  float rightTarget = 0;

  ControlType controlType = ControlType::kVelocity;

  float getLeftEncoder(EncoderDataType);
  float getRightEncoder(EncoderDataType);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  CANSparkMax leftMaster {kLeftFrontMotorPort};
  CANSparkMax leftSlave {kLeftMiddleMotorPort};

  CANSparkMax rightMaster {kRightFrontMotorPort};
  CANSparkMax rightSlave {kRightMiddleMotorPort};

  CANPIDController leftPID {leftMaster.GetPIDController()}; 
  CANPIDController rightPID {rightMaster.GetPIDController()}; 

  CANEncoder leftEncoder {leftMaster.GetEncoder()};
  CANEncoder rightEncoder {rightMaster.GetEncoder()};
};
