#ifndef CHAIN_SUBSYSTEM_H
#define CHAIN_SUBSYSTEM_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ChainSubsystem : public frc2::SubsystemBase {
    public:

    ChainSubsystem();

    void Periodic() override;

    frc2::CommandPtr LiftRobot(double speed);


    private:

    rev::CANSparkMax m_leftMotor;
    rev::CANSparkMax m_rightMotor;
};

#endif