// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterMovementComponent.h"
#include "ArenaBattle.h"
#include "GameFramework/Character.h"

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
	if (CharacterOwner)
	{
		AB_SUBLOG(LogABTeleport, Log, TEXT("Teleport Begin"));

		FVector TargetLocation = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorForwardVector() * TeleportOffset;
		CharacterOwner->TeleportTo(TargetLocation, CharacterOwner->GetActorRotation(), false, true);
		bDidTeleport = true;

		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
		{
			bDidTeleport = true;
			AB_SUBLOG(LogABTeleport, Log, TEXT("Teleport End"));
		}), TeleportCoolTime, false, -1.0f);
	}
}
