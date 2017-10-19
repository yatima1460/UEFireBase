// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignInCallbackBase.h"
#include "AnonymouslySignInCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UAnonymouslySignInCallback : public USignInCallbackBase
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AnonymouslySignIn", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UAnonymouslySignInCallback* AnonymouslySignIn();

	virtual void Activete_imp() override;
	
};
