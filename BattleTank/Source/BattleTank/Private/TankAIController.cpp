// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//AI Tank controller should never be spawned without a tank
		UE_LOG(LogTemp, Error, TEXT("AI Tank Controller spawned without a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI is controlling: %s"), *(ControlledTank->GetName()));
	 }
}