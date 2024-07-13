// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible_Coin.h"

#include "MidnightW_PlayerState.h"
#include "MidnightW_TestTaskCharacter.h"

// Sets default values
ACollectible_Coin::ACollectible_Coin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(RootComponent);

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	CoinMesh->SetupAttachment(SceneComponent);

}

void ACollectible_Coin::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	//AMidnightW_TestTaskCharacter* Character;
	if(const AMidnightW_TestTaskCharacter* Character = Cast<AMidnightW_TestTaskCharacter>(OtherActor))
	{
		Cast<AMidnightW_PlayerState>(Character->GetPlayerState())->IncrementCollectedCoins();

		
		GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ACollectible_Coin::DestroyCoin);
	}
}

void ACollectible_Coin::DestroyCoin()
{
	Destroy();
}

// Called when the game starts or when spawned
void ACollectible_Coin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectible_Coin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

