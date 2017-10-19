// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FireBase.h"
#include "FirebaseGetUserInfo.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFireBaseGetUserSucced, FFireBaseUser, userInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFireBaseUserFail);

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseGetUserInfo : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	UFirebaseGetUserInfo();

	UPROPERTY(BlueprintAssignable)
	FFireBaseGetUserSucced OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FFireBaseUserFail OnFail;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFirebaseUserInfo", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseGetUserInfo* GetFirebaseUserInfo();

private:

	FFireBaseGetUserCompleteDelegate SuccedDelegate;
	FDelegateHandle SuccedDelegateHandle;

	FFireBaseUserNotLoginDelegate FailDelegate;
	FDelegateHandle FailDelegateHandle;
	
	void OnSuccedComplete(FFireBaseUser User);
	void OnFailComplete();
};
