// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "DwarfCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UAnimMontage* AttackAnim;
    
    UPROPERTY(EditAnywhere)
    float Health = 20.0f;
    
    UPROPERTY(EditAnywhere)
    float Damage = 10.0f;
    
    float CurrentDamage;
    
    FTimerHandle Timer;
    APawn* ShmupPlayerActor;
    
    
    ADwarfCharacter();
    
    void StartAttack();
    void StopAttack();
    virtual float TakeDamage(float DamageAmount,
                             struct FDamageEvent const & DamageEvent,
                             class AController * EventInstigator,
                             AActor * DamageCaused) override;
};
