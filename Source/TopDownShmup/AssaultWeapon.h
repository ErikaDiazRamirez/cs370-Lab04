// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "TopDownShmupCharacter.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()
public:

    AAssaultWeapon();
    virtual void OnStartFire() override;
    virtual void OnStopFire() override;


    float FireRate;
    float WeaponRange;

    UPROPERTY(EditDefaultsOnly)
    UParticleSystem* HitEffect;

protected:
    void WeaponTrace();

};
