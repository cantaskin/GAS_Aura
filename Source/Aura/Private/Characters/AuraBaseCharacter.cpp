// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraBaseCharacter.h"

// Sets default values
AAuraBaseCharacter::AAuraBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


// Called when the game starts or when spawned
void AAuraBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AAuraBaseCharacter::GetAbilitySystemComponent() const 
{
	return  AbilitySystemComponent;
}

UAttributeSet* AAuraBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}



