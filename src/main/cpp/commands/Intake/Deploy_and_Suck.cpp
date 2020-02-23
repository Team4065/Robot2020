/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/Deploy_and_Suck.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
Deploy_and_Suck::Deploy_and_Suck(Intake& intake) {
  AddCommands(
    DeployIntake(intake),
    Suck(intake)
  );
}
Deploy_and_Suck::Deploy_and_Suck(DeployIntake& deployIntake, Suck& suck) {
  AddCommands(
    deployIntake,
    suck
  );
}

