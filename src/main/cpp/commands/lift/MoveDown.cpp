#include "commands/lift/MoveDown.h"
#include "subsystems/Lift.h"
#include <iostream>

MoveDown::MoveDown() {
  AddRequirements({&Lift::GetInstance()});
}

// Called when the command is initially scheduled.
void MoveDown::Initialize() 
{
  double encAPos = Lift::GetInstance().GetEncAPos();
  double encBPos = Lift::GetInstance().GetEncBPos();

  // initialDeltaPos_ = encAPos - encBPos;
}
void MoveDown::Execute()
{
  double MAX_DELTA_POS = -3.0;   //In Revolutions
  // double DELTA_POS = 0.25;
  double encAPos = Lift::GetInstance().GetEncAPos();
  double encBPos = Lift::GetInstance().GetEncBPos();

  double deltaPos = (encAPos - encBPos);
  // if(std::abs(deltaPos) < MAX_DELTA_POS){
  //   Lift::GetInstance().SetAPosition(encAPos + DELTA_POS);
  //   Lift::GetInstance().SetBPosition(encBPos + DELTA_POS);
  // }

  double commandedAPos = encAPos + MAX_DELTA_POS;
  //double commandedBPos = encBPos + MAX_DELTA_POS;
  double commandedBPos = encBPos + MAX_DELTA_POS + deltaPos;
  Lift::GetInstance().SetAPosition(commandedAPos);
  Lift::GetInstance().SetBPosition(commandedBPos);

  std::cout << "DeltaPosition = " << deltaPos << std::endl;
}

void MoveDown::End(bool interrupted){}

bool MoveDown::IsFinished(){return false;}