#include "CombatEncounter.h"
#include "CombatComponent.h"
#include "RPSResolver.h"

ACombatEncounter::ACombatEncounter()
{
}

void ACombatEncounter::ChooseGesture(ERPSGesture Gesture) 
{
    ERPSGesture EnemyGesture = ERPSGesture::Guard;
	FRPSResolveResult Result;
    AActor* Attacker = nullptr;
    AActor* Defender = nullptr;
    if (IsHeroTurn)
    {
	    Attacker = TestHero;
	    Defender = TestEnemy;
    }
    else
    {
	    Attacker = TestEnemy;
	    Defender = TestHero;
    }

	if (IsHeroTurn)
	{
		Result = URPSResolver::Resolve(Gesture, EnemyGesture);
	}
	else
	{
		Result = URPSResolver::Resolve(EnemyGesture, Gesture);
	}

    if(Result.Outcome == ERPSOutcome::Hit)
    {
        UCombatComponent* AttackerCombat = Attacker->FindComponentByClass<UCombatComponent>();
        UCombatComponent* DefenderCombat = Defender->FindComponentByClass<UCombatComponent>();
        if (AttackerCombat && DefenderCombat)
        {
	        DefenderCombat->ApplyDamage(AttackerCombat->BaseDamage * Result.DamageMultiplier);
        }   
    }
    else if(Result.Outcome == ERPSOutcome::Clash)
    {
        UCombatComponent* AttackerCombat = Attacker->FindComponentByClass<UCombatComponent>();
        UCombatComponent* DefenderCombat = Defender->FindComponentByClass<UCombatComponent>();
        if (AttackerCombat && DefenderCombat)
        {
	        DefenderCombat->ApplyDamage(AttackerCombat->BaseDamage * Result.DamageMultiplier);
        }   
    }
    else
    {
        UCombatComponent* AttackerCombat = Attacker->FindComponentByClass<UCombatComponent>();
        UCombatComponent* DefenderCombat = Defender->FindComponentByClass<UCombatComponent>();
        if (AttackerCombat && DefenderCombat)
        {
	        AttackerCombat->ApplyDamage(DefenderCombat->BaseDamage * Result.DamageMultiplier);
        }   
    }
	
	IsHeroTurn = !IsHeroTurn;

}