// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseDatabaseRef.h"
#include "FireBaseBPLibrary.h"
#include "FirebaseVariant.h"

extern ::firebase::App* g_firebaseApp;

UFirebaseDatabaseRef::UFirebaseDatabaseRef()
{
}


UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetRootDatabaseRef()
{
	::firebase::database::Database *database = ::firebase::database::Database::GetInstance(g_firebaseApp);
	::firebase::database::DatabaseReference rootRef = database->GetReference();

	UFirebaseDatabaseRef* ret = NewObject<UFirebaseDatabaseRef>();
	ret->mDatabaseRef = MakeShareable(new ::firebase::database::DatabaseReference(rootRef) );

	return ret;
}


UFirebaseDatabaseRef* UFirebaseDatabaseRef::Child(const FString child)
{
	if (!mDatabaseRef.IsValid() )
	{
		UE_LOG(FireBase, Error, TEXT("UFirebaseDatabaseRef:Child self is nullptr:%s"), *child);
		return nullptr;
	}

	firebase::database::DatabaseReference childRef = mDatabaseRef->Child(TCHAR_TO_UTF8(*child));
	UFirebaseDatabaseRef* ret = NewObject<UFirebaseDatabaseRef>();
	ret->mDatabaseRef = MakeShareable(new ::firebase::database::DatabaseReference(childRef));

	return ret;
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::PushChild()
{
	if (!mDatabaseRef.IsValid())
	{
		UE_LOG(FireBase, Error, TEXT("UFirebaseDatabaseRef:PushChild self is nullptr") );
		return nullptr;
	}

	firebase::database::DatabaseReference childRef = mDatabaseRef->PushChild();

	UFirebaseDatabaseRef* ret = NewObject<UFirebaseDatabaseRef>();
	ret->mDatabaseRef = MakeShareable(new ::firebase::database::DatabaseReference(childRef));

	return ret;
}

bool UFirebaseDatabaseRef::IsValid()
{
	if (!mDatabaseRef.IsValid())
	{
		return false;
	}

	return mDatabaseRef->is_valid();
}

FString UFirebaseDatabaseRef::Key()
{
	if (!IsValid())
	{
		return TEXT("");
	}

	auto strKey = mDatabaseRef->key_string();
	FString retKey = UTF8_TO_TCHAR(strKey.c_str() );
	
	return retKey;
}

bool UFirebaseDatabaseRef::IsRoot()
{
	if (!IsValid())
	{
		return false;
	}

	return mDatabaseRef->is_root();
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetParent()
{
	if (!IsValid())
	{
		return nullptr;
	}

	UFirebaseDatabaseRef* ret = NewObject<UFirebaseDatabaseRef>();
	firebase::database::DatabaseReference parent = mDatabaseRef->GetParent();
	ret->mDatabaseRef = MakeShareable(new ::firebase::database::DatabaseReference(parent));

	return ret;
}

FString UFirebaseDatabaseRef::GetUrl()
{
	if (!IsValid())
	{
		return TEXT("");
	}

	std::string strUrl = mDatabaseRef->url();

	FString ret = UTF8_TO_TCHAR(strUrl.c_str() );

	return ret;
}

UFirebaseDatabaseRef* UFirebaseDatabaseRef::GetRoot()
{
	if (!IsValid())
	{
		return nullptr;
	}

	UFirebaseDatabaseRef* ret = NewObject<UFirebaseDatabaseRef>();
	firebase::database::DatabaseReference root = mDatabaseRef->GetRoot();
	ret->mDatabaseRef = MakeShareable(new ::firebase::database::DatabaseReference(root) );

	return ret;
}

void UFirebaseDatabaseRef::GoOnline()
{
	if (!IsValid())
	{
		return;
	}

	mDatabaseRef->GoOnline();
}

void UFirebaseDatabaseRef::GoOffline()
{
	if (!IsValid())
	{
		return;
	}

	mDatabaseRef->GoOffline();
}

firebase::database::Query* UFirebaseDatabaseRef::GetQuery()
{
	return mDatabaseRef.Get();
}




