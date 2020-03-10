#include "RobotContainer.h"
#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include "Constants.h"

RobotContainer::RobotContainer() 
{
  Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller_));
  // frc::SmartDashboard::PutData("Auto Modes", &chooser_);
  //Drivetrain::GetInstance().SetDefaultCommand(ArcadeDrive(&controller2_));
  // chooser_.AddOption(kRightRendevousAuto, kRightRendevousAuto);
  // chooser_.AddOption(kLeftRendevousAuto, kLeftRendevousAuto);
  // chooser_.AddOption(kTrenchAuto, kTrenchAuto);
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // y_btn_.WhenPressed(new MoveUp()).WhenReleased(new IdleLift());
  y_btn_.WhileHeld(new MoveUp()).WhenReleased(new IdleLift());
//   a_btn_.WhileHeld(new MoveDown(false)).WhenReleased(new IdleLift()); //Controlled
  a_btn_.WhileHeld(new MoveDown(true)).WhenReleased(new IdleLift());  //Full Power
  // y_btn_.WhileHeld(new MoveUp());
  // a_btn_.WhileHeld(new MoveDown());
  //x_btn_.WhenPressed(new TimedShoot(60_rpm, 3_s)).WhenReleased(new PreSpinup(0_rpm));
  x_btn_.WhenPressed(new VBeltForward()).WhenReleased(new VBeltOff());
  b_btn_.WhenPressed(new ToggleLiftPiston());
  rb_btn_.WhenPressed(new ToggleIntake());
  //lb_btn_.WhenPressed(new TimedShoot(4000_rpm, 6_s));
  lb_btn_.WhileHeld(new TimedShoot(3700_rpm, 10_s));
  // sl_btn_.WhenPressed();
  // sr_btn_.WhenPressed();
  start_btn_.WhenPressed(new TrackThenAlign());
  back_btn_.WhenPressed(new ReverseIntake()).WhenReleased(new IdleIntake());
  // lt_btn_.WhenPressed();
  //rt_btn_.WhenPressed(new ReverseIntake()).WhenReleased(new IdleIntake());

//romell controls
  // sec_y_btn_.WhileHeld(new MoveUp()).WhenReleased(new IdleLift());
  // sec_a_btn_.WhileHeld(new MoveDown(true)).WhenReleased(new IdleLift());  //Full Power
  // sec_b_btn_.WhenPressed(new VBeltForward()).WhenReleased(new VBeltOff());
  // sec_start_btn_.WhenPressed(new ToggleLiftPiston());
  // sec_rb_btn_.WhenPressed(new ToggleIntake());
  // sec_x_btn_.WhileHeld(new TimedShoot(3500_rpm, 10_s));
  // sec_back_btn_.WhenPressed(new TrackThenAlign());
  // sec_lb_btn_.WhenPressed(new ReverseIntake()).WhenReleased(new IdleIntake());

  //Button Box
  moveLiftUp_.WhileHeld(new MoveUp());
  moveLiftDown_.WhileHeld(new MoveDown(true));
  deployLift_.WhenPressed(new DeployLift());
  stowLift_.WhenPressed(new StowLift());
  
}

// frc2::Command* RobotContainer::GetAutonomousCommand()
// {
//   std::string selected_ = chooser_.GetSelected();
//   if (selected_ == kLeftRendevousAuto)
//     return GetLeftRendevousAuto();
//   else if (selected_ == kRightRendevousAuto)
//     return GetRightRendevousAuto();
//   else if (selected_ == kTrenchAuto)
//     return GetTrenchAuto();
// }  

