#pragma once

#include "subsystems/CommandSwerveDrivetrain.h"

using namespace ctre::phoenix6;

// Generated by the Tuner X Swerve Project Generator
// https://v6.docs.ctr-electronics.com/en/stable/docs/tuner/tuner-swerve/index.html
class TunerConstants {
    // Both sets of gains need to be tuned to your individual robot.

    // The steer motor uses any SwerveModule.SteerRequestType control request with the
    // output type specified by SwerveModuleConstants::SteerMotorClosedLoopOutput
    static constexpr configs::Slot0Configs steerGains = configs::Slot0Configs{}
        .WithKP(100).WithKI(0).WithKD(2.0)
        .WithKS(0.2).WithKV(1.59).WithKA(0)
        .WithStaticFeedforwardSign(signals::StaticFeedforwardSignValue::UseClosedLoopSign);
    // When using closed-loop control, the drive motor uses the control
    // output type specified by SwerveModuleConstants::DriveMotorClosedLoopOutput
    static constexpr configs::Slot0Configs driveGains = configs::Slot0Configs{}
        .WithKP(0.1).WithKI(0).WithKD(0)
        .WithKS(0).WithKV(0.124);

    // The closed-loop output type to use for the steer motors;
    // This affects the PID/FF gains for the steer motors
    static constexpr swerve::ClosedLoopOutputType kSteerClosedLoopOutput = swerve::ClosedLoopOutputType::Voltage;
    // The closed-loop output type to use for the drive motors;
    // This affects the PID/FF gains for the drive motors
    static constexpr swerve::ClosedLoopOutputType kDriveClosedLoopOutput = swerve::ClosedLoopOutputType::Voltage;

    // The remote sensor feedback type to use for the steer motors;
    // When not Pro-licensed, FusedCANcoder/SyncCANcoder automatically fall back to RemoteCANcoder
    static constexpr swerve::SteerFeedbackType kSteerFeedbackType = swerve::SteerFeedbackType::FusedCANcoder;

    // The stator current at which the wheels start to slip;
    // This needs to be tuned to your individual robot
    static constexpr units::ampere_t kSlipCurrent = 120_A;

    // Initial configs for the drive and steer motors and the CANcoder; these cannot be null.
    // Some configs will be overwritten; check the `With*InitialConfigs()` API documentation.
    static constexpr configs::TalonFXConfiguration driveInitialConfigs{};
    static constexpr configs::TalonFXConfiguration steerInitialConfigs = configs::TalonFXConfiguration{}
        .WithCurrentLimits(
            configs::CurrentLimitsConfigs{}
                // Swerve azimuth does not require much torque output, so we can set a relatively low
                // stator current limit to help avoid brownouts without impacting performance.
                .WithStatorCurrentLimit(60_A)
                .WithStatorCurrentLimitEnable(true)
        );
    static constexpr configs::CANcoderConfiguration cancoderInitialConfigs{};
    // Configs for the Pigeon 2; leave this nullopt to skip applying Pigeon 2 configs
    static constexpr std::optional<configs::Pigeon2Configuration> pigeonConfigs = std::nullopt;

    static constexpr std::string_view kCANBusName = "rio";

public:
    // CAN bus that the devices are located on;
    // All swerve devices must share the same CAN bus
    static inline const CANBus kCANBus{kCANBusName, "./logs/example.hoot"};

    // Theoretical free speed (m/s) at 12 V applied output;
    // This needs to be tuned to your individual robot
    static constexpr units::meters_per_second_t kSpeedAt12Volts = 4.55_mps;

private:
    // Every 1 rotation of the azimuth results in kCoupleRatio drive motor turns;
    // This may need to be tuned to your individual robot
    static constexpr units::scalar_t kCoupleRatio = 3.5;

    static constexpr units::scalar_t kDriveGearRatio = 7.363636364;
    static constexpr units::scalar_t kSteerGearRatio = 12.8;
    static constexpr units::inch_t kWheelRadius = 2.167_in;

    static constexpr bool kInvertLeftSide = false;
    static constexpr bool kInvertRightSide = true;

    static constexpr int kPigeonId = 1;

    // These are only used for simulation
    static constexpr units::kilogram_square_meter_t kSteerInertia = 0.01_kg_sq_m;
    static constexpr units::kilogram_square_meter_t kDriveInertia = 0.01_kg_sq_m;
    // Simulated voltage necessary to overcome friction
    static constexpr units::volt_t kSteerFrictionVoltage = 0.25_V;
    static constexpr units::volt_t kDriveFrictionVoltage = 0.25_V;

public:
    static constexpr swerve::SwerveDrivetrainConstants DrivetrainConstants = swerve::SwerveDrivetrainConstants{}
            .WithCANBusName(kCANBusName)
            .WithPigeon2Id(kPigeonId)
            .WithPigeon2Configs(pigeonConfigs);

private:
    static constexpr swerve::SwerveModuleConstantsFactory ConstantCreator = swerve::SwerveModuleConstantsFactory{}
            .WithDriveMotorGearRatio(kDriveGearRatio)
            .WithSteerMotorGearRatio(kSteerGearRatio)
            .WithCouplingGearRatio(kCoupleRatio)
            .WithWheelRadius(kWheelRadius)
            .WithSteerMotorGains(steerGains)
            .WithDriveMotorGains(driveGains)
            .WithSteerMotorClosedLoopOutput(kSteerClosedLoopOutput)
            .WithDriveMotorClosedLoopOutput(kDriveClosedLoopOutput)
            .WithSlipCurrent(kSlipCurrent)
            .WithSpeedAt12Volts(kSpeedAt12Volts)
            .WithFeedbackSource(kSteerFeedbackType)
            .WithDriveMotorInitialConfigs(driveInitialConfigs)
            .WithSteerMotorInitialConfigs(steerInitialConfigs)
            .WithCANcoderInitialConfigs(cancoderInitialConfigs)
            .WithSteerInertia(kSteerInertia)
            .WithDriveInertia(kDriveInertia)
            .WithSteerFrictionVoltage(kSteerFrictionVoltage)
            .WithDriveFrictionVoltage(kDriveFrictionVoltage);


