// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class MENU_SYSTEM_C_API UPauseMenu : public UMenuWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitPauseButton;

	UFUNCTION()
	void CancelPauseEvent();
	
	UFUNCTION()
	void QuitGameEvent();
};
