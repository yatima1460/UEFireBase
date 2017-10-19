// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseGetUserInfo.h"


UFirebaseGetUserInfo::UFirebaseGetUserInfo() :SuccedDelegate(FFireBaseGetUserCompleteDelegate::CreateUObject(this, &ThisClass::OnSuccedComplete) ),
FailDelegate(FFireBaseUserNotLoginDelegate::CreateUObject(this, &ThisClass::OnFailComplete) )
{
	
}

void UFirebaseGetUserInfo::Activate()
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseGetUserCompleteDelegate_Handle();
		SuccedDelegateHandle = Module->AddFireBaseGetUserCompleteDelegate_Handle(SuccedDelegate);

		Module->ClearAllFireBaseUserNotLoginDelegate_Handle();
		FailDelegateHandle = Module->AddFireBaseUserNotLoginDelegate_Handle(FailDelegate);
	}

	UFireBaseBPLibrary::GetFirebaseUserInfo();
}

UFirebaseGetUserInfo* UFirebaseGetUserInfo::GetFirebaseUserInfo()
{
	UFirebaseGetUserInfo* ret = NewObject<UFirebaseGetUserInfo>();
	return ret;
}

void UFirebaseGetUserInfo::OnSuccedComplete(FFireBaseUser User)
{
	OnSuccess.Broadcast(User);
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseGetUserCompleteDelegate_Handle();
	}

	SetReadyToDestroy();
}

void UFirebaseGetUserInfo::OnFailComplete()
{
	OnFail.Broadcast();
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseUserNotLoginDelegate_Handle();
	}

	SetReadyToDestroy();
}

