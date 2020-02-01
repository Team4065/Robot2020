#include "subsystems/Drivetrain.h"

std::shared_ptr<double> kP_Velocity;//2.31 / 100;
std::shared_ptr<double> kD_Velocity;
std::shared_ptr<double> kF_Velocity;
std::shared_ptr<double> kArbiFeedForw;

Drivetrain::Drivetrain()
    : odometry_(frc::Rotation2d(GetHeading()))
{
    left_front_master_.RestoreFactoryDefaults();
    left_middle_slave_.RestoreFactoryDefaults();
    //left_rear_slave_.RestoreFactoryDefaults();
    right_front_master_.RestoreFactoryDefaults();
    right_middle_slave_.RestoreFactoryDefaults();
    //right_rear_slave_.RestoreFactoryDefaults();

    left_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    left_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    //left_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    right_front_master_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
    right_middle_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());
   // right_rear_slave_.SetSmartCurrentLimit(constants::drivetrain::kMaxCurrentDraw.to<double>());

    left_front_master_.SetInverted(true);

    left_middle_slave_.Follow(left_front_master_, false);
    //left_rear_slave_.Follow(left_front_master_, false);

    right_middle_slave_.Follow(right_front_master_, false);
    //right_rear_slave_.Follow(right_front_master_, false);

    /*
    left_pid_.SetP(constants::drivetrain::kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetD(constants::drivetrain::kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetFF(constants::drivetrain::kF_Velocity, constants::drivetrain::kVelocityPIDPort);

    right_pid_.SetP(constants::drivetrain::kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetD(constants::drivetrain::kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetFF(constants::drivetrain::kF_Velocity, constants::drivetrain::kVelocityPIDPort);
    */

    // frc4065::ReferencedTunable::Register("kP", kP_Velocity);
    // frc4065::ReferencedTunable::Register("kD", kD_Velocity);
    // frc4065::ReferencedTunable::Register("kF", kF_Velocity);
    // frc4065::ReferencedTunable::Register("kArbiFeedForw", kArbiFeedForw);
    
}

// This method will be called once per scheduler run
void Drivetrain::Periodic()
{
    
    left_pid_.SetP(*kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetD(*kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    left_pid_.SetFF(*kF_Velocity, constants::drivetrain::kVelocityPIDPort);

    right_pid_.SetP(*kP_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetD(*kD_Velocity, constants::drivetrain::kVelocityPIDPort);
    right_pid_.SetFF(*kF_Velocity, constants::drivetrain::kVelocityPIDPort);
    

    state.pastTime = state.currentTime;
    state.currentTime = frc::Timer::GetFPGATimestamp();
    state.deltaTime = state.currentTime - state.pastTime;

    odometry_.Update(frc::Rotation2d(GetHeading()), GetLeftEncoderDistance(), GetRightEncoderDistance());

    int PIDPortSelected = 0;
    switch(state.outputMode)
    {
        case rev::ControlType::kVelocity:
            PIDPortSelected = constants::drivetrain::kVelocityPIDPort;
            break;
        case rev::ControlType::kPosition:
            PIDPortSelected = constants::drivetrain::kPositionPIDPort;
            break;
        case rev::ControlType::kSmartVelocity:
            PIDPortSelected = constants::drivetrain::kVelocityPIDPort;
            break;
        case rev::ControlType::kSmartMotion:
            PIDPortSelected = constants::drivetrain::kPositionPIDPort;
            break;
        default:
            PIDPortSelected = constants::drivetrain::kVelocityPIDPort;
            break;
    }

    Tracking();

    std::cout << "left target: " << state.leftTarget << " right target: " << state.rightTarget << std::endl;
    std::cout << "left velocity: " << left_encoder_.GetVelocity() / 7.49 << " right velocity: " << right_encoder_.GetVelocity() / 7.49 << std::endl;
    //std::cout << "left voltage: " << state.leftTarget / 4 << " right voltage: " << state.rightTarget / 4 << std::endl;
    //left_front_master_.Set((state.leftTarget / 12) / 4);
    //right_front_master_.Set((state.leftTarget / 12) / 4);
    //left_pid_.SetReference(state.leftTarget, state.outputMode, PIDPortSelected, constants::drivetrain::kArbiFeedForw * abs(state.leftTarget) / state.leftTarget);
    //right_pid_.SetReference(state.rightTarget, state.outputMode, PIDPortSelected, constants::drivetrain::kArbiFeedForw * abs(state.rightTarget) / state.rightTarget);

    // left_pid_.SetReference(state.leftTarget, state.outputMode, PIDPortSelected, *kArbiFeedForw * abs(state.leftTarget) / state.leftTarget);
    // right_pid_.SetReference(state.rightTarget, state.outputMode, PIDPortSelected, *kArbiFeedForw * abs(state.rightTarget) / state.rightTarget);
    
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
void Drivetrain::NeutralMode(bool isEnable)
{
  if (isEnable)
  {
    left_front_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    left_middle_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    //left_rear_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    right_front_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    right_middle_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    //right_rear_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  }
  else
  {
    left_front_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    left_middle_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    //left_rear_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    right_front_master_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    right_middle_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    //right_rear_slave_.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  }
}
Drivetrain &Drivetrain::GetInstance()
{
    static Drivetrain instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Drivetrain::Tracking(){
    limelight->PutNumber("pipeline", state.trackingMode);

    double tx = limelight->GetNumber("tx", 0.0);
    
    double error = -tx;// 0 - tx // 0 is always the target
    static double pastError;
    double deltaError = (pastError - error) / state.deltaTime;

    double leftOutput = error * state.kP_tracking + deltaError * state.kD_tracking + (abs(error) / error) * state.kF_tracking;

    //may need to be put in a conditional to prevent tracking when it isn't supposed to be (the pipline shouldn't find a target during no tracking)
    if(state.trackingMode != TrackingMode::NONE){
        state.leftTarget += leftOutput;
        state.rightTarget -= leftOutput;
    }


    pastError = error;
}

void Drivetrain::SetLeft(double value){ 
    Drivetrain::GetInstance().state.leftTarget = value;
}

void Drivetrain::SetRight(double value){
    Drivetrain::GetInstance().state.rightTarget = value;
}