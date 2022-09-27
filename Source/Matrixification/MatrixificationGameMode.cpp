// Copyright Epic Games, Inc. All Rights Reserved.

#include "MatrixificationGameMode.h"
#include "MatrixificationHUD.h"
#include "MatrixificationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMatrixificationGameMode::AMatrixificationGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Smorty"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	static ConstructorHelpers::FObjectFinder<UClass> test(TEXT("/Game/Blueprints/FPS_HUD.FPS_HUD_C"));
	HUDClass = test.Object;
}
