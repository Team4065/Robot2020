#include "Constants.h"

using namespace constants::drivetrain;

const frc::DifferentialDriveKinematics constants::drivetrain::kDriveKinematics(kTrackWidth);
const frc::TrajectoryConfig constants::drivetrain::kAutoConfig(auto_mode::kMaxVelocity, auto_mode::kMaxAcceleration);
const frc::DifferentialDriveKinematics DriveConstants::kDriveKinematics(
    kTrackwidth);