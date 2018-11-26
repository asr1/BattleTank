// Copyright Alex Rinehart

#include "Tank.h"
#include "Engine/World.h"

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	float DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;
}
