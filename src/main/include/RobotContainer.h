// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc2/command/Command.h>

#include "Constants.h"

#include "commands/Autos.h"

#include "subsystems/LauncherSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ChainSubsystem.h"
#include "subsystems/IntakeSubsystem.h"

class RobotContainer {
    public:
    RobotContainer();

    void ConfigureBindings();

    frc2::Command* GetAutonomousCommand();

    void UpdateData();

    private:
    frc::Joystick m_driverController {OIConstants::kDriverJoystickId};
    frc::Joystick m_flightController {OIConstants::kFlightJoystickId};

    frc2::JoystickButton m_speakerLaunchButton {&m_flightController, OIConstants::kSpeakerLaunch};
    frc2::JoystickButton m_ampLaunchButton     {&m_flightController, OIConstants::kAmpLaunch};
    frc2::JoystickButton m_intakeButton        {&m_flightController, OIConstants::kIntake};
    frc2::JoystickButton m_conveyerButton      {&m_flightController, OIConstants::kConveyer};
    frc2::JoystickButton m_chainUpButton       {&m_flightController, OIConstants::kChainUp};
    frc2::JoystickButton m_chainDownButton     {&m_flightController, OIConstants::kChainDown};
    
    DriveSubsystem m_drive;
    LauncherSubsystem m_launcher;
    ChainSubsystem m_chain;
    IntakeSubsystem m_intake;

    frc2::CommandPtr m_simpleAuto            {autos::SimpleAuto(&m_drive)};
    frc2::CommandPtr m_shootAuto             {autos::ShootAuto(&m_launcher)};
    frc2::CommandPtr m_shootAndMoveAuto      {autos::ShootAndMoveAuto(&m_drive, &m_launcher)};
    frc2::CommandPtr m_shootAndMoveRightAuto {autos::ShootAndMoveRightAuto(&m_drive, &m_launcher)};
    frc2::CommandPtr m_shootAndMoveLeftAuto  {autos::ShootAndMoveLeftAuto(&m_drive, &m_launcher)};
    frc2::CommandPtr m_encoderAuto           {autos::EncoderAuto(&m_drive, &m_launcher)};

    frc::SendableChooser<frc2::Command*> m_chooser;
 
    // void ConfigureBindings();
};

#endif