    // Front Left
    static constexpr int kFrontLeftDriveMotorId = 5;
    static constexpr int kFrontLeftSteerMotorId = 4;
    static constexpr int kFrontLeftEncoderId = 2;
    static constexpr units::turn_t kFrontLeftEncoderOffset = -0.83544921875_tr;
    static constexpr bool kFrontLeftSteerMotorInverted = true;
    static constexpr bool kFrontLeftCANcoderInverted = false;

    static constexpr units::inch_t kFrontLeftXPos = 10.5_in;
    static constexpr units::inch_t kFrontLeftYPos = 10.5_in;

    // Front Right
    static constexpr int kFrontRightDriveMotorId = 7;
    static constexpr int kFrontRightSteerMotorId = 6;
    static constexpr int kFrontRightEncoderId = 3;
    static constexpr units::turn_t kFrontRightEncoderOffset = -0.15234375_tr;
    static constexpr bool kFrontRightSteerMotorInverted = true;
    static constexpr bool kFrontRightCANcoderInverted = false;

    static constexpr units::inch_t kFrontRightXPos = 10.5_in;
    static constexpr units::inch_t kFrontRightYPos = -10.5_in;

    // Back Left
    static constexpr int kBackLeftDriveMotorId = 1;
    static constexpr int kBackLeftSteerMotorId = 0;
    static constexpr int kBackLeftEncoderId = 0;
    static constexpr units::turn_t kBackLeftEncoderOffset = -0.4794921875_tr;
    static constexpr bool kBackLeftSteerMotorInverted = true;
    static constexpr bool kBackLeftCANcoderInverted = false;

    static constexpr units::inch_t kBackLeftXPos = -10.5_in;
    static constexpr units::inch_t kBackLeftYPos = 10.5_in;

    // Back Right
    static constexpr int kBackRightDriveMotorId = 3;
    static constexpr int kBackRightSteerMotorId = 2;
    static constexpr int kBackRightEncoderId = 1;
    static constexpr units::turn_t kBackRightEncoderOffset = -0.84130859375_tr;
    static constexpr bool kBackRightSteerMotorInverted = true;
    static constexpr bool kBackRightCANcoderInverted = false;

    static constexpr units::inch_t kBackRightXPos = -10.5_in;
    static constexpr units::inch_t kBackRightYPos = -10.5_in;


public:
    static constexpr swerve::SwerveModuleConstants FrontLeft = ConstantCreator.CreateModuleConstants(
            kFrontLeftSteerMotorId, kFrontLeftDriveMotorId, kFrontLeftEncoderId, kFrontLeftEncoderOffset,
            kFrontLeftXPos, kFrontLeftYPos, kInvertLeftSide, kFrontLeftSteerMotorInverted, kFrontLeftCANcoderInverted);
    static constexpr swerve::SwerveModuleConstants FrontRight = ConstantCreator.CreateModuleConstants(
            kFrontRightSteerMotorId, kFrontRightDriveMotorId, kFrontRightEncoderId, kFrontRightEncoderOffset,
            kFrontRightXPos, kFrontRightYPos, kInvertRightSide, kFrontRightSteerMotorInverted, kFrontRightCANcoderInverted);
    static constexpr swerve::SwerveModuleConstants BackLeft = ConstantCreator.CreateModuleConstants(
            kBackLeftSteerMotorId, kBackLeftDriveMotorId, kBackLeftEncoderId, kBackLeftEncoderOffset,
            kBackLeftXPos, kBackLeftYPos, kInvertLeftSide, kBackLeftSteerMotorInverted, kBackLeftCANcoderInverted);
    static constexpr swerve::SwerveModuleConstants BackRight = ConstantCreator.CreateModuleConstants(
            kBackRightSteerMotorId, kBackRightDriveMotorId, kBackRightEncoderId, kBackRightEncoderOffset,
            kBackRightXPos, kBackRightYPos, kInvertRightSide, kBackRightSteerMotorInverted, kBackRightCANcoderInverted);

    /**
     * Creates a CommandSwerveDrivetrain instance.
     * This should only be called once in your robot program.
     */
    static subsystems::CommandSwerveDrivetrain CreateDrivetrain()
    {
        return {DrivetrainConstants, FrontLeft, FrontRight, BackLeft, BackRight};
    }
};
