#include "commands/drivetrain/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive(frc::XboxController* controller) : controller_(controller)
{
  AddRequirements({ &Drivetrain::GetInstance() });
}

// Called when the command is initially scheduled.
void ArcadeDrive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute()
{
  double throttle = -controller_->GetY(frc::XboxController::kLeftHand) * 0.7;
  double turn = controller_->GetX(frc::XboxController::kRightHand) * 0.4;
  if(abs(throttle) < 0.05)
    throttle = 0;
  
  if(abs(turn) < 0.05)
    turn = 0;

  Drivetrain::GetInstance().TankDrivePercent(throttle + turn, throttle - turn);
}

// Called once the command ends or is interrupted.
void ArcadeDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool ArcadeDrive::IsFinished() { return false; }
