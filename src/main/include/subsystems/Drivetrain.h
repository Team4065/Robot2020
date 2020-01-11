#pragma once

#include <frc2/command/SubsystemBase.h>

class Drivetrain : public frc2::SubsystemBase {
 public:

  static Drivetrain& GetInstance()
  {
    static Drivetrain    instance;  // Guaranteed to be destroyed.
                                    // Instantiated on first use.
    return instance;
  }

  Drivetrain(Drivetrain const&)      = delete;
  void operator=(Drivetrain const&)  = delete;


  void Periodic();

 private:
  
  rev::CANSparkMax left_front_master_ { constants::drivetrain::kLeftFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax left_middle_ { constants::drivetrain::kLeftMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax left_rear_ { constants::drivetrain::kLeftRearMotorPort, rev::CANSparkMax::MotorType::kBrushless };

  rev::CANSparkMax right_front_master_ { constants::drivetrain::kRightFrontMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax right_middle_ { constants::drivetrain::kRightMiddleMotorPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax right_rear_ { constants::drivetrain::kRightRearMotorPort, rev::CANSparkMax::MotorType::kBrushless };

  Drivetrain(){}
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
