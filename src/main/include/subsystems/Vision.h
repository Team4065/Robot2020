#pragma once

#include <frc2/command/SubsystemBase.h>

/**
 * TODO:
 * - Add vision functionality to this subsystem.
 * - Should use constants to calculate values for shooter, drivetrain, etc.
 * - I've decided to seperate functionality for vision systems as both the
 *   drivetrain and shooter will need access, which makes vision ownership
 *   to a particular subsystem unnecessary.
 */

class Vision : public frc2::SubsystemBase
{
public:
  Vision();
  void Periodic();
private:
};
