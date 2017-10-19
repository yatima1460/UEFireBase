// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncWaitOperateFinish.h"


UAsyncWaitOperateFinish::UAsyncWaitOperateFinish()
{
	mbSetComplete = false;
}

void UAsyncWaitOperateFinish::Tick(float DeltaTime)
{
	CheckFinish();
}

bool UAsyncWaitOperateFinish::IsTickable() const
{
	return !mbSetComplete;
}

TStatId UAsyncWaitOperateFinish::GetStatId() const
{
	return TStatId();
}

void UAsyncWaitOperateFinish::Activate()
{
	CheckFinish();
}


void UAsyncWaitOperateFinish::CheckFinish()
{
	if (mFutureData.status() == firebase::kFutureStatusPending)
	{
		return;
	}

	mbSetComplete = true;

	OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())));

	SetReadyToDestroy();
}

