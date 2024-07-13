// Fill out your copyright notice in the Description page of Project Settings.


#include "MidnightW_PlayerState.h"

#include "Collectible_Coin.h"
#include "MidnightW_PlayerController.h"
#include "Kismet/GameplayStatics.h"

AMidnightW_PlayerState::AMidnightW_PlayerState()
{
	TArray<AActor*> FoundCoins;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACollectible_Coin::StaticClass(), FoundCoins);

	CollectedCoins_OnMap = FoundCoins.Num();
}

bool AMidnightW_PlayerState::CanPassLevel()
{
	return bCanPassLevel;
}

void AMidnightW_PlayerState::IncrementCollectedCoins()
{
	CollectedCoins_Amount++;

	OnCoinsAmountUpdated.Broadcast();
	
	if(CollectedCoins_Amount == CollectedCoins_OnMap)
	{
		bCanPassLevel = true;
		OnAllCoinsCollected.Broadcast();
	}
}

void AMidnightW_PlayerState::TryPassLevel()
{
	if(bCanPassLevel)
	{
		OnLevelPassed.Broadcast();
	}
}


FCoinsStruct AMidnightW_PlayerState::GetCollectedCoins()
{
	return FCoinsStruct(CollectedCoins_Amount,CollectedCoins_OnMap);
}
