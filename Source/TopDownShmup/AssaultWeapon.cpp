// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultWeapon.h"

AAssaultWeapon::AAssaultWeapon()
{
    FireRate = 0.05f;
    WeaponRange = 10000.0f;

}

void AAssaultWeapon::OnStartFire()
{
    Super::OnStartFire();
}


void AAssaultWeapon::OnStopFire()
{
    Super::OnStopFire();
}


void AAssaultWeapon::WeaponTrace()

{

    static FName WeaponFireTag = FName(TEXT("WeaponTrace"));

    static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));

    // Start from the muzzle's position

    FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);

    // Get forward vector of MyPawn

    FVector Forward = MyPawn->GetActorForwardVector();

    // Calculate end position

    FVector EndPos = /*TODO: Figure out vector math based on the WeaponRange*/;

    // Perform line trace to retrieve hit info

    FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());

    // This fires the ray and checks against all objects w/ collision

    FHitResult Hit(ForceInit);

    GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos,

        FCollisionObjectQueryParams::AllObjects, TraceParams);

    // Did this hit anything?

    if (Hit.bBlockingHit)

    {

        // TODO: Actually do something

    }

}