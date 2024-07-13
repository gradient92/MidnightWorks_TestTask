// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MidnightW_PlayerState.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCoinsAmountUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllCoinsCollected);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelPassed);

USTRUCT(BlueprintType)
	struct FCoinsStruct
	{
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoinsStruct")
		int32 CollectedCoins_Amount;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoinsStruct")
		int32 CollectedCoins_OnMap;
	};

UCLASS()
class MIDNIGHTW_TESTTASK_API AMidnightW_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
	AMidnightW_PlayerState();

	UPROPERTY()
	int8 CollectedCoins_Amount = 0;

	UPROPERTY()
	int8 CollectedCoins_OnMap = 0;

	UPROPERTY()
	bool bCanPassLevel = false;
	
public:

	UFUNCTION(Blueprintable)
	bool CanPassLevel();
	
	UFUNCTION(BlueprintCallable)
	void IncrementCollectedCoins();

	UFUNCTION(BlueprintCallable)
	void TryPassLevel();

	UPROPERTY(BlueprintAssignable)
	FOnCoinsAmountUpdated OnCoinsAmountUpdated;
    
	UPROPERTY(BlueprintAssignable)
	FOnAllCoinsCollected OnAllCoinsCollected;

	UPROPERTY(BlueprintAssignable)
	FOnLevelPassed OnLevelPassed;
	
	UFUNCTION(BlueprintCallable)
	FCoinsStruct GetCollectedCoins();
};
