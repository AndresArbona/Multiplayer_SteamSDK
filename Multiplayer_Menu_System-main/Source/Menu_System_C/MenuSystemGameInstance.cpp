// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystemGameInstance.h"

#include "Blueprint//UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Menu_System_CGameMode.h"
#include "MainMenu.h"
#include "MenuWidget.h"

UMenuSystemGameInstance::UMenuSystemGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return; 
	MenuClass = MenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> PauseMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGamePauseMenu"));
	if (!ensure(PauseMenuBPClass.Class != nullptr)) return;
	PauseMenuClass = PauseMenuBPClass.Class;

}

void UMenuSystemGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *PauseMenuClass->GetName());
}

void UMenuSystemGameInstance::LoadMenu() 
{
	if (!ensure(MenuClass != nullptr)) return; 

	Menu = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr))  return; 

	Menu->Setup();
	Menu->SetMenuInterface(this);

}

void UMenuSystemGameInstance::LoadPauseMenu()
{
	if (!ensure(PauseMenuClass != nullptr)) return;

	UMenuWidget* MenuWidget = CreateWidget<UMenuWidget>(this, PauseMenuClass);
	if (!ensure(MenuWidget != nullptr))  return;

	MenuWidget->Setup();
	MenuWidget->SetMenuInterface(this);
}

void UMenuSystemGameInstance::HostServer()
{

	if (Menu != nullptr) 
	{ 
		Menu->NativeDestruct();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));
	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UMenuSystemGameInstance::JoinServer(const FString& Address)
{

	if (Menu != nullptr)
	{
		Menu->NativeDestruct();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	PlayerController->ClientTravel(*Address, ETravelType::TRAVEL_Absolute);
}

void UMenuSystemGameInstance::LoadMainMenu() 
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/MenuSystem/MenuLevel/MainMenuLevel", ETravelType::TRAVEL_Absolute);
}