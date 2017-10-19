// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "FirebaseSetValueCallback.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFireBaseSetValueDelegate, int, errcode, const FString&, errmsg);

class UFirebaseDatabaseRef;
class UFirebaseVariant;
/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseSetValueCallback : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()
	
public:
	
	UFirebaseSetValueCallback();

	UPROPERTY(BlueprintAssignable)
	FFireBaseSetValueDelegate OnComplete;

	virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetValue", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseSetValueCallback* SetValue(UFirebaseDatabaseRef* databaseRef, UFirebaseVariant* value);

	void CheckFinish();

	firebase::Future<void> mFutureData;
	bool mbSetComplete;
};
