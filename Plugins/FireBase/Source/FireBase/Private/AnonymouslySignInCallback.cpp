// Fill out your copyright notice in the Description page of Project Settings.

#include "AnonymouslySignInCallback.h"


UAnonymouslySignInCallback* UAnonymouslySignInCallback::AnonymouslySignIn()
{
	UAnonymouslySignInCallback* proxy = NewObject<UAnonymouslySignInCallback>();

	return proxy;
}

void UAnonymouslySignInCallback::Activete_imp()
{
	UFireBaseBPLibrary::AnonymouslySignIn();
}

