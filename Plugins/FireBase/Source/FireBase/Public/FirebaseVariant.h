// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/NoExportTypes.h"

#include "Containers/Array.h"
#include "Containers/Map.h"
#include "FirebaseVariant.generated.h"


UENUM(BlueprintType)
enum class VariantType : uint8
{
	Null 	UMETA(DisplayName = "Null"),  
	Int 	UMETA(DisplayName = "Int"),
	Float 	UMETA(DisplayName = "Float"),	
	Bool 	UMETA(DisplayName = "Bool"),
	String 	UMETA(DisplayName = "String"),
	Vector 	UMETA(DisplayName = "Vector"),
	Map 	UMETA(DisplayName = "Map"),
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FIREBASE_API UFirebaseVariant : public UObject
{
	GENERATED_BODY()
	
public:

	UFirebaseVariant();
	
	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantInt(int value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantFloat(float value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantBool(bool value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantString(const FString& value);
	
	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantVector(const TArray<UFirebaseVariant*>& value);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	static UFirebaseVariant* CreateVariantMap(const TMap<FString, UFirebaseVariant*>& value);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	VariantType DataType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	int IntValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	float FloatValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	bool BoolValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	FString StringValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	TArray<UFirebaseVariant*> VectorValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	TMap<FString, UFirebaseVariant*> MapValue;
};
