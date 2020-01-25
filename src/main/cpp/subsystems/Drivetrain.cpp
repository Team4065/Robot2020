#include "subsystems/Drivetrain.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <iostream>

Drivetrain::Drivetrain(): odometry_(frc::Rotation2d(GetHeading())) {
    front_left_.Config_kP(0, kp);
    front_left_.Config_kI(0, 0);
    front_left_.Config_kD(0, 0);
    front_left_.Config_kF(0, 0);
    front_right_.Config_kP(0, kp);
    front_right_.Config_kI(0, 0);
    front_right_.Config_kD(0, 0);
    front_right_.Config_kF(0, 0);

    front_right_.SetNeutralMode(NeutralMode::Brake);
    front_left_.SetNeutralMode(NeutralMode::Brake);
    back_right_.SetNeutralMode(NeutralMode::Brake);
    back_left_.SetNeutralMode(NeutralMode::Brake);

    frc4065::ReferencedTunable::Register("kP", kp);

    back_right_.Follow(front_right_);
    back_left_.Follow(front_left_);

    front_right_.SetInverted(InvertType::InvertMotorOutput);
    front_left_.SetInverted(InvertType::None);
    back_right_.SetInverted(InvertType::FollowMaster);
    back_left_.SetInverted(InvertType::FollowMaster);

    front_left_.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0);
    front_right_.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0);

    front_left_.SetSensorPhase(true);
    front_right_.SetSensorPhase(true);

    gyro_.Reset();
    ZeroEncoders();
}

void Drivetrain::ZeroEncoders()
{
    front_left_.SetSelectedSensorPosition(0);
    front_right_.SetSelectedSensorPosition(0);
}

Drivetrain& Drivetrain::GetInstance()
{
    static Drivetrain instance;

    return instance;
}

void Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right)
{
    front_left_.Set(ControlMode::PercentOutput, left.to<double>() / 12.0);
    front_right_.Set(ControlMode::PercentOutput, left.to<double>() / 12.0);
}

frc::DifferentialDriveWheelSpeeds Drivetrain::GetWheelSpeeds()
{
    return {
        units::feet_per_second_t(front_left_.GetSelectedSensorVelocity(0)  * 10 / 4096 * 1/2 * 3.14159 / 10.75),
        units::feet_per_second_t(front_right_.GetSelectedSensorVelocity(0) * 10 / 4096 * 1/2 * 3.14159 / 10.75)
    };
}
void Drivetrain::DriveVelocity(units::feet_per_second_t left, units::feet_per_second_t right)
{
    front_left_.Set(ControlMode::Velocity, left.to<double>() / 10.0 * 4096.0 / 0.5 / 3.14159);
    front_right_.Set(ControlMode::Velocity, right.to<double>() / 10.0 * 4096.0 / 0.5 / 3.14159);
}
frc::Pose2d Drivetrain::GetPose() const
{
    return odometry_.GetPose();
}
units::degree_t Drivetrain::GetHeading()
{
    return units::degree_t(std::remainder(gyro_.GetAngle(), 360) * (constants::drivetrain::kGyroReversed ? -1.0 : 1.0));
}

units::foot_t Drivetrain::GetLeftEncoderDistance()
{
    return units::foot_t( front_left_.GetSelectedSensorPosition() / 4096.0 * 0.5 * 3.14159);
}

units::foot_t Drivetrain::GetRightEncoderDistance()
{
    return units::foot_t( front_right_.GetSelectedSensorPosition() / 4096.0 * 0.5 * 3.14159 );
}

void Drivetrain::Periodic() {odometry_.Update(frc::Rotation2d(GetHeading()), GetLeftEncoderDistance(), GetRightEncoderDistance());
    //std::cout << "Err: " << front_left_.GetClosedLoopError() << std::endl;
    front_right_.Config_kP(0, kp);
    front_left_.Config_kP(0, kp);
    frc::SmartDashboard::PutNumber("Gyro Angle", GetHeading().to<double>());
    frc::SmartDashboard::PutNumber("Right Dist. (ft)", GetRightEncoderDistance().to<double>());
    frc::SmartDashboard::PutNumber("Left Dist. (ft)", GetLeftEncoderDistance().to<double>());
}
