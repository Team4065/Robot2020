#include "subsystems/Drivetrain.h"
#include <frc/controller/PIDController.h>
#include <cmath>

/*
double kP_Velocity = 0;//2.31 / 100;
double kD_Velocity = 0;
double kF_Velocity = 0.00125;
double kArbiFeedForw = 0.130;

double maxAccel = 500;
double maxVelocity = 100;
*/

Drivetrain::Drivetrain()
    : odometry_(frc::Rotation2d(GetHeading()))
{
    left_front_master_.RestoreFactoryDefaults();
    left_middle_slave_.RestoreFactoryDefaults();
    right_front_master_.RestoreFactoryDefaults();
    right_middle_slave_.RestoreFactoryDefaults();

    // left_front_master_.EnableVoltageCompensation(constants::drivetrain::kNominalVoltage.to<double>());
    // left_middle_slave_.EnableVoltageCompensation(constants::drivetrain::kNominalVoltage.to<double>());
    // right_front_master_.EnableVoltageCompensation(constants::drivetrain::kNominalVoltage.to<double>());
    // right_middle_slave_.EnableVoltageCompensation(constants::drivetrain::kNominalVoltage.to<double>());

    // left_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    // left_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    // right_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    // right_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    left_front_master_.SetInverted(false);
    right_front_master_.SetInverted(false);

    left_middle_slave_.Follow(left_front_master_, false);

    right_middle_slave_.Follow(right_front_master_, false);

    // left_pid_.SetP(constants::drivetrain::kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    // left_pid_.SetD(constants::drivetrain::kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    // left_pid_.SetFF(constants::drivetrain::kF_Velocity, constants::drivetrain::kVelocityPIDPort);

    // right_pid_.SetP(constants::drivetrain::kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    // right_pid_.SetD(constants::drivetrain::kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    // right_pid_.SetFF(constants::drivetrain::kF_Velocity, constants::drivetrain::kVelocityPIDPort);

    // left_pid_.SetSmartMotionMaxAccel(constants::drivetrain::kMaxAccel, constants::drivetrain::kVelocityPIDPort);
    // right_pid_.SetSmartMotionMaxAccel(constants::drivetrain::kMaxAccel, constants::drivetrain::kVelocityPIDPort);
    
    // left_pid_.SetSmartMotionMaxVelocity(constants::drivetrain::kMaxVelocity, constants::drivetrain::kVelocityPIDPort);
    // right_pid_.SetSmartMotionMaxVelocity(constants::drivetrain::kMaxVelocity, constants::drivetrain::kVelocityPIDPort);


    // left_encoder_.SetPositionConversionFactor(constants::drivetrain::kWheelDiameter.to<double>() * M_PI / constants::drivetrain::kGearRatio);
    // right_encoder_.SetPositionConversionFactor(constants::drivetrain::kWheelDiameter.to<double>() * M_PI / constants::drivetrain::kGearRatio);

    // left_encoder_.SetVelocityConversionFactor(constants::drivetrain::kWheelDiameter.to<double>() * M_PI / constants::drivetrain::kGearRatio / 60);
    // right_encoder_.SetVelocityConversionFactor(constants::drivetrain::kWheelDiameter.to<double>() * M_PI / constants::drivetrain::kGearRatio / 60);

   /*
    frc4065::ReferencedTunable::Register("kP", kP_Velocity);
    frc4065::ReferencedTunable::Register("kD", kD_Velocity);
    frc4065::ReferencedTunable::Register("kF", kF_Velocity);
    frc4065::ReferencedTunable::Register("kArbiFeedForw", kArbiFeedForw);
    frc4065::ReferencedTunable::Register("maxAccel", maxAccel);
    frc4065::ReferencedTunable::Register("maxVelocity", maxVelocity);
    */
   
    NeutralMode(true);
    ResetGyro();
    ResetOdometry(frc::Pose2d());
}

// This method will be called once per scheduler run
void Drivetrain::Periodic()
{
    /*
    left_pid_.SetP(kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetD(kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetFF(kF_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetP(kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetD(kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetFF(kF_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetSmartMotionMaxVelocity(maxVelocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetSmartMotionMaxVelocity(maxVelocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetSmartMotionMaxAccel(maxAccel, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetSmartMotionMaxAccel(maxAccel, constants::drivetrain::kVelocityPIDPort);
    */
    //static int loop_ = 0;
    //if (loop_ % 20 == 0)
        std::cout << "Left (m.): " << GetLeftEncoderDistance().to<double>() << " Right (m.): " << GetRightEncoderDistance().to<double>() << " Heading (deg.): " << GetHeading().to<double>() << std::endl;
   // loop_++;
    odometry_.Update(frc::Rotation2d(GetHeading()), GetLeftEncoderDistance(), GetRightEncoderDistance());
    drive_.Feed();
}

void Drivetrain::ArcadeDrive(double fwd, double rot) {}

void Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right)
{
    DEBUG_LOG(((std::abs(left.to<double>()) > 12.0 || std::abs(left.to<double>()) < 0.0)
                ? "Attempting to apply voltage to left side out of bounds!" : ""));
    DEBUG_LOG(((std::abs(right.to<double>()) > 12.0 || std::abs(right.to<double>()) < 0.0) 
                ? "Attempting to apply voltage to right side out of bounds!" : ""));
    std::cout << "Left (V): " << left.to<double>() << " Right (V): " << -right.to<double>() << std::endl;
    left_motors_.SetVoltage(left);
    right_motors_.SetVoltage(-right);
}

void Drivetrain::TankDrivePercent(double left, double right)
{
    std::cout << left << " " << -right << std::endl;
    left_front_master_.Set(left);
    right_front_master_.Set(-right);
}

frc::DifferentialDriveWheelSpeeds Drivetrain::GetWheelSpeeds()
{
    return {
       units::meters_per_second_t(left_front_master_.GetEncoder().GetVelocity() / 9.47 * DriveConstants::kPI * 0.1524 / 60),
      -units::meters_per_second_t(right_front_master_.GetEncoder().GetVelocity() / 9.47 * DriveConstants::kPI * 0.1524 / 60)
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
units::meter_t Drivetrain::GetLeftEncoderDistance()
{
    return units::meter_t(left_front_master_.GetEncoder().GetPosition() / 9.47 * DriveConstants::kPI * 0.1524);
}
units::meter_t Drivetrain::GetRightEncoderDistance()
{
    return -units::meter_t(right_front_master_.GetEncoder().GetPosition() / 9.47 * DriveConstants::kPI * 0.1524);
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

void Drivetrain::ResetGyro()
{
    gyro_.Reset();
}

void Drivetrain::NeutralMode(bool isEnabled)
{
    left_front_master_.SetIdleMode(isEnabled ? rev::CANSparkMax::IdleMode::kBrake : rev::CANSparkMax::IdleMode::kCoast);
    left_middle_slave_.SetIdleMode(isEnabled ? rev::CANSparkMax::IdleMode::kBrake : rev::CANSparkMax::IdleMode::kCoast);
    right_front_master_.SetIdleMode(isEnabled ? rev::CANSparkMax::IdleMode::kBrake : rev::CANSparkMax::IdleMode::kCoast);
    right_middle_slave_.SetIdleMode(isEnabled ? rev::CANSparkMax::IdleMode::kBrake : rev::CANSparkMax::IdleMode::kCoast);
}
Drivetrain &Drivetrain::GetInstance()
{
    static Drivetrain instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}