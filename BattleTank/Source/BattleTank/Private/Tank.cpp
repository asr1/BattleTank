// Copyright Alex Rinehart

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // Blueprint is the parent, needed for that to run!

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector TargetLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(TargetLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) 
	{ 
		//Spawn a projectile at the barrel's socket location
		auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto StartRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, StartLocation, StartRotation);
		Projectile->LaunchProjectile(LaunchSpeed);
	
		LastFireTime = FPlatformTime::Seconds();
	}

}
