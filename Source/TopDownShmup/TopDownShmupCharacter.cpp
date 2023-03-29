// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupCharacter.h"
#include "TopDownShmup.h"

ATopDownShmupCharacter::ATopDownShmupCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    bIsDead = false;
}

void ATopDownShmupCharacter::BeginPlay()

{

	// Call base class BeginPlay


	Super::BeginPlay();

	// Spawn the weapon, if one was specified
	
	if (WeaponClass)

	{

		UWorld* World = GetWorld();

		if (World)

		{

			FActorSpawnParameters SpawnParams;
			
			SpawnParams.Owner = this;

			SpawnParams.Instigator = GetInstigator();

			// Need to set rotation like this because otherwise gun points down

			// NOTE: This should probably be a blueprint parameter

			FRotator Rotation(0.0f, 0.0f, -90.0f);

			// Spawn the Weapon

			MyWeapon = World->SpawnActor<AWeapon>(WeaponClass, FVector::ZeroVector,

				Rotation, SpawnParams);
            //set the pawn in weapon class to our character?
            MyWeapon->MyPawn = this;
			if (MyWeapon)

			{

				// This is attached to "WeaponPoint" which is defined in the skeleton

				// NOTE: This should probably be a blueprint parameter

				MyWeapon->WeaponMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("WeaponPoint"));
                

			}

		}

	}
	

}

void ATopDownShmupCharacter::OnStartFire()
{
	if(MyWeapon && (!IsDead()))
	{
		MyWeapon->OnStartFire();
	}
    else
    {
        MyWeapon->OnStopFire();
    }
}

void ATopDownShmupCharacter::OnStopFire()
{
	if (MyWeapon && (!IsDead()))
	{
		MyWeapon->OnStopFire();
	}
	
}


float ATopDownShmupCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,

AController* EventInstigator, AActor* DamageCauser)

{

    float ActualDamage = Super::TakeDamage(Damage, DamageEvent,

    EventInstigator, DamageCauser);

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

            bIsDead = true;
            UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetIgnoreLookInput(true);
            UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetIgnoreMoveInput(true);
            
        }

    }

    return ActualDamage;

}

bool ATopDownShmupCharacter::IsDead()
{
       return bIsDead;
}
