// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "AsyncWaitOperateFinish.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFireBaseFinishDelegate, int, errcode, const FString&, errmsg);

/**
 * 
 */
UCLASS()
class FIREBASE_API UAsyncWaitOperateFinish : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()
	
public:

	UAsyncWaitOperateFinish();

	UPROPERTY(BlueprintAssignable)
	FFireBaseFinishDelegate OnComplete;

	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;
	virtual void Activate() override;

	void CheckFinish();

	firebase::Future<void> mFutureData;
	bool mbSetComplete;
};