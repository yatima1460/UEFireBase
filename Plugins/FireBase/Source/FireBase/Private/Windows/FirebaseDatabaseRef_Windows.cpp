// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseDatabaseRef.h"
#include "FireBaseBPLibrary.h"

extern ::firebase::App* g_firebaseApp;

UFirebaseDatabaseRef::UFirebaseDatabaseRef()
{
}


UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetRootDatabaseRef()
{
	return nullptr;
}


UFirebaseDatabaseRef* UFirebaseDatabaseRef::Child(const FString child)
{
	return nullptr;
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::PushChild()
{
	return nullptr;
}

bool UFirebaseDatabaseRef::IsValid()
{
	return false;
}

FString UFirebaseDatabaseRef::Key()
{
	return TEXT("");
}

bool UFirebaseDatabaseRef::IsRoot()
{
	return false;
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetParent()
{
	return nullptr;
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetRoot()
{
	return nullptr;
}

void UFirebaseDatabaseRef::GoOnline()
{

}

void UFirebaseDatabaseRef::GoOffline()
{

}

FString UFirebaseDatabaseRef::GetUrl()
{
	return TEXT("");
}

firebase::database::Query* UFirebaseDatabaseRef::GetQuery()
{
	return mDatabaseRef.Get();
}

