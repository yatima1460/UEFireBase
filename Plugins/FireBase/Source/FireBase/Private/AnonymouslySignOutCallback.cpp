// Fill out your copyright notice in the Description page of Project Settings.

#include "AnonymouslySignOutCallback.h"

UAnonymouslySignOutCallback* UAnonymouslySignOutCallback::AnonymouslySignOut()
{
	UAnonymouslySignOutCallback* proxy = NewObject<UAnonymouslySignOutCallback>();

	return proxy;
}

void UAnonymouslySignOutCallback::Activete_imp()
{
	UFireBaseBPLibrary::AnonymouslySignOut();
}


