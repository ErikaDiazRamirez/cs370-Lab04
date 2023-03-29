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
    GetWorldTimerManager().SetTimer(TimerHandle, [this]() {ShmupPlayerActor->TakeDamage(Damage, FDamageEvent(), GetInstigatorController(), this);}, CurrentDamage, true);
}

void ADwarfCharacter::StopAttack()
{
    StopAnimMontage(AttackAnim);
    GetWorldTimerManager().ClearTimer(TimerHandle);
}

float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser){

    float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
    //GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("Dwarf Health: %d"), Health), false);

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
            deathTime = PlayAnimMontage(DeathAnim);
            
            //not sure how to do the timer 
            // ShmupPlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

            GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ADwarfCharacter::OnDeathAnimationFinished, deathTime - .25f, false);


        }
    }
    return ActualDamage;
}

//the timer didn't want to take destroy so we made a new function
void ADwarfCharacter::OnDeathAnimationFinished()
{
    Destroy();
    UnPossessed();
    GetWorldTimerManager().ClearTimer(DeathTimerHandle);
}