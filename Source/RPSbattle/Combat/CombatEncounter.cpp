#include "CombatEncounter.h"
#include "CombatComponent.h"
#include "RPSResolver.h"
#include "GameFramework/PlayerController.h"

ACombatEncounter::ACombatEncounter()
{
}

void ACombatEncounter::BeginPlay()
{
	Super::BeginPlay();

	if (TestHero == nullptr)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			TestHero = PC->GetPawn();
		}
	}
}

void ACombatEncounter::ChooseGesture(ERPSGesture Gesture)
{
	if (Phase == ECombatPhase::Ended) return;
	if (TestHero == nullptr)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			TestHero = PC->GetPawn();
		}
	}

	if (TestHero == nullptr || TestEnemy == nullptr)
	{
		return;
	}

	ERPSGesture EnemyGesture = ERPSGesture::Guard;
	FRPSResolveResult Result;
	AActor* Attacker = nullptr;
	AActor* Defender = nullptr;
	if (IsHeroTurn)
	{
		Attacker = TestHero;
		Defender = TestEnemy;
		Result = URPSResolver::Resolve(Gesture, EnemyGesture);
	}
	else
	{
		Attacker = TestEnemy;
		Defender = TestHero;
		Result = URPSResolver::Resolve(EnemyGesture, Gesture);
	}

	UCombatComponent* AttackerCombat = Attacker->FindComponentByClass<UCombatComponent>();
	UCombatComponent* DefenderCombat = Defender->FindComponentByClass<UCombatComponent>();
	if (!AttackerCombat || !DefenderCombat)
	{
		return;
	}

	if (Result.Outcome == ERPSOutcome::Hit || Result.Outcome == ERPSOutcome::Clash)
	{
		DefenderCombat->ApplyDamage(AttackerCombat->BaseDamage * Result.DamageMultiplier);
	}
	else
	{
		AttackerCombat->ApplyDamage(DefenderCombat->BaseDamage * Result.DamageMultiplier);
	}
	if (AttackerCombat->IsDead() || DefenderCombat->IsDead()) 
	{
		Phase = ECombatPhase::Ended;
	}else
	{
		IsHeroTurn = !IsHeroTurn;
	}
}
