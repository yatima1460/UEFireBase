// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireBase.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SignOutCallbackBase.h"
#include "GoogleSignOutCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UGoogleSignOutCallback : public USignOutCallbackBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GoogleSignOut", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UGoogleSignOutCallback* GoogleSignOut();
	
	virtual void Activete_imp() override;
};
