// Fill out your copyright notice in the Description page of Project Settings.

#include "SignOutCallbackBase.h"


USignOutCallbackBase::USignOutCallbackBase() :
	SignoutDelegate(FFireBaseSignOutCompleteDelegate::CreateUObject(this, &ThisClass::OnSignoutComplete))
{

}

void USignOutCallbackBase::Activate()
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseSignOutCompleteDelegate_Handle();
		SignoutDelegateHandle = Module->AddFireBaseSignOutCompleteDelegate_Handle(SignoutDelegate);
		Activete_imp();
	}

}

void USignOutCallbackBase::Activete_imp()
{

}

void USignOutCallbackBase::OnSignoutComplete()
{
	OnSignOut.Broadcast();
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseSignOutCompleteDelegate_Handle();
	}

	SetReadyToDestroy();
}

