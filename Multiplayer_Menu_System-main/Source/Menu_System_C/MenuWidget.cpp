// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* SetupMenuInterface)
{
	this->MenuInterface = SetupMenuInterface;
}

void UMenuWidget::Setup()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	this->AddToViewport();

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::NativeDestruct()
{
	this->RemoveFromViewport();
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputGameModeData;

	PlayerController->SetInputMode(InputGameModeData);
	PlayerController->bShowMouseCursor = false;
	Super::NativeDestruct();
}
