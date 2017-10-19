// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FireBase.h"
#include "FireBaseBPLibrary.h"
#include "SignOutCallbackBase.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API USignOutCallbackBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	USignOutCallbackBase();

	UPROPERTY(BlueprintAssignable)
	FFireBaseSignOutDelegate OnSignOut;

	virtual void Activate() override;
	virtual void Activete_imp();

private:

	FFireBaseSignOutCompleteDelegate SignoutDelegate;
	FDelegateHandle SignoutDelegateHandle;

	void OnSignoutComplete();
	
	
};
