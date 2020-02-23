#include "commands/drivetrain/TankDrive.h"

TankDrive::TankDrive(Drivetrain& drivetrain_)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&drivetrain_});
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  std::cout << "Tank Drive" << std::endl;
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() { return false; }
