#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{
  Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller_));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // y_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  y_btn_.WhileHeld(new MoveUp()).WhenReleased(new IdleLift());
  a_btn_.WhileHeld(new MoveDown(false)).WhenReleased(new IdleLift()); //Controlled
  b_btn_.WhileHeld(new MoveDown(true)).WhenReleased(new IdleLift());  //Full Power
  // y_btn_.WhileHeld(new MoveUp());
  // a_btn_.WhileHeld(new MoveDown());
  //x_btn_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  x_btn_.WhenPressed(new VBeltForward()).WhenReleased(new VBeltOff());
  b_btn_.WhenPressed(new ToggleLiftPiston());
  rb_btn_.WhenPressed(new ToggleIntake());
  //lb_btn_.WhenPressed(new TimedShoot(4000_rpm, 6_s));
  lb_btn_.WhileHeld(new TimedShoot(4000_rpm, 10_s));
  // sl_btn_.WhenPressed();
  // sr_btn_.WhenPressed();
  start_btn_.WhenPressed(new TrackThenAlign());
  // back_btn_.WhenPressed();
  // lt_btn_.WhenPressed();
  // rt_btn_.WhenPressed();


  
}

frc2::Command* RobotContainer::GetAutonomousCommand()
{
  drivetrain_.ResetOdometry(frc::Pose2d());

  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
  frc::SimpleMotorFeedforward<units::meters>(
       constants::drivetrain::kS,
       constants::drivetrain::kV,
       constants::drivetrain::kA),
  constants::drivetrain::kDriveKinematics,
  10_V);
  frc::TrajectoryConfig config(constants::drivetrain::auto_mode::kMaxVelocity, constants::drivetrain::auto_mode::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(constants::drivetrain::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);
  frc::Trajectory traj_ = frc::TrajectoryGenerator::GenerateTrajectory(
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      {
        frc::Translation2d(1_m, 1_m)
      },
      frc::Pose2d(2_m, 0_m, frc::Rotation2d(0_deg)),
      config
  );

  frc2::RamseteCommand ramsete_command_(
    traj_, [this]() { return drivetrain_.GetPose(); },
    frc::RamseteController(constants::drivetrain::auto_mode::kRamseteB,
                        constants::drivetrain::auto_mode::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        constants::drivetrain::kS, constants::drivetrain::kV, constants::drivetrain::kA),
    constants::drivetrain::kDriveKinematics,
    [this] { return drivetrain_.GetWheelSpeeds(); },
    frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
    frc2::PIDController(constants::drivetrain::kPDriveVel, 0, 0),
    [this](units::volt_t left, units::volt_t right) { drivetrain_.TankDrivePercent(left.to<double>() / 12.0, right.to<double>() / 12.0); },
  {&drivetrain_});

  return new frc2::SequentialCommandGroup(
    std::move(ramsete_command_),
    frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }),
    TrackThenAlign()
  );
}