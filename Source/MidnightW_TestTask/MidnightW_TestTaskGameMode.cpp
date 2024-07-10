// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightW_TestTaskGameMode.h"
#include "MidnightW_TestTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMidnightW_TestTaskGameMode::AMidnightW_TestTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