frc2::Command* RobotContainer::GetTrenchAuto()
{
    // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks,
          DriveConstants::kv,
          DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed, AutoConstants::kMaxAcceleration);
  frc::TrajectoryConfig slow_config(0.75_mps, 1_mps_sq);
  // Add kinematics to ensure max speed is actually obeyed
  slow_config.SetKinematics(DriveConstants::kDriveKinematics);
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);
  slow_config.AddConstraint(autoVoltageConstraint);
    frc2::PIDController leftController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);
    frc2::PIDController rightController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);

  drivetrain_.ResetOdometry(frc::Pose2d());
    auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
        // Start at the origin facing the +X direction
        frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)), {},
        // Pass through these two interior waypoints, making an 's' curve path
      //{frc::Translation2d(1_m, 1_m)},// frc::Translation2d(2_m, -1_m)},
        // End 3 meters straight ahead of where we started, facing forward
        frc::Pose2d(1_m, 0_m, frc::Rotation2d(15_deg)),
        // Pass the config
        config);

    frc2::RamseteCommand ramseteCommand(
        exampleTrajectory,
        [this]() { return drivetrain_.GetPose(); },
        frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        DriveConstants::kDriveKinematics,
        [this] { return drivetrain_.GetWheelSpeeds(); },
        leftController,
        rightController,
        [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
        {&drivetrain_}
    );

    auto exampleTrajectory2 = frc::TrajectoryGenerator::GenerateTrajectory(
        // Start at the origin facing the +X direction
        frc::Pose2d(1_m, 0_m, frc::Rotation2d(15_deg)),// {},
        // Pass through these two interior waypoints, making an 's' curve path
        {
        frc::Translation2d(1.4_m, 0_m),
        frc::Translation2d(2.0_m, 0_m)
        },
        // End 3 meters straight ahead of where we started, facing forward
        frc::Pose2d(3.8_m, 0_m, frc::Rotation2d(0_deg)),
        // Pass the config
        config);

    frc2::RamseteCommand ramseteCommand2(
        exampleTrajectory2,
        [this]() { return drivetrain_.GetPose(); },
        frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        DriveConstants::kDriveKinematics,
        [this] { return drivetrain_.GetWheelSpeeds(); },
        leftController,
        rightController,
        [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
        {&drivetrain_}
    );

    slow_config.SetReversed(true);

    auto exampleTrajectory3 = frc::TrajectoryGenerator::GenerateTrajectory(
        // Start at the origin facing the +X direction
        frc::Pose2d(3.8_m, 0_m, frc::Rotation2d(0_deg)), {},
        // Pass through these two interior waypoints, making an 's' curve path
      //{frc::Translation2d(1_m, 1_m)},// frc::Translation2d(2_m, -1_m)},
        // End 3 meters straight ahead of where we started, facing forward
        frc::Pose2d(2.5_m, -0.1_m, frc::Rotation2d(10_deg)),
        // Pass the config
        slow_config);

    frc2::RamseteCommand ramseteCommand3(
        exampleTrajectory3,
        [this]() { return drivetrain_.GetPose(); },
        frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
        
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        DriveConstants::kDriveKinematics,
        [this] { return drivetrain_.GetWheelSpeeds(); },
        leftController,
        rightController,
        [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
        {&drivetrain_}
    );


    // no auto
    return new frc2::SequentialCommandGroup(
      frc2::ParallelCommandGroup(
        ToggleLiftPiston(),
        PreSpinup(2500_rpm),
        std::move(ramseteCommand)
      ),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      TrackThenAlign(),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      frc2::PrintCommand("Ending alignment."),
      TimedShoot(3500_rpm, 2.5_s),
      frc2::PrintCommand("Ending shooting."),
      ToggleIntake(),
      std::move(ramseteCommand2),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      frc2::ParallelCommandGroup(
        PreSpinup(2500_rpm),
        std::move(ramseteCommand3)
      ),
      ToggleIntake(),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      //TrackThenAlign(),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      TimedShoot(3500_rpm, 2.5_s)
    );
}

frc2::Command* RobotContainer::GetRightRendevousAuto()
{
    // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks,
          DriveConstants::kv,
          DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed, AutoConstants::kMaxAcceleration);
  frc::TrajectoryConfig slow_config(0.75_mps, 1_mps_sq);
  // Add kinematics to ensure max speed is actually obeyed
  slow_config.SetKinematics(DriveConstants::kDriveKinematics);
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);
  slow_config.AddConstraint(autoVoltageConstraint);

  drivetrain_.ResetOdometry(frc::Pose2d());
      auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),// {},
      {
        frc::Translation2d(1_m, -0.2_m)
      },
      frc::Pose2d(1.35_m, -0.28_m, frc::Rotation2d(5_deg)),
      slow_config);

    frc2::PIDController leftController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);
    frc2::PIDController rightController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);

    frc2::RamseteCommand ramseteCommand(
        exampleTrajectory,
        [this]() { return drivetrain_.GetPose(); },
        frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        DriveConstants::kDriveKinematics,
        [this] { return drivetrain_.GetWheelSpeeds(); },
        leftController,
        rightController,
        [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
        {&drivetrain_}
    );
    slow_config.SetReversed(true);
      auto exampleTrajectory2 = frc::TrajectoryGenerator::GenerateTrajectory(
      frc::Pose2d(1.35_m, -0.28_m, frc::Rotation2d(5_deg)),// {},
      {},
      frc::Pose2d(1.1_m, -0.28_m, frc::Rotation2d(-15_deg)),
      slow_config);

    frc2::RamseteCommand ramseteCommand2(
        exampleTrajectory2,
        [this]() { return drivetrain_.GetPose(); },
        frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        DriveConstants::kDriveKinematics,
        [this] { return drivetrain_.GetWheelSpeeds(); },
        leftController,
        rightController,
        [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
        {&drivetrain_}
    );

    return new frc2::SequentialCommandGroup(
      ToggleLiftPiston(),
      ToggleIntake(),
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      frc2::ParallelCommandGroup(
        PreSpinup(3000_rpm),
        frc2::SequentialCommandGroup(
          std::move(ramseteCommand2),
          frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {})
        )
      ),
      TrackThenAlign(),
      frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
      TimedShoot(3500_rpm, 5_s)
    );
}

