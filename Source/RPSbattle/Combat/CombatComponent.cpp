#include "CombatComponent.h"

UCombatComponent::UCombatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCombatComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHP = MaxHP;
}

void UCombatComponent::ApplyDamage(float Amount)
{
    CurrentHP = FMath::Max(0.f, CurrentHP - Amount);
}

bool UCombatComponent::IsDead() const
{
    return CurrentHP <= 0.f;
}