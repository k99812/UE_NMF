// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterMovementComponent.h"

UABCharacterMovementComponent::UABCharacterMovementComponent()
{
	TeleportOffset = 600.0f;
	TeleportCoolTime = 3.0f;
}

void UABCharacterMovementComponent::SetTeleportCommand()
{
	bPressedTeleport = true;
}

void UABCharacterMovementComponent::ABTeleport()
{
}
