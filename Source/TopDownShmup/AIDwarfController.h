// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "TopDownShmupCharacter.h"
#include "AIDwarfController.generated.h"

/**
 * 
 */

enum class EDwarfState : short
{
    EStart, EChasing, EAttacking, EDead, EUnknown
};

UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
	
    
    ATopDownShmupCharacter* ShmupPlayer;
    APawn* MyPawn;
    EDwarfState CurrentState;
    APawn* ShmupPlayerActor;
    
    virtual void OnPossess(APawn*) override;
    
    virtual void BeginPlay() override;
    
    virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
    
    void SetState();
    
    
};
