// Copyright Epic Games, Inc. All Rights Reserved.

#include "thirdPersonSampleGameMode.h"
#include "thirdPersonSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/HUD.h"

AthirdPersonSampleGameMode::AthirdPersonSampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<AHUD> HUDBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Widgets/Player_HUD"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		HUDClass = HUDBPClass.Class;
	}
}
