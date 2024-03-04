#include "subsystems/ChainSubsystem.h"

#include <frc2/command/CommandPtr.h>

ChainSubsystem::ChainSubsystem() : 
    m_leftMotor{ChainConstants::kLeftMotorId, rev::CANSparkLowLevel::MotorType::kBrushless},
    m_rightMotor{ChainConstants::kRightMotorId, rev::CANSparkLowLevel::MotorType::kBrushless} {
        m_leftMotor.SetInverted(true);
        m_rightMotor.Follow(m_leftMotor, true);
    }

void ChainSubsystem::Periodic() {}

frc2::CommandPtr ChainSubsystem::LiftRobot(double speed) {
    return this->Run(
        [this, speed] { m_leftMotor.Set(speed); }
    );
}