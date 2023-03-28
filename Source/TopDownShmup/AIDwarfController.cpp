// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "Engine/Engine.h"
#include "AIDwarfController.h"

void AAIDwarfController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    MyPawn = InPawn;
}

void AAIDwarfController::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentState(EDwarfState::EStart);
    ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    MoveToActor(ShmupPlayerActor, 5.0f);

    //ShmupPlayer = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AAIDwarfController::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    if (GetCurrentState() == EDwarfState::EStart) 
    {
        SetCurrentState(EDwarfState::EChasing);
    }
    if ((GetCurrentState() == EDwarfState::EAttacking) && (ShmupPlayerActor->GetDistanceTo(MyPawn) > range)) {
        SetCurrentState(EDwarfState::EChasing);
    }
}

void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("MOVE COMPLETE")));
    SetCurrentState(EDwarfState::EAttacking);
}


EDwarfState AAIDwarfController::GetCurrentState() const 
{
    return CurrentState;
}


void AAIDwarfController::SetCurrentState(EDwarfState NewState)
{
    CurrentState = NewState;
    HandleNewState(NewState);
}

void AAIDwarfController::HandleNewState(EDwarfState NewState)
{
    switch (NewState)
    {
        case EDwarfState::EChasing:
        {
            //call move function
            Move();
        }
        break;

        case EDwarfState::EAttacking:
        {
            
        }
        break;

        case EDwarfState::EDead:
        {
            //call move function
        }
        break;

        default:
        case EDwarfState::EUnknown:
        {
            //call move function
        }
        break;
    }
}

void AAIDwarfController::Move()
{
    ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    MoveToActor(ShmupPlayerActor, 5.0f);
    SetCurrentState(EDwarfState::EChasing);
}