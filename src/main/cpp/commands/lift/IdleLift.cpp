#include "subsystems/Lift.h"

#include "commands/lift/IdleLift.h"

IdleLift::IdleLift() {
  AddRequirements({&Lift::GetInstance()});
}

// Called when the command is initially scheduled.
void IdleLift::Initialize()
{
  Lift::GetInstance().MovePercent(0.0);
}
