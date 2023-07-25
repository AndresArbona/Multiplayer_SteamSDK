// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MENU_SYSTEM_C_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()



protected:

	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostServerButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinServerButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta  = (BindWidget))
	class UWidgetSwitcher* MenuSwitch;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressField;


	UFUNCTION()
	void HostServerEvent();
	
	UFUNCTION()
	void JoinServerEvent();

	UFUNCTION()
	void JoinMenuEvent();

	UFUNCTION()
	void MainMenuEvent();

	UFUNCTION()
	void QuitPressedEvent();

};
