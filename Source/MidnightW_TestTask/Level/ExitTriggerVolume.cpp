// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitTriggerVolume.h"

#include "MidnightW_TestTask/Game/MidnightW_PlayerState.h"
#include "MidnightW_TestTask/Player/MidnightW_TestTaskCharacter.h"

void AExitTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(const AMidnightW_TestTaskCharacter* Character = Cast<AMidnightW_TestTaskCharacter>(OtherActor))
	{
		Cast<AMidnightW_PlayerState>(Character->GetPlayerState())->TryPassLevel();
	}
}
