// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MENU_SYSTEM_C_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	

public:
	AMovingPlatform();

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	float PlatformSpeed = 20;
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector PlatformTargetLocation;


private:
	FVector GlobalPlatformStartLocation;
	FVector GlobalPlatformTargetLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
