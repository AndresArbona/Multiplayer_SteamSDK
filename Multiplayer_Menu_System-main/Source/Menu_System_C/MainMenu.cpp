// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"


bool UMainMenu::Initialize()
{
	bool Succes = Super::Initialize();
	if (!Succes) return false;
	
	if (!ensure(HostServerButton != nullptr)) return false;
	if (!ensure(JoinServerButton != nullptr)) return false;
	if (!ensure(MainMenuButton != nullptr)) return false;
	if (!ensure(JoinMenuButton != nullptr)) return false;
	if (!ensure(QuitButton != nullptr)) return false;

	
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitPressedEvent);
	HostServerButton->OnClicked.AddDynamic(this, &UMainMenu::HostServerEvent);
	JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServerEvent);
	JoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::JoinMenuEvent);
	MainMenuButton->OnClicked.AddDynamic(this, &UMainMenu::MainMenuEvent);

	return true;
}

void UMainMenu::HostServerEvent()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->HostServer();
	}
}

void UMainMenu::JoinServerEvent()
{
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressField != nullptr)) return;
		const FString& Address = IPAddressField->GetText().ToString();
		MenuInterface->JoinServer(Address);
	}
}

void UMainMenu::JoinMenuEvent()
{
	if (!ensure(MenuSwitch != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitch->SetActiveWidget(JoinMenu);
}

void UMainMenu::MainMenuEvent()
{
	if (!ensure(MenuSwitch != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitch->SetActiveWidget(MainMenu);
}

void UMainMenu::QuitPressedEvent()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}