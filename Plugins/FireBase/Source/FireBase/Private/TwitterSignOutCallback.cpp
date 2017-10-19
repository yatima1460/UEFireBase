// Fill out your copyright notice in the Description page of Project Settings.

#include "TwitterSignOutCallback.h"


UTwitterSignOutCallback* UTwitterSignOutCallback::TwitterSignOut()
{
	UTwitterSignOutCallback* Proxy = NewObject<UTwitterSignOutCallback>();
	return Proxy;
}

void UTwitterSignOutCallback::Activete_imp()
{
	UFireBaseBPLibrary::TwitterSignOut();
}

