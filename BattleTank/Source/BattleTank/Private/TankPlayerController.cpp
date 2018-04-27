// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing: %s"), *(ControlledTank->GetName()));
	}


	;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Line trace through the dot from the barrel
	OutHitLocation = FVector(1, 1, 1);
	return true;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector Hitlocation; //Out parameter

	if (GetSightRayHitLocation(Hitlocation)) //Will ray-trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *Hitlocation.ToString()); 
		//TODO tell controlled tank to aim at this point
	}

	//Get world location of linetrace through crosshar
		//if it hits landscape, 
			//Controlled tank should aim at that point

}
