// Fill out your copyright notice in the Description page of Project Settings.


#include "MidnightW_PlayerState.h"

#include "MidnightW_TestTask/Level/Collectible_Coin.h"
#include "Kismet/GameplayStatics.h"


AMidnightW_PlayerState::AMidnightW_PlayerState()
{
	TArray<AActor*> FoundCoins;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACollectible_Coin::StaticClass(), FoundCoins);

	CollectedCoins_OnMap = FoundCoins.Num();
}

bool AMidnightW_PlayerState::CanPassLevel() const
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
	}
}

void AMidnightW_PlayerState::TryPassLevel() const
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
