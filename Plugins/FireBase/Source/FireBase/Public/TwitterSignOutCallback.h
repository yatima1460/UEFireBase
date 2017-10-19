// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignOutCallbackBase.h"
#include "TwitterSignOutCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UTwitterSignOutCallback : public USignOutCallbackBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TwitterSignOut", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UTwitterSignOutCallback* TwitterSignOut();

	virtual void Activete_imp() override;
	
	
};
