// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Weapon.h"
#include "TopDownShmupCharacter.generated.h"

UCLASS(Blueprintable)
class ATopDownShmupCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

    UPROPERTY(EditAnywhere)
    float Health = 100.0f;

public:
	ATopDownShmupCharacter();

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

    UPROPERTY(EditAnywhere, Category = Weapon)
    TSubclassOf<AWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly)
        UAnimMontage* DeathAnim;
    
    void BeginPlay() override;
    virtual float TakeDamage(float DamageAmount,
                             struct FDamageEvent const & DamageEvent,
                             class AController * EventInstigator,
                             AActor * DamageCaused) override;
	void OnStartFire();
	void OnStopFire();
    
    bool bIsDead;

    FTimerHandle DeathTimerHandle;
    void OnDeathAnimationFinished();

    float deathTime = 0.0f;

    bool IsDead();
    
private:
    AWeapon* MyWeapon;
    
};