frc2::Command* RobotContainer::GetLeftRendevousAuto()
{
    // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks,
          DriveConstants::kv,
          DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed, AutoConstants::kMaxAcceleration);
  frc::TrajectoryConfig slow_config(0.75_mps, 1_mps_sq);
  // Add kinematics to ensure max speed is actually obeyed
  slow_config.SetKinematics(DriveConstants::kDriveKinematics);
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);
  slow_config.AddConstraint(autoVoltageConstraint);
    frc2::PIDController leftController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);
    frc2::PIDController rightController(DriveConstants::kPDriveVel, DriveConstants::kIDriveVel, DriveConstants::kDDriveVel);

  drivetrain_.ResetOdometry(frc::Pose2d());
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
    // Start at the origin facing the +X direction
    frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
    {frc::Translation2d(1.219_m, 0.3_m)},// frc::Translation2d(2_m, -1_m)},
    // End 3 meters straight ahead of where we started, facing forward
    frc::Pose2d(2.22_m, -0.25_m, frc::Rotation2d(-65_deg)),
    // Pass the config
    config);
  frc2::RamseteCommand ramseteCommand(
      exampleTrajectory,
      [this]() { return drivetrain_.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return drivetrain_.GetWheelSpeeds(); },
      leftController,
      rightController,
      [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
      {&drivetrain_}
  );
  config.SetReversed(true);
    auto exampleTrajectory2 = frc::TrajectoryGenerator::GenerateTrajectory(
    // Start at the origin facing the +X direction
    frc::Pose2d(2.22_m, -0.25_m, frc::Rotation2d(-65_deg)),
    {},// frc::Translation2d(2_m, -1_m)},
    // End 3 meters straight ahead of where we started, facing forward
    frc::Pose2d(2.0_m, 0_m, frc::Rotation2d(0_deg)),
    // Pass the config
    config);
  frc2::RamseteCommand ramseteCommand2(
      exampleTrajectory2,
      [this]() { return drivetrain_.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return drivetrain_.GetWheelSpeeds(); },
      leftController,
      rightController,
      [this](auto left, auto right) { drivetrain_.TankDriveVolts(left, right); },
      {&drivetrain_}
  );
  return new frc2::SequentialCommandGroup(
    ToggleLiftPiston(),
    ToggleIntake(),
    std::move(ramseteCommand),
    frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
    std::move(ramseteCommand2),
    frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
    TrackThenAlign(),
    frc2::InstantCommand([this] { drivetrain_.TankDriveVolts(0_V, 0_V); }, {}),
    TimedShoot(3500_rpm, 4_s)
  );
}

frc2::Command* RobotContainer::GetNoAuto()
{
  return &NoAuto;
}