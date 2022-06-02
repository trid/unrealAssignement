// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MainLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSAMPLE_API AMainLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	AMainLevelScriptActor();
private:
	TSubclassOf<AActor> HealSpotClass;

	UFUNCTION(BlueprintCallable)
	void ResetHealSpots(AActor* Caller);
};
