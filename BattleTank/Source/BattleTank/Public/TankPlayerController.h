// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:

	///Start the tank moving the barrel so that a shot would
	///Hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	///Return an out parameter as well as true if it hits landscape, false if it hits sky
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocaiton = 1.f / 3.f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000; //10KM

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
