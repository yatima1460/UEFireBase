// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseRunTransactionCallback.h"


UFirebaseRunTransactionCallback::UFirebaseRunTransactionCallback()
{
	mGetValueComplete = false;
}

UFirebaseRunTransactionCallback* UFirebaseRunTransactionCallback::RunTransaction(UFirebaseDatabaseRef* databaseRef, FFireBaseTransactionDelegate OnTransaction)
{
	UFirebaseRunTransactionCallback* ret = NewObject<UFirebaseRunTransactionCallback>();

	return ret;
}


void UFirebaseRunTransactionCallback::Tick(float DeltaTime)
{

}

bool UFirebaseRunTransactionCallback::IsTickable() const
{
	return !mGetValueComplete;
}

TStatId UFirebaseRunTransactionCallback::GetStatId() const
{
	return TStatId();
}

void UFirebaseRunTransactionCallback::Activate()
{

}

void UFirebaseRunTransactionCallback::CheckFutureState()
{

}