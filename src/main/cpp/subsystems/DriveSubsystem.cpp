#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    m_leftMotor1   {DriveConstants::kLeftMotor1Id, rev::CANSparkLowLevel::MotorType::kBrushed},
    m_leftMotor2  {DriveConstants::kLeftMotor2Id, rev::CANSparkLowLevel::MotorType::kBrushed},
    m_rightMotor1 {DriveConstants::kRightMotor1Id, rev::CANSparkLowLevel::MotorType::kBrushed},
    m_rightMotor2 {DriveConstants::kRightMotor2Id, rev::CANSparkLowLevel::MotorType::kBrushed},
    m_leftEncoder  {DriveConstants::kLeftEncoderId[0], DriveConstants::kLeftEncoderId[1]},
    m_rightEncoder {DriveConstants::kRightEncoderId[0], DriveConstants::kRightEncoderId[1]} {

        m_leftMotor1.SetInverted(true);
        m_leftMotor2.Follow(m_leftMotor1);

        m_rightMotor2.Follow(m_rightMotor1);

        m_leftEncoder.SetDistancePerPulse(DriveConstants::kDistancePerPulse);
        m_rightEncoder.SetDistancePerPulse(DriveConstants::kDistancePerPulse);
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot){
    m_leftMotor1.Set(fwd + rot);
    m_rightMotor1.Set(fwd - rot);
}

void DriveSubsystem::ResetEncoders() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}

double DriveSubsystem::GetAverageEncoderDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() {
    return m_leftEncoder;
}

frc::Encoder& DriveSubsystem::GetRightEncoder() {
    return m_rightEncoder;
}