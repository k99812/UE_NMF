// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterMovementComponent.h"
#include "ArenaBattle.h"
#include "GameFramework/Character.h"

UABCharacterMovementComponent::UABCharacterMovementComponent()
{
	TeleportOffset = 100.0f;
	TeleportCoolTime = 3.0f;

	bPressedTeleport = false;
	bDidTeleport = false;
}

void UABCharacterMovementComponent::SetTeleportCommand()
{
	bPressedTeleport = true;
}

void UABCharacterMovementComponent::ABTeleport()
{
	if (CharacterOwner)
	{
		AB_SUBLOG(LogABTeleport, Log, TEXT("%s"), TEXT("Teleport Begin"));

		FVector TargetLocation = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorForwardVector() * TeleportOffset;
		CharacterOwner->TeleportTo(TargetLocation, CharacterOwner->GetActorRotation(), false, true);
		bDidTeleport = true;

		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]
		{
			bDidTeleport = false;
			AB_SUBLOG(LogABTeleport, Log, TEXT("%s"), TEXT("Teleport End"));
		}), TeleportCoolTime, false, -1.0f);
	}
}

void UABCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	if (bPressedTeleport && !bDidTeleport)
	{
		ABTeleport();
	}

	if (bPressedTeleport)
	{
		bPressedTeleport = false;
	}
}
