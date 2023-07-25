// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "MenuSystemGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MENU_SYSTEM_C_API UMenuSystemGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	


public:
	
	UMenuSystemGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void HostServer() override;

	UFUNCTION(Exec)
	void JoinServer(const FString& Address) override;




	UFUNCTION(BlueprintCallable)
	void LoadPauseMenu();

	UFUNCTION()
	void LoadMainMenu() override;

private:
	TSubclassOf<class UUserWidget>	MenuClass;

	class UMainMenu* Menu;
	
	TSubclassOf<class UUserWidget> PauseMenuClass;
};
