// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include"GameFramework/Controller.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:


	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
	
private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333333;
	float LineTraceRange = 1000000;
};
