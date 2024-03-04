#ifndef LAUNCHER_SUBSYSTEM_H
#define LAUNCHER_SUBSYSTEM_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class LauncherSubsystem : public frc2::SubsystemBase {
    public:

    LauncherSubsystem();

    void Periodic() override;

    frc2::CommandPtr Launch(double topSpeed, double bottomSpeed);
    void AutoLaunch(double topSpeed, double bottomSpeed);

    
    private:

    rev::CANSparkMax m_bottomMotor;
    rev::CANSparkMax m_topMotor;
};

#endif