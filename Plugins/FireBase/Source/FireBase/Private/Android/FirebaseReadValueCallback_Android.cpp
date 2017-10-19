// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseReadValueCallback.h"
#include "FirebaseDataSnapshot.h"


UFirebaseReadValueCallback::UFirebaseReadValueCallback()
{
	mGetValueComplete = false;
}

void UFirebaseReadValueCallback::Activate()
{
	CheckFutureState();
}

void UFirebaseReadValueCallback::CheckFutureState()
{
	if (mFutureData.status() == firebase::kFutureStatusPending)
	{
		return;
	}

	mGetValueComplete = true;

	if (mFutureData.status() != firebase::kFutureStatusComplete)
	{
		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), nullptr);
	}
	else if (mFutureData.error() != 0) 
	{
		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), nullptr);
	}
	else
	{
		UFirebaseDataSnapshot* pResult = NewObject<UFirebaseDataSnapshot>();
		pResult->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(*mFutureData.result() ) );

		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), pResult);
	}


	SetReadyToDestroy();
}

UFirebaseReadValueCallback* UFirebaseReadValueCallback::GetValue(UFirebaseQuery* query)
{
	if (query == nullptr || !query->IsValid() )
	{
		return nullptr;
	}

	UFirebaseReadValueCallback* pRet = NewObject<UFirebaseReadValueCallback>();
	pRet->mFutureData = query->GetQuery()->GetValue();

	return pRet;
}

void UFirebaseReadValueCallback::Tick(float DeltaTime)
{
	CheckFutureState();
}

bool UFirebaseReadValueCallback::IsTickable() const
{
	return !mGetValueComplete;
}

TStatId UFirebaseReadValueCallback::GetStatId() const
{
	return TStatId();
}
