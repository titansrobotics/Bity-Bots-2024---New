#ifndef AUTOS_H
#define AUTOS_H

#include <frc2/command/CommandPtr.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/LauncherSubsystem.h"

namespace autos {

frc2::CommandPtr SimpleAuto(DriveSubsystem* drive);

frc2::CommandPtr ShootAuto(LauncherSubsystem* launcher);

frc2::CommandPtr ShootAndMoveAuto(DriveSubsystem* drive, LauncherSubsystem* launcher);

frc2::CommandPtr ShootAndMoveRightAuto(DriveSubsystem* drive, LauncherSubsystem* launcher);

frc2::CommandPtr ShootAndMoveLeftAuto(DriveSubsystem* drive, LauncherSubsystem* launcher);

frc2::CommandPtr EncoderAuto(DriveSubsystem* drive, LauncherSubsystem* launcher);

}

#endif