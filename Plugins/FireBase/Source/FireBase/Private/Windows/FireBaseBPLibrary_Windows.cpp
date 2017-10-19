// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FireBaseBPLibrary.h"
#include "FireBase.h"
#include "FirebaseDatabaseRef.h"



UFireBaseBPLibrary::UFireBaseBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


void UFireBaseBPLibrary::GoogleSign()
{
	UE_LOG(FireBase, Error, TEXT("GoogleSignIn Windows") );
}

void UFireBaseBPLibrary::GoogleSignOut()
{
	UE_LOG(FireBase, Error, TEXT("GoogleSignOut Windows"));
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->FireBaseSignOutCompleteDelegates.Broadcast();
	}
}

void UFireBaseBPLibrary::FacebookSignIn()
{
	UE_LOG(FireBase, Error, TEXT("FacebookSignIn Windows"));
}

void UFireBaseBPLibrary::FacebookSignOut()
{
	UE_LOG(FireBase, Error, TEXT("FacebookSignOut Windows"));
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->FireBaseSignOutCompleteDelegates.Broadcast();
	}
}

void UFireBaseBPLibrary::TwitterSignIn()
{

}

void UFireBaseBPLibrary::TwitterSignOut()
{

}

void UFireBaseBPLibrary::AnonymouslySignIn()
{

}

void UFireBaseBPLibrary::AnonymouslySignOut()
{

}

void UFireBaseBPLibrary::GetFirebaseUserInfo()
{

}

void UFireBaseBPLibrary::FireBaseInitialize()
{
	UFirebaseDatabaseRef* pRef = NewObject<UFirebaseDatabaseRef>();
	pRef = nullptr;
}

bool UFireBaseBPLibrary::isFirebaseUserLogin()
{
	return false;
}

void UFireBaseBPLibrary::FirebaseSignout()
{

}



