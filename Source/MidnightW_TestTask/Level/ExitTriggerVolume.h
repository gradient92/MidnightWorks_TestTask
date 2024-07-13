// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "ExitTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class MIDNIGHTW_TESTTASK_API AExitTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

private:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
