// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
    RootComponent = WeaponMesh;
    
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnStartFire()
{
    FireAC = PlayWeaponSound(FireLoopSound);
    FireFX = UGameplayStatics::SpawnEmitterAttached(MuzzleFX, WeaponMesh, TEXT("MuzzleFlashSocket"));
}

void AWeapon::OnStopFire()
{
    if (FireAC) 
    {
        FireAC->Stop();
        PlayWeaponSound(FireFinishSound);
        FireFX->DeactivateSystem();
    }
 }



UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* Sound)

{

    UAudioComponent* AC = NULL;

    if (Sound)

    {

        AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);

    }

    return AC;

}

