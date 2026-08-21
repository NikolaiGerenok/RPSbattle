// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPSbattle : ModuleRules
{
	public RPSbattle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"RPSbattle",
			"RPSbattle/Combat",
			"RPSbattle/Variant_Strategy",
			"RPSbattle/Variant_Strategy/UI",
			"RPSbattle/Variant_TwinStick",
			"RPSbattle/Variant_TwinStick/AI",
			"RPSbattle/Variant_TwinStick/Gameplay",
			"RPSbattle/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
