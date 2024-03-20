// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacter.h"
#include "AbilitySystemComponent.h"
#include "Game/AuraHUD.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init Ability Actor In Server
	InitAbilityActorInfo();
	
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init Ability Actor In Client

	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	if(AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(GetPlayerState()))
	{
		AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState,this);
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AttributeSet = AuraPlayerState->GetAttributeSet();
		
		if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			if(AAuraHUD* HUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
			{
				HUD->InitOverlay(AuraPlayerState,PlayerController,AbilitySystemComponent,AttributeSet);
			}
		}
	}
}