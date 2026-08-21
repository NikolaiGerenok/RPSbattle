#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

UCLASS(ClassGroup = Combat, meta = (BlueprintSpawnableComponent))
class UCombatComponent : public UActorComponent
{
    GENERATED_BODY()

    public:
    UCombatComponent();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Combat")
    float MaxHP = 20.0f;

    UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Combat")
    float CurrentHP = 0.0f;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Combat")
    float BaseDamage = 5.0f;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void ApplyDamage(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Combat")
    bool IsDead() const;
};