// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank * GetControlledTank() const;

private:

	///Start the tank moving the barrel so that a shot would
	///Hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	///Return an out parameter as well as true if it hits landscape, false if it hits sky
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = .5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocaiton = 1.f / 3.f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000; //10KM

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
