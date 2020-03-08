#include "commands/lift/MoveDown.h"
#include "subsystems/Lift.h"
#include <iostream>

using namespace std;
using namespace frc4065;

MoveDown::MoveDown(bool fullPower) {
  AddRequirements({&Lift::GetInstance()});
  fullPower_ = fullPower;
  kP_ = constants::lift::kP;
  // ReferencedTunable::Register("Lift Move Down kP", kP_);
}

// Called when the command is initially scheduled.
void MoveDown::Initialize() {}
void MoveDown::Execute()
{
  if(fullPower_ == true) {
    Lift::GetInstance().SetA(-constants::lift::kFullPowerLiftPercentage);
    Lift::GetInstance().SetB(-constants::lift::kFullPowerLiftPercentage);
  } else {
    Lift::GetInstance().MoveLift(kP_, false);
  }
  
  // DEBUG_LOG("Lift Percent Command = " + to_string(percentDwnCmd_)); 
  // DEBUG_LOG("Lift Delta Position = " + to_string(Lift::GetInstance().GetEncAPos() - Lift::GetInstance().GetEncBPos() - Lift::GetInstance().GetInitialDeltaPosition())); 
}

void MoveDown::End(bool interrupted){
  if(fullPower_ == true) {
    Lift::GetInstance().SetA(0);
    Lift::GetInstance().SetB(0);
  }
}

bool MoveDown::IsFinished(){return false;}