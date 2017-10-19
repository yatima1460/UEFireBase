// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseQuery.h"
#include "FirebaseDatabaseRef.h"


UFirebaseQuery::UFirebaseQuery()
{

}

UFirebaseDatabaseRef* UFirebaseQuery::GetReference()
{
	if (!IsValid())
	{
		return nullptr;
	}

	auto dbRef = GetQuery()->GetReference();
	UFirebaseDatabaseRef* pRet = NewObject<UFirebaseDatabaseRef>();
	pRet->mDatabaseRef = TSharedPtr<firebase::database::DatabaseReference>(new firebase::database::DatabaseReference(dbRef) );

	return pRet;
}

void UFirebaseQuery::SetKeepSynchronized(bool keep_sync)
{
	if (!IsValid())
	{
		return;
	}

	GetQuery()->SetKeepSynchronized(keep_sync);
}

UFirebaseQuery* UFirebaseQuery::OrderByChild(const FString& child)
{
	if (!IsValid())
	{
		return nullptr;
	}

	std::string strChild = TCHAR_TO_UTF8(*child);
	firebase::database::Query retQuery = GetQuery()->OrderByChild(strChild);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery) );

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::OrderByKey()
{
	if (!IsValid())
	{
		return nullptr;
	}

	firebase::database::Query retQuery = GetQuery()->OrderByKey();

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::OrderByPriority()
{
	if (!IsValid())
	{
		return nullptr;
	}

	firebase::database::Query retQuery = GetQuery()->OrderByPriority();

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}


UFirebaseQuery* UFirebaseQuery::OrderByValue()
{
	if (!IsValid())
	{
		return nullptr;
	}

	firebase::database::Query retQuery = GetQuery()->OrderByValue();

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

extern firebase::Variant makeVariant(UFirebaseVariant* value);

UFirebaseQuery* UFirebaseQuery::StartAt(UFirebaseVariant* orderValue)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);
	firebase::database::Query retQuery = GetQuery()->StartAt(firebaseOrderValue);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::StartAtChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);
	std::string strChildKey = TCHAR_TO_UTF8(*childKey);

	firebase::database::Query retQuery = GetQuery()->StartAt(firebaseOrderValue, strChildKey.c_str() );

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::EndAt(UFirebaseVariant* orderValue)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);
	
	firebase::database::Query retQuery = GetQuery()->EndAt(firebaseOrderValue);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::EndAtChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);
	std::string strChildKey = TCHAR_TO_UTF8(*childKey);

	firebase::database::Query retQuery = GetQuery()->EndAt(firebaseOrderValue, strChildKey.c_str() );

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::EqualTo(UFirebaseVariant* orderValue)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);

	firebase::database::Query retQuery = GetQuery()->EqualTo(firebaseOrderValue);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::EqualToChild(UFirebaseVariant* orderValue, const FString& childKey)
{
	if (!IsValid() || !orderValue)
	{
		return nullptr;
	}

	firebase::Variant firebaseOrderValue = makeVariant(orderValue);
	std::string strChildKey = TCHAR_TO_UTF8(*childKey);

	firebase::database::Query retQuery = GetQuery()->EqualTo(firebaseOrderValue, strChildKey.c_str() );

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::LimitToFirst(int limit)
{
	if (!IsValid() )
	{
		return nullptr;
	}

	firebase::database::Query retQuery = GetQuery()->LimitToFirst(limit);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

UFirebaseQuery* UFirebaseQuery::LimitToLast(int limit)
{
	if (!IsValid())
	{
		return nullptr;
	}

	firebase::database::Query retQuery = GetQuery()->LimitToLast(limit);

	UFirebaseQuery* pRet = NewObject<UFirebaseQuery>();
	pRet->mQuery = TSharedPtr<firebase::database::Query>(new firebase::database::Query(retQuery));

	return pRet;
}

bool UFirebaseQuery::IsValid()
{
	if (!mQuery.IsValid())
	{
		return false;
	}

	return mQuery.Get()->is_valid();
}

firebase::database::Query* UFirebaseQuery::GetQuery()
{
	return mQuery.Get();
}
