// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseDataSnapshot.h"

UFirebaseDataSnapshot::UFirebaseDataSnapshot()
{

}

UFirebaseDataSnapshot* UFirebaseDataSnapshot::Child(const FString& path)
{
	UFirebaseDataSnapshot* ret = NewObject<UFirebaseDataSnapshot>();

	return ret;
}

TArray<UFirebaseDataSnapshot*> UFirebaseDataSnapshot::Children()
{
	TArray<UFirebaseDataSnapshot*> ret;
	
	return ret;
}

int UFirebaseDataSnapshot::ChildrenCount()
{
	return 0;
}

bool UFirebaseDataSnapshot::HasChildren()
{
	return false;
}

FString UFirebaseDataSnapshot::GetKey()
{
	return TEXT("");
}

UFirebaseVariant* UFirebaseDataSnapshot::GetValue()
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();

	return ret;
}

bool UFirebaseDataSnapshot::HasChild(const FString& path)
{
	return false;
}

bool UFirebaseDataSnapshot::IsValid()
{
	return false;
}

