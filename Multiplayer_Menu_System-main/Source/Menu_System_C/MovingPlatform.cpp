// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalPlatformStartLocation = GetActorLocation();
	GlobalPlatformTargetLocation = GetTransform().TransformPosition(PlatformTargetLocation);

}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority()) //Not on server == client.
		{

			FVector PlatformLocation = GetActorLocation();

			float JourneyLength = (GlobalPlatformTargetLocation - GlobalPlatformStartLocation).Size();
			float JourneyTravelled = (PlatformLocation - GlobalPlatformStartLocation).Size();


			if (JourneyTravelled >= JourneyLength)
			{
				FVector Swap = GlobalPlatformStartLocation;
				GlobalPlatformStartLocation = GlobalPlatformTargetLocation;
				GlobalPlatformTargetLocation = Swap;
			}

			FVector Direction = (GlobalPlatformTargetLocation - GlobalPlatformStartLocation).GetSafeNormal();
			PlatformLocation += (PlatformSpeed * DeltaTime * Direction);
			SetActorLocation(PlatformLocation);

		}
	}
}


void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}