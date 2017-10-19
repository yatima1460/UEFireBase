// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "firebase/database.h"
#include "FirebaseVariant.h"
#include "FirebaseQuery.generated.h"

class UFirebaseDatabaseRef;
class UFirebaseVariant;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FIREBASE_API UFirebaseQuery : public UObject
{
	GENERATED_BODY()
	
public:

	UFirebaseQuery();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseDatabaseRef* GetReference();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void SetKeepSynchronized(bool keep_sync);
	
	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* OrderByChild(const FString& child);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* OrderByKey();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* OrderByPriority();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* OrderByValue();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* StartAt(UFirebaseVariant* orderValue);
	
	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* StartAtChild(UFirebaseVariant* orderValue, const FString& childKey);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* EndAt(UFirebaseVariant* orderValue);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* EndAtChild(UFirebaseVariant* orderValue, const FString& childKey);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* EqualTo(UFirebaseVariant* orderValue);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* EqualToChild(UFirebaseVariant* orderValue, const FString& childKey);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* LimitToFirst(int limit);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseQuery* LimitToLast(int limit);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	virtual bool IsValid();

	virtual firebase::database::Query* GetQuery();

private:

	TSharedPtr<firebase::database::Query> mQuery;
};
