// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SignOutCallbackBase.h"
#include "FaceBookSignOutCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UFaceBookSignOutCallback : public USignOutCallbackBase
{
	GENERATED_BODY()
	
public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FaceBookSignOut", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFaceBookSignOutCallback* FaceBookSignOut();

	virtual void Activete_imp() override;
	
};
