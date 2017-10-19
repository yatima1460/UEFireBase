// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseSetValueCallback.h"
#include "FirebaseVariant.h"
#include "FirebaseDatabaseRef.h"

UFirebaseSetValueCallback::UFirebaseSetValueCallback()
{
	mbSetComplete = false;
}

void UFirebaseSetValueCallback::Tick(float DeltaTime)
{
	CheckFinish();
}

bool UFirebaseSetValueCallback::IsTickable() const
{
	return !mbSetComplete;
}

TStatId UFirebaseSetValueCallback::GetStatId() const
{
	return TStatId();
}

void UFirebaseSetValueCallback::Activate()
{
	CheckFinish();
}

void UFirebaseSetValueCallback::CheckFinish()
{
	if (mFutureData.status() == firebase::kFutureStatusPending)
	{
		return;
	}

	mbSetComplete = true;

	OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())));

	SetReadyToDestroy();
}

firebase::Variant makeVariant(UFirebaseVariant* value)
{
	firebase::Variant setValue;

	if (value->DataType == VariantType::Int)
	{
		setValue = firebase::Variant(value->IntValue);
	}
	else if (value->DataType == VariantType::Bool)
	{
		setValue = firebase::Variant(value->BoolValue);
	}
	else if (value->DataType == VariantType::Float)
	{
		setValue = firebase::Variant(value->FloatValue);
	}
	else if (value->DataType == VariantType::String)
	{
		std::string strValue = TCHAR_TO_UTF8(*(value->StringValue));
		setValue = firebase::Variant(strValue);
	}
	else if (value->DataType == VariantType::Vector)
	{
		std::vector<firebase::Variant> valueList;
		for (int i = 0; i < value->VectorValue.Num(); i++)
		{
			valueList.push_back(makeVariant(value->VectorValue[i]));
		}
		setValue = firebase::Variant(valueList);
	}
	else if (value->DataType == VariantType::Map)
	{
		std::map<std::string, firebase::Variant> mapValue;
		for (auto it = value->MapValue.CreateConstIterator(); it; ++it)
		{
			std::string strValue = TCHAR_TO_UTF8(*(it->Key));

			firebase::Variant tmpvalue = makeVariant(it->Value);
			mapValue[strValue] = tmpvalue;
		}
		setValue = firebase::Variant(mapValue);
	}

	return setValue;
}

UFirebaseSetValueCallback* UFirebaseSetValueCallback::SetValue(UFirebaseDatabaseRef* databaseRef, UFirebaseVariant* value)
{
	if (value == nullptr)
	{
		return nullptr;
	}

	UFirebaseSetValueCallback* ret = NewObject<UFirebaseSetValueCallback>();
	ret->mFutureData = databaseRef->mDatabaseRef->SetValue(makeVariant(value) );

	return ret;
}
