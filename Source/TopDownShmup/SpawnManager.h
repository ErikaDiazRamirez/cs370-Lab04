// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "DwarfCharacter.h"
#include "Math/UnrealMathUtility.h"
#include "SpawnManager.generated.h"

UCLASS()
class TOPDOWNSHMUP_API ASpawnManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Spawn)
	TArray<ATargetPoint*> targetPoints;
	
	UPROPERTY(EditAnywhere, Category = Spawn)
	TSubclassOf<ACharacter> CharacterSpawn;


	UPROPERTY(EditAnywhere, Category = Spawn)
	float MinSpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn)
	float MaxSpawnTime;


	void SpawnCharacter();

public:	
	// Sets default values for this actor's properties
	ASpawnManager();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	ADwarfCharacter* MyDwarf;
};
