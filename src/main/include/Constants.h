#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <units/time.h>

constexpr double kPI = 3.14159265358979323846;


namespace DriveConstants {

    constexpr int kLeftMotor1Id  {4};
    constexpr int kLeftMotor2Id  {5};
    constexpr int kRightMotor1Id {6};
    constexpr int kRightMotor2Id {7};

    constexpr int kLeftEncoderId[2]  {0, 1};
    constexpr int kRightEncoderId[2] {2, 3};

    constexpr double kCountsPerRevolution {2048};
    constexpr double kWheelDiameter       {6};
    constexpr double kDistancePerPulse    {kWheelDiameter*kPI/kCountsPerRevolution};
    //Assuming the encoder is mounted directly on the wheel shaft

    constexpr double kDriveForwardPercentage  {0.70};
    constexpr double kDriveRotationPercentage {0.55};
}


namespace ChainConstants {

    constexpr int kLeftMotorId  {10};
    constexpr int kRightMotorId {11};

    constexpr double kChainPercentage {0.2};
}


namespace LauncherConstants {

    constexpr int kBottomMotorId {8};
    constexpr int kTopMotorId    {9};

    constexpr double kSpeakerTopPercentage {1};
    constexpr double kSpeakerBottomPercentage {1};
    constexpr double kAmpTopPercentage {0.4};
    constexpr double kAmpBottomPercentage {0.4};

}


namespace IntakeConstants {
    
    constexpr int kTopMotorId    {3};
    constexpr int kBottomMotorId {2};

    constexpr double kIntakePercentage   {0.2};
    constexpr double kConveyerPercentage {0.1};

}


namespace OIConstants {
    
    constexpr int kDriverJoystickId    {0}; //console controller
    constexpr int kDriveForwardAxisId  {1};

    constexpr int kFlightJoystickId    {1};
    constexpr int kDriveRotationAxisId {4};
    constexpr int kSpeakerLaunch       {1}; // 'Trigger'
    constexpr int kAmpLaunch           {2}; // 'Thumb Button'
    constexpr int kIntake              {3}; // 'Left Bottom'
    constexpr int kConveyer            {5}; // 'Left Top'
    constexpr int kChainDown           {4}; // 'Right Bottom'
    constexpr int kChainUp             {6}; // 'Right Top'
}


namespace AutoConstants {
    constexpr double kSimpleAutoSpeed               {0.3};
    constexpr units::time::second_t kSimpleAutoTime {3.0_s};

    constexpr double kShootAutoTopSpeed {0.1};
    constexpr double kShootAutoBottomSpeed {0.1};
    constexpr units::time::second_t kShootAutoTime {1.2_s};

    constexpr double kComplexAutoSpeed {-0.3};
    constexpr double kComplexAutoRot   {0.1};
    constexpr int kComplexAutoDistance {3};

    constexpr units::time::second_t kLaunchTime {1.0_s};
    constexpr units::time::second_t kDriveTime  {2.0_s};
    
}

#endif