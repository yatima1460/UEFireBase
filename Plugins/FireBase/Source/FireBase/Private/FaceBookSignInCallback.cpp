// Fill out your copyright notice in the Description page of Project Settings.

#include "FaceBookSignInCallback.h"


UFaceBookSignInCallback* UFaceBookSignInCallback::FaceBookSignIn()
{
	UFaceBookSignInCallback* Proxy = NewObject<UFaceBookSignInCallback>();
	
	return Proxy;
}

void UFaceBookSignInCallback::Activete_imp()
{
	UFireBaseBPLibrary::FacebookSignIn();
}



