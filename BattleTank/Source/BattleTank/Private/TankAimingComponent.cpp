// Copyright Alex Rinehart

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed)
{
	if (Barrel && Turret)
	{
		auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FVector OutLaunchVelocity;


		if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, TargetLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
		}
	}
}

void UTankAimingComponent::Initialize(UTankBarrel* Barrel, UTankTurret* Turret)
{
	if (!ensure(Barrel && Turret)) { return; }

	this->Barrel = Barrel;
	this->Turret = Turret;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel && Turret))  { return; }
	
	//Find difference between current rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

