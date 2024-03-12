// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;
/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

	
public:
	AAuraPlayerController();
	void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
		UPROPERTY(EditDefaultsOnly, Category= "Input")
		TObjectPtr<UInputMappingContext> MappingContext;

		UPROPERTY(EditDefaultsOnly, Category= "Input")
		TObjectPtr<UInputAction> MoveAction;

		void Move(const FInputActionValue& InputActionValue);

		void CursorTrace();
		TObjectPtr<IEnemyInterface> LastActor;
		TObjectPtr<IEnemyInterface> ThisActor;
};
