/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/SpinUp_and_Shoot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
SpinUp_and_Shoot::SpinUp_and_Shoot(Shooter& shooter) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    SpinUp(shooter),
    Shoot(shooter)
  );
}
