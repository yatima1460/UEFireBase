// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseChildListenerCallback.h"

UFirebaseChildListenerCallback::UFirebaseChildListenerCallback()
{

}

void UFirebaseChildListenerCallback::BeginDestroy()
{
	Super::BeginDestroy();
}

void UFirebaseChildListenerCallback::Activate()
{

}

UFirebaseChildListenerCallback* UFirebaseChildListenerCallback::AddChildListener(UFirebaseQuery* query)
{
	return nullptr;
}

void UFirebaseChildListenerCallback::RemoveChildListener()
{
	
}

void UFirebaseChildListenerCallback::OnChildAdded(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{

}

void UFirebaseChildListenerCallback::OnChildChanged(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{

}

void UFirebaseChildListenerCallback::OnChildMoved(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{

}

void UFirebaseChildListenerCallback::OnChildRemoved(const firebase::database::DataSnapshot& snapshot)
{
	
}


