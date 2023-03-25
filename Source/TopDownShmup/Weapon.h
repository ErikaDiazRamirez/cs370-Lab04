// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Sound/SoundCue.h>
#include "Weapon.generated.h"

UCLASS()
class TOPDOWNSHMUP_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
    
    
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Weapon)
    USkeletalMeshComponent* WeaponMesh;


	//sound cue components
	UPROPERTY(EditDefaultsOnly, Category = Sound)
	USoundCue* FireLoopSound;


	UPROPERTY(EditDefaultsOnly, Category = Sound)
	USoundCue* FireFinishSound;

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//fire audio component that we will capture so that we can stop the loop later
	UPROPERTY(Transient)
	UAudioComponent* FireAC;

	UAudioComponent* PlayWeaponSound(USoundCue* Sound);

	//fire particle effect
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	UParticleSystem* MuzzleFX;

	UPROPERTY(Transient)
	UParticleSystemComponent* FireFX;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    virtual void OnStartFire();
    virtual void OnStopFire();
};
