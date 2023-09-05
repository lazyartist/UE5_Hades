// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_HadesGameMode.h"
#include "UE5_HadesPlayerController.h"
#include "UE5_HadesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_HadesGameMode::AUE5_HadesGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUE5_HadesPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}