#pragma once

#include "CoreMinimal.h"
#include "CombatPhase.generated.h" 

UENUM(BlueprintType)
enum class ECombatPhase : uint8
{
    OutOfCombat,
    TurnIdle,
    Ended,
};

