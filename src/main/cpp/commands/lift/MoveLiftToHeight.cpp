#include "commands/lift/MoveLiftToHeight.h"

MoveLiftToHeight::MoveLiftToHeight(units::foot_t height) : height_(height)
{
  AddRequirements({ &Lift::GetInstance() });
}

// Called when the command is initially scheduled.
void MoveLiftToHeight::Initialize()
{
  Lift::GetInstance().SetHeight(height_);
}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToHeight::Execute() {}

// Called once the command ends or is interrupted.
void MoveLiftToHeight::End(bool interrupted) {}

// Returns true when the command should end.
bool MoveLiftToHeight::IsFinished() { return std::abs((Lift::GetInstance().GetHeight() - height_).to<double>())
                                             < constants::lift::kHeightTolerance.to<double>(); }
