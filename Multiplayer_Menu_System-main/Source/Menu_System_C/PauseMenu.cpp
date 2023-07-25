// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "Components/Button.h"

bool UPauseMenu::Initialize()
{
	bool Succes = Super::Initialize();
	if (!Succes) return false;
	
	//if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UPauseMenu::CancelPauseEvent);
	
	//if (!ensure(QuitPauseButton != nullptr)) return false;
	QuitPauseButton->OnClicked.AddDynamic(this, &UPauseMenu::QuitGameEvent);


	return true;
}

void UPauseMenu::CancelPauseEvent() 
{
	NativeDestruct();
}

void UPauseMenu::QuitGameEvent()
{
	if (MenuInterface != nullptr)
	{
		NativeDestruct();
		MenuInterface->LoadMainMenu();
	}
}