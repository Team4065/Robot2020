#include "commands/lift/MoveDown.h"
#include "subsystems/Lift.h"
#include <iostream>

using namespace std;
using namespace frc4065;

MoveDown::MoveDown() {
  AddRequirements({&Lift::GetInstance()});
  // ReferencedTunable::Register("Lift Down Percent Command", percentDwnCmd_);
}

// Called when the command is initially scheduled.
void MoveDown::Initialize() {
  percentDwnCmd_ = -0.2;
}
void MoveDown::Execute()
{
<<<<<<< HEAD
  Lift::GetInstance().MovePercent(-.5);
=======
  Lift::GetInstance().MoveLift(percentDwnCmd_);
  DEBUG_LOG("Lift Percent Command = " + to_string(percentDwnCmd_)); 
  DEBUG_LOG("Lift Delta Position = " + to_string(Lift::GetInstance().GetEncAPos() - Lift::GetInstance().GetEncBPos() - Lift::GetInstance().GetInitialDeltaPosition())); 
>>>>>>> 49869f14be37d2fe54b84081c4bc1db16edbb6e1
}

void MoveDown::End(bool interrupted){
  // Lift::GetInstance().MoveLift(0);
}

bool MoveDown::IsFinished(){return false;}