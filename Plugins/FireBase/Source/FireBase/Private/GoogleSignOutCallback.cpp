// Fill out your copyright notice in the Description page of Project Settings.

#include "GoogleSignOutCallback.h"




UGoogleSignOutCallback* UGoogleSignOutCallback::GoogleSignOut()
{
	UGoogleSignOutCallback* Proxy = NewObject<UGoogleSignOutCallback>();
	return Proxy;
}

void UGoogleSignOutCallback::Activete_imp()
{
	UFireBaseBPLibrary::GoogleSignOut();
}




