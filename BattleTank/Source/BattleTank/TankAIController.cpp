// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Not found"), *ControlledTank->GetName());
	}
	
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank NOT Found"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
}
