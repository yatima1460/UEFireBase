// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignOutCallbackBase.h"
#include "AnonymouslySignOutCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UAnonymouslySignOutCallback : public USignOutCallbackBase
{
	GENERATED_BODY()
	
	
public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AnonymouslySignOut", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UAnonymouslySignOutCallback* AnonymouslySignOut();

	virtual void Activete_imp() override;
	
};
