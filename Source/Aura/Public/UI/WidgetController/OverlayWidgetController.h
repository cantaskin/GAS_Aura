// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature,float,OnHealthChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthMaxHealthChangedSignature,float,OnHealthMaxChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature,float,OnManaChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature,float,OnMaxManaChanged);
/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual  void BroadCastInitialization() override;
	virtual void BindCallbackDependencies() override;

	UPROPERTY(BlueprintAssignable,Category="GAS|Attribute")
	FOnHealthChangedSignature FOnHealthChanged;

	UPROPERTY(BlueprintAssignable,Category="GAS|Attribute")
	FOnHealthMaxHealthChangedSignature FOnHealthMaxChanged;

	UPROPERTY(BlueprintAssignable,Category="GAS|Attribute")
	FOnManaChangedSignature FOnManaChanged;

	UPROPERTY(BlueprintAssignable,Category="GAS|Attribute")
	FOnMaxManaChangedSignature FOnMaxManaChanged;

private:

	void OnHealthChangedFunc(const FOnAttributeChangeData& Data) const;
	void OnMaxHealthChangedFunc(const FOnAttributeChangeData& Data) const;
	void OnManaChangedFunc(const FOnAttributeChangeData& Data) const;
	void OnMaxManaChangedFunc(const FOnAttributeChangeData& Data) const;
	
};
