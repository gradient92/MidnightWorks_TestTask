// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightW_TestTaskGameMode.h"

#include "MidnightW_TestTask/Player/MidnightW_PlayerController.h"
#include "MidnightW_PlayerState.h"
#include "GameFramework/HUD.h"
#include "UObject/ConstructorHelpers.h"

AMidnightW_TestTaskGameMode::AMidnightW_TestTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	PlayerStateClass = AMidnightW_PlayerState::StaticClass();
	
	static ConstructorHelpers::FClassFinder<AHUD> HUD_BPClass(TEXT("/Script/Engine.Blueprint'/Game/Widgets/GameLevel/MidnightW_HUD_BP.MidnightW_HUD_BP_C'"));
	if (HUD_BPClass.Class != NULL)
	{
		HUDClass = HUD_BPClass.Class;
	}

	PlayerControllerClass = AMidnightW_PlayerController::StaticClass();
}
