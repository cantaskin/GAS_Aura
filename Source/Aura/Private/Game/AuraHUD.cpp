// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& ControllerParams)
{
	if(!OverlayWidgetController)
	{
		OverlayWidgetController  = NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(ControllerParams);
		return  OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerState* PS,APlayerController* PC,UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(),OverlayWidgetClass);

	const FWidgetControllerParams ControllerParams(PS,PC,ASC,AS);
	UOverlayWidgetController* WC = GetOverlayWidgetController(ControllerParams);

	OverlayWidget->SetWidgetController(WC);
	WC->BindCallbackDependencies();
	OverlayWidget->AddToViewport();
}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(),OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
