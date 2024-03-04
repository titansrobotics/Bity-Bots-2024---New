#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include <frc/Encoder.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>


#include "Constants.h"


class DriveSubsystem : public frc2::SubsystemBase {
    public:

    DriveSubsystem();

    void Periodic() override;

    void ArcadeDrive(double fwd, double rot);

    void ResetEncoders();

    double GetAverageEncoderDistance();

    frc::Encoder& GetLeftEncoder();
    frc::Encoder& GetRightEncoder();


    private:

    rev::CANSparkMax m_leftMotor1;
    rev::CANSparkMax m_leftMotor2;
    rev::CANSparkMax m_rightMotor1;
    rev::CANSparkMax m_rightMotor2;

    frc::Encoder m_leftEncoder;
    frc::Encoder m_rightEncoder;
};

#endif