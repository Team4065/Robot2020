#include "commands/lift/MoveUp.h"
#include "subsystems/Lift.h"
#include <iostream>

MoveUp::MoveUp() {
  AddRequirements({&Lift::GetInstance()});
}

// Called when the command is initially scheduled.
void MoveUp::Initialize() {
  // Lift::GetInstance().MovePercent(1);

  // double encAPos = Lift::GetInstance().GetEncAPos();
  // double encBPos = Lift::GetInstance().GetEncBPos();

  // initialDeltaPos_ = encAPos - encBPos;
}

// Called repeatedly when this Command is scheduled to run
void MoveUp::Execute() {
  double MAX_DELTA_POS = 3.0;   //In Revolutions
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
  // std::cout << "Motor A Position = " << encAPos << std::endl;
  // std::cout << "Motor B Position = " << encBPos << std::endl;
  // DEBUG_LOG("Motor A Position Command = " + STRINGIFY(commandedAPos));
  // DEBUG_LOG("Motor B Position Command = " + STRINGIFY(commandedBPos));

}

void MoveUp::End(bool interrupted){}

bool MoveUp::IsFinished(){return false;}