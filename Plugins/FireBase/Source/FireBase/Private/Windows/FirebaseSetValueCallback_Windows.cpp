// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseSetValueCallback.h"
#include "FirebaseVariant.h"
#include "FirebaseDatabaseRef.h"

UFirebaseSetValueCallback::UFirebaseSetValueCallback()
{
	mbSetComplete = false;
}

void UFirebaseSetValueCallback::Tick(float DeltaTime)
{

}

bool UFirebaseSetValueCallback::IsTickable() const
{
	return false;
}

TStatId UFirebaseSetValueCallback::GetStatId() const
{
	return TStatId();
}

void UFirebaseSetValueCallback::Activate()
{

}

void UFirebaseSetValueCallback::CheckFinish()
{

}

UFirebaseSetValueCallback* UFirebaseSetValueCallback::SetValue(UFirebaseDatabaseRef* databaseRef, UFirebaseVariant* value)
{
	UFirebaseSetValueCallback* ret = NewObject<UFirebaseSetValueCallback>();
	
	return ret;
}
