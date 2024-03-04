#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/FunctionalCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>

IntakeSubsystem::IntakeSubsystem() :
    m_topMotor{IntakeConstants::kTopMotorId, rev::CANSparkMax::MotorType::kBrushless},
    m_bottomMotor{IntakeConstants::kBottomMotorId, rev::CANSparkMax::MotorType::kBrushless} {
        m_bottomMotor.SetInverted(true);
}

void IntakeSubsystem::Periodic() {}

frc2::CommandPtr IntakeSubsystem::Intake(double speed) {
    return this->Run(
        [this, speed] { m_topMotor.Set(speed);
                        m_bottomMotor.Set(speed);}
    );
}

frc2::CommandPtr IntakeSubsystem::Conveyer(double speed) {
    return this->Run(
        [this, speed] { m_topMotor.Set(speed); }
    );
}

void IntakeSubsystem::UpdateData(){
    // frc::SmartDashboard::PutNumber("Top Temp", m_topMotor.GetMotorTemperature());
    // frc::SmartDashboard::PutNumber("Bottom Temp", m_bottomMotor.GetMotorTemperature());
    // frc::SmartDashboard::PutNumber("Top Current", m_topMotor.GetOutputCurrent());
    // frc::SmartDashboard::PutNumber("Bottom Current", m_bottomMotor.GetOutputCurrent());
}