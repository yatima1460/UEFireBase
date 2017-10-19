// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseVariant.h"


UFirebaseVariant::UFirebaseVariant()
{
	
}

UFirebaseVariant* UFirebaseVariant::CreateVariantInt(int value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::Int;
	ret->IntValue = value;

	return ret;
}

UFirebaseVariant* UFirebaseVariant::CreateVariantFloat(float value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::Float;
	ret->FloatValue = value;

	return ret;
}

UFirebaseVariant* UFirebaseVariant::CreateVariantBool(bool value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::Bool;
	ret->BoolValue = value;

	return ret;
}

UFirebaseVariant* UFirebaseVariant::CreateVariantString(const FString& value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::String;
	ret->StringValue = value;

	return ret;
}

UFirebaseVariant* UFirebaseVariant::CreateVariantVector(const TArray<UFirebaseVariant*>& value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::Vector;
	ret->VectorValue = value;

	return ret;
}

UFirebaseVariant* UFirebaseVariant::CreateVariantMap(const TMap<FString, UFirebaseVariant*>& value)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	ret->DataType = VariantType::Map;
	ret->MapValue = value;

	return ret;
}



