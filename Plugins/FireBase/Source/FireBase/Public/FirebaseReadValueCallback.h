// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "FirebaseReadValueCallback.generated.h"


class UFirebaseQuery;
class UFirebaseDatabaseRef;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFireBaseGetValueDelegate, int, errcode, const FString&, errmsg, UFirebaseDataSnapshot*, dataSnapshot);

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseReadValueCallback : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()
	
public:

	UFirebaseReadValueCallback();
	
	UPROPERTY(BlueprintAssignable)
	FFireBaseGetValueDelegate OnComplete;

	virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetValue", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseReadValueCallback* GetValue(UFirebaseQuery* query);

	void CheckFutureState();

	firebase::Future<firebase::database::DataSnapshot> mFutureData;
	bool mGetValueComplete;
};
