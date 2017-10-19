// Fill out your copyright notice in the Description page of Project Settings.

#include "FaceBookSignOutCallback.h"



UFaceBookSignOutCallback* UFaceBookSignOutCallback::FaceBookSignOut()
{
	UFaceBookSignOutCallback* Proxy = NewObject<UFaceBookSignOutCallback>();
	return Proxy;
}

void UFaceBookSignOutCallback::Activete_imp()
{
	UFireBaseBPLibrary::FacebookSignOut();
}
