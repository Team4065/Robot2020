/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DoubleSolenoid.h>
#include <rev/CANSparkMax.h>


#include "util/Macros.h"
#include <Constants.h>
#include <units/units.h>

using namespace constants::lift;

class Lift : public frc2::SubsystemBase {
public:
  static Lift& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(Lift);
  void Periodic();
  void Extend();
  void Retract();
  void MovePercent(double percent);
  void SetHeight(units::foot_t height);
  units::foot_t GetHeight();
  bool IsExtended() const;

  double GetEncAPos(void) {return(lift_master_.GetEncoder().GetPosition());}
  double GetEncBPos(void) {return(lift_slave_.GetEncoder().GetPosition());}

  // void MoveLift(double percentCommand);
  void MoveLift(double kP, bool moveUp);
  void SetAPosition(double position);
  void SetBPosition(double position);
  void SetAPosition(double position, double feedForward);
  void SetBPosition(double position, double feedForward);
  void SetA(double percent);
  void SetB(double percent);

  double GetInitialDeltaPosition();

private:
  Lift();

  frc::DoubleSolenoid solenoid_ { constants::lift::kSolenoidPorts[0], constants::lift::kSolenoidPorts[1] };
  bool is_extended_ = true;
  rev::CANSparkMax lift_master_ { constants::lift::kMasterPort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANSparkMax lift_slave_ { constants::lift::kSlavePort, rev::CANSparkMax::MotorType::kBrushless };
  rev::CANEncoder master_encoder_ { lift_master_.GetEncoder() };
  rev::CANEncoder slave_encoder_ { lift_slave_.GetEncoder() };
  rev::CANPIDController master_pid_ { lift_master_.GetPIDController() };
  rev::CANPIDController slave_pid_ { lift_slave_.GetPIDController() };

  double initial_delta_position_;
  double kP_;
  double kI_;

};
