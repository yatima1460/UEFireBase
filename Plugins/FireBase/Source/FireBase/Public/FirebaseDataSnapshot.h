// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "firebase/database.h"
#include "FirebaseDataSnapshot.generated.h"

class UFirebaseVariant;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FIREBASE_API UFirebaseDataSnapshot : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFirebaseDataSnapshot();
	
	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseDataSnapshot* Child(const FString& path);

	UFUNCTION(BlueprintPure, Category = "FireBase")
	TArray<UFirebaseDataSnapshot*> Children();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	int ChildrenCount();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool HasChildren();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	FString GetKey();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	UFirebaseVariant* GetValue();

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool HasChild(const FString& path);

	UFUNCTION(BlueprintPure, Category = "FireBase")
	bool IsValid();


	TSharedPtr<firebase::database::DataSnapshot> mDataSnapshot;
};
