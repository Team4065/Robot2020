// /*----------------------------------------------------------------------------*/
// /* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
// /* Open Source Software - may be modified and shared by FRC teams. The code   */
// /* must be accompanied by the FIRST BSD license file in the root directory of */
// /* the project.                                                               */
// /*----------------------------------------------------------------------------*/

// #pragma once

// #include <frc2/command/CommandBase.h>
// #include <frc2/command/CommandHelper.h>

// #include <units/units.h>
// #include <frc2/Timer.h>

// #include "subsystems/Shooter.h"
// #include "subsystems/Serializer.h"

// /**
//  * Shoots until timer runs out; timer only begins once shooter is spun up.
//  */
// class TimedShoot
//     : public frc2::CommandHelper<frc2::CommandBase, TimedShoot> {
//  public:
//   TimedShoot(units::revolutions_per_minute_t rpm, units::second_t time);

//   void Initialize() override;
//   void Execute() override;
//   void End(bool interrupted) override;
//   bool IsFinished() override;

//   units::revolutions_per_minute_t rpm_;
//   units::second_t time_;
//   units::second_t start_time_;
//   bool hysteresis_flag_;
//   frc2::Timer timer_;
//   bool timer_started_;
// };
