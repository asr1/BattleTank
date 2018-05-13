// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "AIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//TODO limit fire rate
		ControlledTank->Fire();
	}
}

void ATankAIController::BeginPlay()
{
	//AI Tank controller should never be spawned without a tank
	Super::BeginPlay();

}