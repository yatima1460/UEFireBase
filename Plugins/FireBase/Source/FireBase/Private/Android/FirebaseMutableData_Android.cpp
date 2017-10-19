// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseMutableData.h"

UFirebaseMutableData::UFirebaseMutableData()
{
}

UFirebaseMutableData* UFirebaseMutableData::Child(const FString& path)
{
	if (!mMutableData.IsValid() )
	{
		return nullptr;
	}

	std::string strPath = TCHAR_TO_UTF8(*path);
	firebase::database::MutableData result = mMutableData->Child(strPath);

	UFirebaseMutableData* ret = NewObject<UFirebaseMutableData>();
	ret->mMutableData = TSharedPtr<firebase::database::MutableData>(new firebase::database::MutableData(result) );

	return ret;
}

TArray<UFirebaseMutableData*> UFirebaseMutableData::children()
{
	if (!mMutableData.IsValid())
	{
		return TArray<UFirebaseMutableData*>();
	}

	auto childList = mMutableData->children();

	TArray<UFirebaseMutableData*> ret;
	for (size_t i = 0; i < childList.size(); i++)
	{
		UFirebaseMutableData* tmp = NewObject<UFirebaseMutableData>();
		tmp->mMutableData = TSharedPtr<firebase::database::MutableData>(new firebase::database::MutableData(childList[i]));
		ret.Add(tmp);
	}

	return ret;
}

int UFirebaseMutableData::children_count()
{
	if (!mMutableData.IsValid())
	{
		return 0;
	}

	return (int)mMutableData->children_count();
}

FString UFirebaseMutableData::key()
{
	if (!mMutableData.IsValid())
	{
		return TEXT("");
	}

	std::string strKey = mMutableData->key_string();
	
	return FString(UTF8_TO_TCHAR(strKey.c_str() ) );
}

UFirebaseVariant* makeFirebaseVariant(firebase::Variant v);

UFirebaseVariant* UFirebaseMutableData::value()
{
	if (!mMutableData.IsValid())
	{
		return nullptr;
	}

	auto result = mMutableData->value();
	UFirebaseVariant* ret = makeFirebaseVariant(result);

	return ret;
}

bool UFirebaseMutableData::HasChild(const FString& path)
{
	if (!mMutableData.IsValid())
	{
		return false;
	}

	std::string strPath = TCHAR_TO_UTF8(*path);
	bool ret = mMutableData->HasChild(strPath);

	return ret;
}

firebase::Variant makeVariant(UFirebaseVariant* value);

void UFirebaseMutableData::set_value(UFirebaseVariant* value)
{
	if (!mMutableData.IsValid() || !value)
	{
		return;
	}

	auto result = makeVariant(value);
	mMutableData->set_value(result);
}

void UFirebaseMutableData::set_priority(UFirebaseVariant* value)
{
	if (!mMutableData.IsValid() || !value)
	{
		return;
	}

	auto result = makeVariant(value);
	mMutableData->set_priority(value);
}

UFirebaseVariant* UFirebaseMutableData::priority()
{
	if (!mMutableData.IsValid() )
	{
		return nullptr;
	}

	auto result = mMutableData->priority();
	UFirebaseVariant* ret = makeFirebaseVariant(result);

	return ret;
}


