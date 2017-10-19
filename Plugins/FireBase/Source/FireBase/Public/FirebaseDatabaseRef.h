// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FirebaseDataSnapshot.h"
#include "FirebaseQuery.h"
#include "FirebaseDatabaseRef.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FIREBASE_API UFirebaseDatabaseRef : public UFirebaseQuery
{
	GENERATED_BODY()
	
public:

	UFirebaseDatabaseRef();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	static UFirebaseDatabaseRef* GetRootDatabaseRef();
	
	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseDatabaseRef* Child(const FString child);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	UFirebaseDatabaseRef* PushChild();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool IsValid() override;

	UFUNCTION(BlueprintPure, Category = "FireBase")
	FString Key();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool IsRoot();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseDatabaseRef* GetParent();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseDatabaseRef* GetRoot();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void GoOnline();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void GoOffline();

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	FString GetUrl();
	
	firebase::database::Query* GetQuery() override;

	TSharedPtr<firebase::database::DatabaseReference> mDatabaseRef;
};
