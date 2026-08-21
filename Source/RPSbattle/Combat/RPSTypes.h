#pragma once

#include "CoreMinimal.h"
#include "RPSTypes.generated.h"

UENUM(BlueprintType) 
enum class ERPSGesture : uint8
{
    Strike,
    Guard,
    Feint
};

UENUM(BlueprintType)
enum class ERPSOutcome : uint8
{
    Hit,
    Clash,
    Counter
};

USTRUCT(BlueprintType)
struct FRPSResolveResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    ERPSOutcome Outcome = ERPSOutcome::Clash;

    UPROPERTY(BlueprintReadOnly)
    float DamageMultiplier = 0.5f;
};