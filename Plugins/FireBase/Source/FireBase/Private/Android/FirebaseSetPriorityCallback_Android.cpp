// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseSetPriorityCallback.h"
#include "FirebaseDatabaseRef.h"

extern firebase::Variant makeVariant(UFirebaseVariant* value);

UFirebaseSetPriorityCallback* UFirebaseSetPriorityCallback::SetPriority(UFirebaseDatabaseRef* databaseRef, UFirebaseVariant* priority)
{
	if (databaseRef == nullptr || priority == nullptr || (databaseRef->IsValid() == false) )
	{
		return nullptr;
	}

	UFirebaseSetPriorityCallback* ret = NewObject<UFirebaseSetPriorityCallback>();
	ret->mFutureData = databaseRef->mDatabaseRef->SetPriority(makeVariant(priority) );

	return ret;
}
