/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/ToggleIntake.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ToggleIntake::ToggleIntake()
{
  static Intake& instance_ = Intake::GetInstance();
  AddCommands(
    frc2::ConditionalCommand(
      frc2::InstantCommand([&] { instance_.Retract(); }, {&instance_}),
      frc2::InstantCommand([&] { instance_.Extend(); }, {&instance_}),
      [&] { return instance_.IsDeployed(); }
    ),
    frc2::ConditionalCommand(
      frc2::WaitCommand(1.25_s),
      frc2::InstantCommand([]{}),
      [&] { return instance_.IsDeployed(); }
    ),
    frc2::ConditionalCommand(
      frc2::InstantCommand([&] { instance_.Suck(); }, {&instance_}),
      frc2::InstantCommand([&] { instance_.Idle(); }, {&instance_}),
      [&] { return instance_.IsDeployed(); }
    )
  );
}
