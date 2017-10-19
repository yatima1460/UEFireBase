// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseRemoveValueCallback.h"
#include "FirebaseDatabaseRef.h"

UFirebaseRemoveValueCallback* UFirebaseRemoveValueCallback::RemoveValue(UFirebaseDatabaseRef* databaseRef)
{
	if (databaseRef == nullptr)
	{
		return nullptr;
	}

	UFirebaseRemoveValueCallback* ret = NewObject<UFirebaseRemoveValueCallback>();
	ret->mFutureData = databaseRef->mDatabaseRef->RemoveValue();

	return ret;
}


