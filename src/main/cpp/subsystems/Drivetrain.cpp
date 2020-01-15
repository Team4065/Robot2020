#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
    : odometry_(frc::Rotation2d(GetHeading()))
{
    left_front_master_.RestoreFactoryDefaults();
    left_middle_slave_.RestoreFactoryDefaults();
    left_rear_slave_.RestoreFactoryDefaults();
    right_front_master_.RestoreFactoryDefaults();
    right_middle_slave_.RestoreFactoryDefaults();
    right_rear_slave_.RestoreFactoryDefaults();

    left_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    left_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    left_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    right_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    right_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    right_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    left_middle_slave_.Follow(left_front_master_, false);
    left_rear_slave_.Follow(left_front_master_, false);

    right_middle_slave_.Follow(right_front_master_, false);
    right_rear_slave_.Follow(right_front_master_, false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic()
{
    odometry_.Update(frc::Rotation2d(GetHeading()), GetLeftEncoderDistance(), GetRightEncoderDistance());
}

void Drivetrain::ArcadeDrive(double fwd, double rot) {}

void Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right)
{
    left_front_master_.SetVoltage(left);
    right_front_master_.SetVoltage(right);
}

frc::DifferentialDriveWheelSpeeds Drivetrain::GetWheelSpeeds()
{
    return {
        units::feet_per_second_t(left_encoder_.GetVelocity()),
        units::feet_per_second_t(right_encoder_.GetVelocity())
    };
}
frc::Pose2d Drivetrain::GetPose() const
{
    return odometry_.GetPose();
}
units::degree_t Drivetrain::GetHeading()
{
    return units::degree_t(std::remainder(gyro_.GetAngle(), 360) * (constants::drivetrain::kGyroReversed ? -1.0 : 1.0));
}
units::foot_t Drivetrain::GetLeftEncoderDistance() const
{
}
units::foot_t Drivetrain::GetRightEncoderDistance() const
{
}

void Drivetrain::ResetEncoders()
{
    left_encoder_.SetPosition(0);
    right_encoder_.SetPosition(0);
}

void Drivetrain::ResetOdometry(frc::Pose2d pose)
{
    ResetEncoders();
    odometry_.ResetPosition(pose, frc::Rotation2d(GetHeading()));
}

Drivetrain &Drivetrain::GetInstance()
{
    static Drivetrain instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}
