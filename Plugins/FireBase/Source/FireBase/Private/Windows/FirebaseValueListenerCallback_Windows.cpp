// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseValueListenerCallback.h"
#include "FirebaseDatabaseRef.h"
#include "FirebaseDataSnapshot.h"

UFirebaseValueListenerCallback::UFirebaseValueListenerCallback()
{
}


void UFirebaseValueListenerCallback::Activate()
{

}

void UFirebaseValueListenerCallback::OnValueChanged(const firebase::database::DataSnapshot& snapshot)
{
	
}

void UFirebaseValueListenerCallback::OnCancelled(const firebase::database::Error& error_code, const char* error_message)
{
	
}

UFirebaseValueListenerCallback* UFirebaseValueListenerCallback::AddValueListener(UFirebaseQuery* query)
{
	return nullptr;
	//return NewObject<UFirebaseValueListenerCallback>();
}

void UFirebaseValueListenerCallback::BeginDestroy()
{
	Super::BeginDestroy();
}

void UFirebaseValueListenerCallback::RemoveValueListener()
{
}

