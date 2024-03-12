// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "Characters/AuraBaseCharacter.h"
#include "Components/SphereComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

		SphereComponent->OnComponentBeginOverlap.AddDynamic(this,&AAuraEffectActor::OnOverlapBegin);
}

// Called every frame
void AAuraEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAuraEffectActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		if(AuraAttributeSet)
		{
			UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
			{
				MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25);
			}
		}
	}
}

