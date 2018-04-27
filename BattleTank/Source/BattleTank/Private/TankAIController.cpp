// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto  PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}

}

void ATankAIController::BeginPlay()
{
	//AI Tank controller should never be spawned without a tank
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Tank cannot find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank is %s"), *(PlayerTank->GetName()));
	}

}