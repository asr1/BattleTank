// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed)
{
	if (Barrel)
	{
		auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FVector OutLaunchVelocity;


		if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, TargetLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			auto TankName = GetOwner()->GetName();
			UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *TankName, *(AimDirection.ToString()))
		}


	}
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

