// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

//Relative speed is between -1 and 1, where 1 is max speed forward and -1 is max speed backwards
void UTankTurret::Rotate(float RelativeSpeed)
{
		RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

		//Move correct amount this frame
		auto YawChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
		auto Rotation = RelativeRotation.Yaw + YawChange;

		SetRelativeRotation(FRotator(0, Rotation, 0));
}

