#include "RPSResolver.h"

FRPSResolveResult URPSResolver::Resolve(ERPSGesture Attacker, ERPSGesture Defender)
{
	FRPSResolveResult Result;
	if (Attacker == Defender)
	{
		Result.Outcome = ERPSOutcome::Clash;
		Result.DamageMultiplier = 0.5f;
	}
	else if (
		(Attacker == ERPSGesture::Strike && Defender == ERPSGesture::Feint) ||
		(Attacker == ERPSGesture::Feint && Defender == ERPSGesture::Guard) ||
		(Attacker == ERPSGesture::Guard && Defender == ERPSGesture::Strike)
	)
	{
		Result.Outcome = ERPSOutcome::Hit;
		Result.DamageMultiplier = 1.0f;
	}
	else
	{
		Result.Outcome = ERPSOutcome::Counter;
		Result.DamageMultiplier = 1.0f;
	}
	return Result;
}