// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelScriptActor.h"

#include "GameFramework\Actor.h"
#include "Kismet\GameplayStatics.h"
#include "Math\UnrealMathUtility.h"
#include "Misc\OutputDeviceNull.h"

AMainLevelScriptActor::AMainLevelScriptActor()
{
	ConstructorHelpers::FClassFinder<AActor> HealSpotBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/HealthPickup_Blueprint"));
	HealSpotClass = HealSpotBPClass.Class;
}

void AMainLevelScriptActor::ResetHealSpots(AActor* Caller)
{
	TArray<AActor*> HealSpots;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), HealSpotClass, HealSpots);

	if (Caller) {
		HealSpots.Remove(Caller);
	}

	auto randomActor = FMath::RandRange(0, HealSpots.Num() - 1);
	FOutputDeviceNull ar;
	HealSpots[randomActor]->CallFunctionByNameWithArguments(TEXT("ActivatePickUp"), ar, nullptr, true);
}
