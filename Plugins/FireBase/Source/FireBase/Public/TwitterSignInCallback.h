// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignInCallbackBase.h"
#include "TwitterSignInCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UTwitterSignInCallback : public USignInCallbackBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TwitterSignIn", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UTwitterSignInCallback* TwitterSignIn();

	virtual void Activete_imp() override;
	
	
};
