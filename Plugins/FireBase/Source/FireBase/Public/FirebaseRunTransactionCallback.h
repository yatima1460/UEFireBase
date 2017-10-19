// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FirebaseMutableData.h"
#include "FirebaseReadValueCallback.h"
#include "FirebaseRunTransactionCallback.generated.h"


DECLARE_DYNAMIC_DELEGATE_TwoParams(FFireBaseTransactionDelegate, UFirebaseMutableData*, mutableData, TransactionResult&, result);

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseRunTransactionCallback : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()
	
public:

	UFirebaseRunTransactionCallback();

	UPROPERTY()
	FFireBaseTransactionDelegate OnTransaction;

	UPROPERTY(BlueprintAssignable)
	FFireBaseGetValueDelegate OnComplete;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RunTransaction", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseRunTransactionCallback* RunTransaction(UFirebaseDatabaseRef* databaseRef, FFireBaseTransactionDelegate transation);

	virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;

	virtual void Activate() override;

	void CheckFutureState();

private:

	firebase::Future<firebase::database::DataSnapshot> mFutureData;
	bool mGetValueComplete;

	UPROPERTY()
		UFirebaseDatabaseRef* mDataBaseRef;
};
