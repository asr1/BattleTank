// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* AimingComponent = nullptr;

	// How close can the AI tank get (in cm?)
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 80 * 100;

private:
	virtual void BeginPlay() override;

	void Tick(float DeltaTime);

};
