// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"
#include "DwarfCharacter.h"

ADwarfCharacter::ADwarfCharacter()
{
    AIControllerClass = AAIDwarfController::StaticClass();
//    DwarfMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Dwarf"));
//    RootComponent = DwarfMesh;
}

void ADwarfCharacter::StartAttack()
{
    CurrentDamage = PlayAnimMontage(AttackAnim);
    ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    GetWorldTimerManager().SetTimer(Timer, [this]() {ShmupPlayerActor->TakeDamage(Damage, FDamageEvent(), GetInstigatorController(), this);}, CurrentDamage, true);
}

void ADwarfCharacter::StopAttack()
{
    StopAnimMontage(AttackAnim);
    GetWorldTimerManager().ClearTimer(Timer);
}

float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser){

    float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
    if (ActualDamage > 0.0f)
    {
        //TODO: Add a debug message on screen to know dwarf got hit

        //Reduce health points
        Health -= ActualDamage;

        if (Health <= 0.0f)
        {
            // We're dead
            SetCanBeDamaged(false); // Don't allow further damage

            // TODO: Process death

            // Stop attack animation,
            StopAttack();

            //********complete the death animation
            PlayAnimMontage(DeathAnim);
            
            //not sure how to do the timer 
            // ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
            //  GetWorldTimerManager().SetTimer(Timer, [this]() {ShmupPlayerActor->TakeDamage(Damage, FDamageEvent(), GetInstigatorController(), this); }, CurrentDamage, true);
            
            // UnPossess the AI controller,
            RemoveFromRoot();
            
            // Remove the dwarf from the world
            Destroy();
        }
    }
    return ActualDamage;
}
