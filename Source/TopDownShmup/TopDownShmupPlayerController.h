// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "TopDownShmupCharacter.h"
#include "TopDownShmupPlayerController.generated.h"

UCLASS()
class ATopDownShmupPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATopDownShmupPlayerController();
    
    //movement
    void MoveForward(float value);
    void MoveRight(float value);
    
    //looking
    void UpdateMouseLook();
	void OnStartFire();
	void OnStopFire();

    //player
    ATopDownShmupCharacter* ShmupPlayer;
    
protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

};


