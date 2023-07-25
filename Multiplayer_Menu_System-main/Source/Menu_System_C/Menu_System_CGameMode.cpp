// Copyright Epic Games, Inc. All Rights Reserved.

#include "Menu_System_CGameMode.h"
#include "Menu_System_CCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMenu_System_CGameMode::AMenu_System_CGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
