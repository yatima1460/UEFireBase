// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "AsyncWaitOperateFinish.h"
#include "FirebaseRemoveValueCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseRemoveValueCallback : public UAsyncWaitOperateFinish
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RemoveValue", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseRemoveValueCallback* RemoveValue(UFirebaseDatabaseRef* databaseRef);
};
