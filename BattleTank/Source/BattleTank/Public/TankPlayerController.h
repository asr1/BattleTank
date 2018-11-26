// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* AimingComponent = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	///Start the tank moving the barrel so that a shot would
	///Hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	///Return an out parameter as well as true if it hits landscape, false if it hits sky
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	virtual void SetPawn(APawn * InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = .5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocaiton = 1.f / 3.f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000; //10KM

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
