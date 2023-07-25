// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MENU_SYSTEM_C_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	void SetMenuInterface(IMenuInterface* SetupMenuInterface);

	void Setup();

	virtual void NativeDestruct();

protected:
	IMenuInterface* MenuInterface;

};
