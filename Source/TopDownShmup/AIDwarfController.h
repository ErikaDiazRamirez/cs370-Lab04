// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "TopDownShmupCharacter.h"
#include "DwarfCharacter.h"
#include "AIDwarfController.generated.h"

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
    APawn* ShmupPlayerActor;
    ADwarfCharacter* MyDwarf;
    float range = 150.0f;

    //Dwarf state 
    EDwarfState GetCurrentState() const;
    void SetCurrentState(EDwarfState NewState);
    
    virtual void OnPossess(APawn*) override;
    virtual void OnUnPossess() override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
    
private:
    EDwarfState CurrentState;
    void HandleNewState(EDwarfState NewState);
    void Move();
};
