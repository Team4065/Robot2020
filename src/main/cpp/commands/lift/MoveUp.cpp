#include "commands/lift/MoveUp.h"
#include "subsystems/Lift.h"
#include <iostream>

using namespace std;
using namespace frc4065;

MoveUp::MoveUp() {
  AddRequirements({&Lift::GetInstance()});
  // ReferencedTunable::Register("Lift Up Percent Command", percentUpCmd_);
}

// Called when the command is initially scheduled.
void MoveUp::Initialize() {
  percentUpCmd_ = 0.75;
}

// Called repeatedly when this Command is scheduled to run
void MoveUp::Execute() {
  Lift::GetInstance().MoveLift(percentUpCmd_);
  DEBUG_LOG("Lift Percent Command = " + to_string(percentUpCmd_)); 
  DEBUG_LOG("Lift Delta Position = " + to_string(Lift::GetInstance().GetEncAPos() - Lift::GetInstance().GetEncBPos() - Lift::GetInstance().GetInitialDeltaPosition())); 
}

void MoveUp::End(bool interrupted){
  // Lift::GetInstance().MoveLift(0);
}

bool MoveUp::IsFinished(){return false;}