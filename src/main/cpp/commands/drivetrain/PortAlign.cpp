#include "commands/drivetrain/PortAlign.h"

PortAlign::PortAlign()
    : CommandHelper(frc2::PIDController(0, 0, 0),
                    // This should return the measurement
                    [] { return 0; },
                    // This should return the setpoint (can also be a constant)
                    [] { return 0; },
                    // This uses the output
                    [](double output) {
                      // Use the output here
                    }) {}

// Returns true when the command should end.
bool PortAlign::IsFinished() { return false; }
