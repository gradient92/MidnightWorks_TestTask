// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MidnightW_PlayerController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDie);

UCLASS()
class MIDNIGHTW_TESTTASK_API AMidnightW_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void Win();

public:
	UFUNCTION(BlueprintCallable)
	void Die();

	UPROPERTY(BlueprintAssignable)
	FOnDie OnDie;
	
};
