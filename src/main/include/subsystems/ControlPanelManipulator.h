#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include <rev/ControlType.h>
#include "rev/CANSparkMax.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "util/Macros.h"
#include <frc/util/color.h>
#include "Constants.h"
#include "utility"

using namespace constants::control_panel_manipulator;

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
  void StowCPM();
  
  double read_encoder_position();

  void setPosition(double position);

  bool IsDeployed(){return m_isDeployed;}
  CPMMode_t GetMode(){return m_mode;}

private:
  ControlPanelManipulator();    //The constructor is a private method because this class is intended to be used only as a singleton instance.
  bool m_isDeployed = false;
  CPMMode_t m_mode = MANUAL;
  WPI_TalonSRX m_deploym_motor { kCPMDeployMotorID };
  // rev::CANPIDController m_deployMotorPID_ { m_deploym_motor.GetPIDController() };
  rev::CANSparkMax m_motor {kCPMSpinMotorID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANPIDController m_motorpid { m_motor.GetPIDController() };
  rev::CANEncoder m_encoder {m_motor.GetEncoder()};
   
  // rev::ColorSensorV3 color_sensor_ { frc::I2CLLPort::kOnboard };
  // rev::ColorMatch color_matcher_;
  // static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  // static constexpr frc::Color kYellowTarget = frc::Color(0.197, 0.561, 0.240);
  // static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  // static constexpr frc::Color kGreenTarget = frc::Color(0.361, 0.524, 0.113);
};
