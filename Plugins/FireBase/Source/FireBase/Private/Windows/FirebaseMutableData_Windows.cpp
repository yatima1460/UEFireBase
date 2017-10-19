// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseMutableData.h"

UFirebaseMutableData::UFirebaseMutableData()
{

}

UFirebaseMutableData* UFirebaseMutableData::Child(const FString& path)
{
	return nullptr;
}

TArray<UFirebaseMutableData*> UFirebaseMutableData::children()
{
	return TArray<UFirebaseMutableData*>();
}

int UFirebaseMutableData::children_count()
{
	return 0;
}

FString UFirebaseMutableData::key()
{
	return TEXT("");
}

UFirebaseVariant* UFirebaseMutableData::value()
{
	return nullptr;
}

bool UFirebaseMutableData::HasChild(const FString& path)
{
	return true;
}

void UFirebaseMutableData::set_value(UFirebaseVariant* value)
{

}

void UFirebaseMutableData::set_priority(UFirebaseVariant* value)
{

}

UFirebaseVariant* UFirebaseMutableData::priority()
{
	return nullptr;
}


