// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UABCharacterMovementComponent();

	void SetTeleportCommand();

public:
	uint8 bPressedTeleport : 1;
	uint8 bDidTeleport : 1;

protected:
	virtual void ABTeleport();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	float TeleportOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	float TeleportCoolTime;
};
