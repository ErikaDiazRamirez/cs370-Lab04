// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"
#include "DwarfCharacter.h"

ADwarfCharacter::ADwarfCharacter()
{
    AIControllerClass = AAIDwarfController::StaticClass();
    
//    DwarfMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Dwarf"));
//    RootComponent = DwarfMesh;
}
