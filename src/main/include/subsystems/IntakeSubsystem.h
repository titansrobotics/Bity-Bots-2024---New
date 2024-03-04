#ifndef INTAKE_SUBSYSTEM_H
#define INTAKE_SUBSYSTEM_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
    public:

    IntakeSubsystem();

    void Periodic() override;

    frc2::CommandPtr Intake(double speed);
    frc2::CommandPtr Conveyer(double speed);
    
    void UpdateData();
    
    private:

    rev::CANSparkMax m_topMotor;
    rev::CANSparkMax m_bottomMotor;
};

#endif