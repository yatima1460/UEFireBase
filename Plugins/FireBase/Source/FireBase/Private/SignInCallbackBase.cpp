// Fill out your copyright notice in the Description page of Project Settings.

#include "SignInCallbackBase.h"

USignInCallbackBase::USignInCallbackBase() :
	SuccedDelegate(FFireBaseSignSuccedCompleteDelegate::CreateUObject(this, &ThisClass::OnSuccedComplete))
{

}


void USignInCallbackBase::Activate()
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseSignSuccedCompleteDelegate_Handle();
		SuccedDelegateHandle = Module->AddFireBaseSignSuccedCompleteDelegate_Handle(SuccedDelegate);
		Activete_imp();
	}
}

void USignInCallbackBase::Activete_imp()
{

}

void USignInCallbackBase::PostSuccedComplete(FFireBaseUser User)
{

}

void USignInCallbackBase::OnSuccedComplete(FFireBaseUser User)
{
	PostSuccedComplete(User);
	OnSuccess.Broadcast(User);
	
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->ClearAllFireBaseSignSuccedCompleteDelegate_Handle();
	}

	SetReadyToDestroy();
}




