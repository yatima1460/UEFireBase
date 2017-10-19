// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncWaitOperateFinish.h"
#include "FirebaseUpdateChildrenCallback.generated.h"

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseUpdateChildrenCallback : public UAsyncWaitOperateFinish
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UpdateChildren", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseUpdateChildrenCallback* UpdateChildren(UFirebaseDatabaseRef* databaseRef, const TMap<FString, UFirebaseVariant*>& value);
};
