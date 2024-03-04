#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>

#include <frc/Timer.h>

#include "Constants.h"

frc::Timer autoTimer;

frc2::CommandPtr autos::SimpleAuto(DriveSubsystem* drive){
    return frc2::FunctionalCommand(
        [] { autoTimer.Reset(); 
             autoTimer.Start(); },
        [drive] { drive->ArcadeDrive(AutoConstants::kSimpleAutoSpeed, 0); },
        [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kSimpleAutoTime); })
        .ToPtr();
}

frc2::CommandPtr autos::ShootAuto(LauncherSubsystem* launcher){
    return frc2::FunctionalCommand(
        [] { autoTimer.Reset();
             autoTimer.Start(); },
        [launcher] { launcher->AutoLaunch(AutoConstants::kShootAutoTopSpeed, AutoConstants::kShootAutoBottomSpeed); },
        [launcher](bool interrupted) {launcher->AutoLaunch(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kShootAutoTime); })
        .ToPtr();
}

frc2::CommandPtr autos::ShootAndMoveAuto(DriveSubsystem* drive, LauncherSubsystem* launcher){
    return frc2::cmd::Sequence(
        frc2::FunctionalCommand(
        [] { autoTimer.Reset();
             autoTimer.Start(); },
        [launcher] { launcher->AutoLaunch(AutoConstants::kShootAutoTopSpeed, AutoConstants::kShootAutoBottomSpeed); },
        [launcher](bool interrupted) {launcher->AutoLaunch(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kShootAutoTime); })
        .ToPtr(),

        frc2::FunctionalCommand(
        [] { autoTimer.Reset(); 
             autoTimer.Start(); },
        [drive] { drive->ArcadeDrive(AutoConstants::kComplexAutoSpeed, 0); },
        [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kDriveTime); })
        .ToPtr()
    );
}

frc2::CommandPtr autos::ShootAndMoveRightAuto(DriveSubsystem* drive, LauncherSubsystem* launcher){
    return frc2::cmd::Sequence(
        frc2::FunctionalCommand(
        [] { autoTimer.Reset();
             autoTimer.Start(); },
        [launcher] { launcher->AutoLaunch(AutoConstants::kShootAutoTopSpeed, AutoConstants::kShootAutoBottomSpeed); },
        [launcher](bool interrupted) {launcher->AutoLaunch(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kShootAutoTime); })
        .ToPtr(),

        frc2::FunctionalCommand(
        [] { autoTimer.Reset(); 
             autoTimer.Start(); },
        [drive] { drive->ArcadeDrive(AutoConstants::kComplexAutoSpeed, AutoConstants::kComplexAutoRot); },
        [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kDriveTime); })
        .ToPtr()
    );
}

frc2::CommandPtr autos::ShootAndMoveLeftAuto(DriveSubsystem* drive, LauncherSubsystem* launcher){
    return frc2::cmd::Sequence(
        frc2::FunctionalCommand(
        [] { autoTimer.Reset();
             autoTimer.Start(); },
        [launcher] { launcher->AutoLaunch(AutoConstants::kShootAutoTopSpeed, AutoConstants::kShootAutoBottomSpeed); },
        [launcher](bool interrupted) {launcher->AutoLaunch(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kShootAutoTime); })
        .ToPtr(),

        frc2::FunctionalCommand(
        [] { autoTimer.Reset(); 
             autoTimer.Start(); },
        [drive] { drive->ArcadeDrive(AutoConstants::kComplexAutoSpeed, -AutoConstants::kComplexAutoRot); },
        [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kDriveTime); })
        .ToPtr()
    );
}

// frc2::CommandPtr autos::TimeAuto(DriveSubsystem* drive, LauncherSubsystem* launcher){
//     return frc2::cmd::Sequence(
//         frc2::cmd::Run(
//             [drive] { drive->ArcadeDrive(AutoConstants::kComplexAutoSpeed, 0); },
//             {drive, launcher})
//         .WithTimeout(AutoConstants::kDriveTime),

//         frc2::cmd::Run(
//             [launcher] { launcher->AutoLaunch(LauncherConstants::kAmpLauncherPercentage); },
//             {drive, launcher})
//         .WithTimeout(AutoConstants::kLaunchTime),

//         frc2::cmd::Run(
//             [drive] { drive->ArcadeDrive(-AutoConstants::kComplexAutoSpeed, 0); },
//             {drive, launcher})
//         .WithTimeout(AutoConstants::kDriveTime)
//     );
// }

frc2::CommandPtr autos::EncoderAuto(DriveSubsystem* drive, LauncherSubsystem* launcher){
    return frc2::cmd::Sequence(
        frc2::FunctionalCommand(
            [drive] { drive->ResetEncoders(); },
            [drive] { drive->ArcadeDrive(AutoConstants::kComplexAutoSpeed, 0); },
            [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
            [drive] {
                return drive->GetAverageEncoderDistance()
                >= AutoConstants::kComplexAutoDistance;
            },
            {drive})
        .ToPtr(),

        frc2::FunctionalCommand(
        [] { autoTimer.Reset();
             autoTimer.Start(); },
        [launcher] { launcher->AutoLaunch(AutoConstants::kShootAutoTopSpeed, AutoConstants::kShootAutoBottomSpeed); },
        [launcher](bool interrupted) {launcher->AutoLaunch(0, 0); },
        [] { return autoTimer.HasElapsed(AutoConstants::kShootAutoTime); })
        .ToPtr(),

        frc2::FunctionalCommand(
            [drive] { drive->ResetEncoders(); },
            [drive] { drive->ArcadeDrive(-AutoConstants::kComplexAutoSpeed, 0); },
            [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
            [drive] {
                return drive->GetAverageEncoderDistance()
                >= -AutoConstants::kComplexAutoDistance;
            },
            {drive})
        .ToPtr()
    );
}