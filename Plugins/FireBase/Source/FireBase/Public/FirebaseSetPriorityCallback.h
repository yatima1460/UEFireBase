// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "AsyncWaitOperateFinish.h"
#include "FirebaseSetPriorityCallback.generated.h"


/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseSetPriorityCallback : public UAsyncWaitOperateFinish
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetPriority", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseSetPriorityCallback* SetPriority(UFirebaseDatabaseRef* databaseRef, UFirebaseVariant* priority);

};
