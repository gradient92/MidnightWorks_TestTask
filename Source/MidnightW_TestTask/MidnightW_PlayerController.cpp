// Fill out your copyright notice in the Description page of Project Settings.


#include "MidnightW_PlayerController.h"

#include "MidnightW_PlayerState.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AMidnightW_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	AMidnightW_PlayerState* MidnightW_PlayerState = GetPlayerState<AMidnightW_PlayerState>();
	if (MidnightW_PlayerState)
	{
		MidnightW_PlayerState->OnLevelPassed.AddDynamic(this, &AMidnightW_PlayerController::Win);
	}
}

void AMidnightW_PlayerController::Die()
{
	OnDie.Broadcast();
	FTimerHandle RestartTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(RestartTimerHandle, this, &APlayerController::RestartLevel, 3.0f, false);
}

void AMidnightW_PlayerController::Win()
{
	GetCharacter()->DisableInput(this);
	
	FTimerHandle WinTimerHandle;
	
	GetWorld()->GetTimerManager().SetTimer(WinTimerHandle, [&]()
	{
		UGameplayStatics::OpenLevel(GetWorld(),"MenuLevel");
	}, 3, false);
}
