// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FireBase.h"
#include "FireBaseBPLibrary.h"
#include "SignInCallbackBase.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API USignInCallbackBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	USignInCallbackBase();

	UPROPERTY(BlueprintAssignable)
	FFireBaseSignSuccessDelegate OnSuccess;
	
	virtual void Activate() override;
	virtual void Activete_imp();
	virtual void PostSuccedComplete(FFireBaseUser User);

private:

	FFireBaseSignSuccedCompleteDelegate SuccedDelegate;
	FDelegateHandle SuccedDelegateHandle;

	void OnSuccedComplete(FFireBaseUser User);
	
};
