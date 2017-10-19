// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseQuery.h"
#include "FirebaseDatabaseRef.h"


UFirebaseQuery::UFirebaseQuery()
{

}

UFirebaseDatabaseRef* UFirebaseQuery::GetReference()
{
	return nullptr;
}

void UFirebaseQuery::SetKeepSynchronized(bool keep_sync)
{

}

UFirebaseQuery* UFirebaseQuery::OrderByChild(const FString& child)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::OrderByKey()
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::OrderByPriority()
{
	return nullptr;
}


UFirebaseQuery* UFirebaseQuery::OrderByValue()
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::StartAt(UFirebaseVariant* orderValue)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::StartAtChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::EndAt(UFirebaseVariant* orderValue)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::EndAtChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::EqualTo(UFirebaseVariant* orderValue)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::EqualToChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::LimitToFirst(int limit)
{
	return nullptr;
}

UFirebaseQuery* UFirebaseQuery::LimitToLast(int limit)
{
	return nullptr;
}

bool UFirebaseQuery::IsValid()
{
	return false;
}

firebase::database::Query* UFirebaseQuery::GetQuery()
{
	return mQuery.Get();
}
