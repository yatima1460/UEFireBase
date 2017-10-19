// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SignInCallbackBase.h"
#include "FaceBookSignInCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UFaceBookSignInCallback : public USignInCallbackBase
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FaceBookSignIn", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFaceBookSignInCallback* FaceBookSignIn();

	virtual void Activete_imp() override;
	
};
