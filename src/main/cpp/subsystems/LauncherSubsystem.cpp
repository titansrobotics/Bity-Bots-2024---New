#include "subsystems/LauncherSubsystem.h"

#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/Commands.h>

LauncherSubsystem::LauncherSubsystem() :
    m_bottomMotor{LauncherConstants::kBottomMotorId, rev::CANSparkLowLevel::MotorType::kBrushed},
    m_topMotor{LauncherConstants::kTopMotorId, rev::CANSparkLowLevel::MotorType::kBrushed} {
        m_bottomMotor.SetInverted(true);
        m_topMotor.SetInverted(true);
}

void LauncherSubsystem::Periodic() {}

frc2::CommandPtr LauncherSubsystem::Launch(double topSpeed, double bottomSpeed) {
    return frc2::cmd::Run(
        [this, bottomSpeed, topSpeed] { m_bottomMotor.Set(bottomSpeed);
                                        m_topMotor.Set(topSpeed); }, {this}
    );
}

void LauncherSubsystem::AutoLaunch(double topSpeed, double bottomSpeed) {
    m_bottomMotor.Set(bottomSpeed);
    m_topMotor.Set(topSpeed);
}