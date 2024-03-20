// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadCastInitialization()
{
	
}

void UOverlayWidgetController::BindCallbackDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this,&UOverlayWidgetController::OnHealthChangedFunc);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&UOverlayWidgetController::OnMaxHealthChangedFunc);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddUObject(this,&UOverlayWidgetController::OnManaChangedFunc);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this,&UOverlayWidgetController::OnMaxManaChangedFunc);
}

void UOverlayWidgetController::OnHealthChangedFunc(const FOnAttributeChangeData& Data) const
{
	FOnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChangedFunc(const FOnAttributeChangeData& Data) const
{
	FOnHealthMaxChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnManaChangedFunc(const FOnAttributeChangeData& Data) const
{
	FOnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxManaChangedFunc(const FOnAttributeChangeData& Data) const
{
	FOnMaxManaChanged.Broadcast(Data.NewValue);
}




