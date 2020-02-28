#include "commands/lift/MoveUp.h"
#include "subsystems/Lift.h"

MoveUp::MoveUp() {
  AddRequirements({&Lift::GetInstance()});
}

// Called when the command is initially scheduled.
void MoveUp::Initialize() {
  Lift::GetInstance().MovePercent(.5);
}
