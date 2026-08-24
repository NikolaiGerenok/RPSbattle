#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPSTypes.h"
#include "CombatEncounter.generated.h"

UCLASS()
class ACombatEncounter : public AActor 
{
    GENERATED_BODY()

    public:
    ACombatEncounter();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    AActor* TestEnemy;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    AActor* TestHero;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    bool IsHeroTurn = true;

    UFUNCTION(BlueprintCallable,Category = "Combat")
    void ChooseGesture(ERPSGesture Gesture);
    };