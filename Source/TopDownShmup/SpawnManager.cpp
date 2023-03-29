// Fill out your copyright notice in the Description page of Project Settings.
/*

#include "SpawnManager.h"

void ASpawnManager::SpawnCharacter()
{
	if (DwarfClass)

	{

		UWorld* World = GetWorld();

		if (World)

		{

			FActorSpawnParameters SpawnParams;
			
			SpawnParams.Owner = this;

			SpawnParams.Instigator = GetInstigator();

			int Index = FMath::RandRange(0, 2);

			ATargetPoint* NewLocation = targetPoints[Index];

			FVector LocationOfVector = NewLocation->GetActorLocation();

			FRotator Rotation(0.0f, 0.0f, 0.0f);

			// Spawn the Weapon


			MyDwarf = World->SpawnActor<ADwarfCharacter>(DwarfClass, LocationOfVector, Rotation, SpawnParams);
      
			MyDwarf->SpawnDefaultController();
		}

	}
}

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacter();
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

*/