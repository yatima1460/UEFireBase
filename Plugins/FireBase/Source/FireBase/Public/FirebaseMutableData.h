// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "firebase/database.h"
#include "FirebaseVariant.h"
#include "FirebaseMutableData.generated.h"


UENUM(BlueprintType)
enum class TransactionResult : uint8
{
	kTransactionResultSuccess 	UMETA(DisplayName = "kTransactionResultSuccess"),
	kTransactionResultAbort 	UMETA(DisplayName = "kTransactionResultAbort"),
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FIREBASE_API UFirebaseMutableData : public UObject
{
	GENERATED_BODY()
	
public:

	UFirebaseMutableData();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseMutableData* Child(const FString& path);

	UFUNCTION(BlueprintPure, Category = "FireBase")
	TArray<UFirebaseMutableData*> children();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	int children_count();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	FString key();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseVariant* value();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool HasChild(const FString& path);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void set_value(UFirebaseVariant* value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void set_priority(UFirebaseVariant* value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseVariant* priority();

	TSharedPtr<firebase::database::MutableData> mMutableData;
};
