// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Commands.h>


RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("Simple Auto", m_simpleAuto.get());
    m_chooser.AddOption("Shoot Auto", m_shootAuto.get());
    m_chooser.AddOption("Shoot And Move Auto", m_shootAndMoveAuto.get());
    m_chooser.AddOption("Shoot And Move Right Auto", m_shootAndMoveRightAuto.get());
    m_chooser.AddOption("Shoot And Move Left Auto", m_shootAndMoveLeftAuto.get());
    m_chooser.AddOption("Encoder Auto", m_encoderAuto.get());

    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    ConfigureBindings();

    m_drive.SetDefaultCommand(frc2::cmd::Run(
    [this] {
    m_drive.ArcadeDrive(m_driverController.GetRawAxis(OIConstants::kDriveForwardAxisId) * DriveConstants::kDriveForwardPercentage,
                        m_driverController.GetRawAxis(OIConstants::kDriveRotationAxisId) * DriveConstants::kDriveRotationPercentage);
    },
    {&m_drive}));
}

void RobotContainer::ConfigureBindings() {
    m_speakerLaunchButton
    .OnTrue(m_launcher.Launch(LauncherConstants::kSpeakerTopPercentage, LauncherConstants::kSpeakerBottomPercentage))
    .OnFalse(m_launcher.Launch(0, 0));

    m_ampLaunchButton
    .OnTrue(m_launcher.Launch(LauncherConstants::kAmpTopPercentage, LauncherConstants::kAmpBottomPercentage))
    .OnFalse(m_launcher.Launch(0, 0));

    m_intakeButton
    .OnTrue(m_intake.Intake(IntakeConstants::kIntakePercentage))
    .OnFalse(m_intake.Intake(0));

    m_conveyerButton
    .OnTrue(m_intake.Conveyer(IntakeConstants::kConveyerPercentage))
    .OnFalse(m_intake.Conveyer(0));

    m_chainUpButton
    .OnTrue(m_chain.LiftRobot(ChainConstants::kChainPercentage))
    .OnFalse(m_chain.LiftRobot(0));

    m_chainDownButton
    .OnTrue(m_chain.LiftRobot(-ChainConstants::kChainPercentage))
    .OnFalse(m_chain.LiftRobot(0));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    return m_chooser.GetSelected();
}

void RobotContainer::UpdateData() {
    m_intake.UpdateData();
}