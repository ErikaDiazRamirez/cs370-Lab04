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
    
    ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    MoveToActor(ShmupPlayerActor, 5.0f);

    //ShmupPlayer = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}


void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("MOVE COMPLETE")));
}
