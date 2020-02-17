#pragma once

#include <frc2/command/SubsystemBase.h>

#include "rev/ControlType.h" 
#include "rev/CANSparkMax.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "util/Macros.h"
#include <utility>
#include "Constants.h"
#include <frc/util/color.h>

class ControlPanelManipulator : public frc2::SubsystemBase 
{
public:
  std::pair<frc::Color, double> GetColorAndConfidence() const;

  static ControlPanelManipulator& GetInstance();
  //DISALLOW_COPY_AND_ASSIGN(ControlPanelManipulator);

  void Periodic();

  // void move_motor_clockwise();
  // void move_motor_counterclockwise();

  void DeployCPM();
  
  double read_encoder_position();

  void setPosition(double position);
  

private:
  ControlPanelManipulator() = default;
  bool isDeployed_ = false;
  WPI_TalonSRX deployMotor_ { kCPMDeployMotorID };
  rev::CANSparkMax motor_ {kCPMSpinMotorID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANPIDController motor_pid_ { motor_.GetPIDController() };
  rev::CANEncoder encoder_ {motor_.GetEncoder()};
   
  // rev::ColorSensorV3 color_sensor_ { frc::I2CLLPort::kOnboard };
  // rev::ColorMatch color_matcher_;
  // static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  // static constexpr frc::Color kYellowTarget = frc::Color(0.197, 0.561, 0.240);
  // static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  // static constexpr frc::Color kGreenTarget = frc::Color(0.361, 0.524, 0.113);
};
