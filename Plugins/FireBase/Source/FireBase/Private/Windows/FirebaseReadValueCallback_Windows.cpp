// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseReadValueCallback.h"
#include "FirebaseDatabaseRef.h"


UFirebaseReadValueCallback::UFirebaseReadValueCallback()
{
	mGetValueComplete = false;
}

void UFirebaseReadValueCallback::Activate()
{
}

void UFirebaseReadValueCallback::Tick(float DeltaTime)
{

}

void UFirebaseReadValueCallback::CheckFutureState()
{

}

UFirebaseReadValueCallback* UFirebaseReadValueCallback::GetValue(UFirebaseQuery* databaseRef)
{
	UFirebaseReadValueCallback* pRet = NewObject<UFirebaseReadValueCallback>();
	
	return pRet;
}

bool UFirebaseReadValueCallback::IsTickable() const
{
	return !mGetValueComplete;
}

TStatId UFirebaseReadValueCallback::GetStatId() const
{
	return TStatId();
}
