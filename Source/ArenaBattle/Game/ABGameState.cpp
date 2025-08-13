// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameState.h"
#include "ArenaBattle.h"

AABGameState::AABGameState()
{

}

void AABGameState::HandleBeginPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("Begin"));

	Super::HandleBeginPlay();

	AB_LOG(LogABNetwork, Log, TEXT("End"));
}

void AABGameState::OnRep_ReplicatedHasBegunPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("Begin"));

	Super::OnRep_ReplicatedHasBegunPlay();

	AB_LOG(LogABNetwork, Log, TEXT("End"));
}
