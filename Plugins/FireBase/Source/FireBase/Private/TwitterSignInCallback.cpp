// Fill out your copyright notice in the Description page of Project Settings.

#include "TwitterSignInCallback.h"




UTwitterSignInCallback* UTwitterSignInCallback::TwitterSignIn()
{
	UTwitterSignInCallback* Proxy = NewObject<UTwitterSignInCallback>();
	return Proxy;
}



void UTwitterSignInCallback::Activete_imp()
{
	UFireBaseBPLibrary::TwitterSignIn();
}