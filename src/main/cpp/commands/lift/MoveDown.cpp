#include "commands/lift/MoveDown.h"

MoveDown::MoveDown() {
  AddRequirements({&Lift::GetInstance()});
}

// Called when the command is initially scheduled.
void MoveDown::Initialize() 
{
  Lift::GetInstance().MovePercent(-.5);
}
