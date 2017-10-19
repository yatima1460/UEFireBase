// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FireBase.h"
#include "SignInCallbackBase.h"
#include "GoogleSignInCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UGoogleSignInCallback : public USignInCallbackBase
{
	GENERATED_BODY()
	
public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GoogleSignIn", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UGoogleSignInCallback* GoogleSignIn();

	virtual void Activete_imp() override;	
};
