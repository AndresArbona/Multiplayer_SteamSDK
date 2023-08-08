// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Menu_System_C : ModuleRules
{
	public Menu_System_C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "OnlineSubsystem" });
	}
}
