// Fill out your copyright notice in the Description page of Project Settings.

#include "GoogleSignInCallback.h"

UGoogleSignInCallback* UGoogleSignInCallback::GoogleSignIn()
{
	UGoogleSignInCallback* Proxy = NewObject<UGoogleSignInCallback>();
	return Proxy;
}

void UGoogleSignInCallback::Activete_imp()
{
	UFireBaseBPLibrary::GoogleSign();
}
