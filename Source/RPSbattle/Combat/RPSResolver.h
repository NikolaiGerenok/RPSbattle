#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RPSTypes.h"
#include "RPSResolver.generated.h"

UCLASS()
class URPSResolver : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()


public:
    UFUNCTION(BlueprintCallable, Category = "Combat|RPS")
    static FRPSResolveResult Resolve(ERPSGesture Attacker, ERPSGesture Defender);
};