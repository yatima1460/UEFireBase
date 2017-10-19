// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseDataSnapshot.h"
#include "FirebaseVariant.h"
#include "FireBase.h"

UFirebaseDataSnapshot::UFirebaseDataSnapshot()
{

}

UFirebaseDataSnapshot* UFirebaseDataSnapshot::Child(const FString& path)
{
	if (!mDataSnapshot.IsValid())
	{
		UE_LOG(FireBase, Error, TEXT("UFirebaseDataSnapshot:Child self is nullptr:%s"), *path);
		return nullptr;
	}

	auto child = mDataSnapshot->Child(TCHAR_TO_UTF8(*path) );
	
	UFirebaseDataSnapshot* ret = NewObject<UFirebaseDataSnapshot>();
	ret->mDataSnapshot = TSharedPtr<::firebase::database::DataSnapshot>(new ::firebase::database::DataSnapshot(child) );

	return ret;
}

TArray<UFirebaseDataSnapshot*> UFirebaseDataSnapshot::Children()
{
	TArray<UFirebaseDataSnapshot*> ret;
	if (!mDataSnapshot.IsValid())
	{
		UE_LOG(FireBase, Error, TEXT("UFirebaseDataSnapshot:Children self is nullptr") );
		return ret;
	}

	auto childList = mDataSnapshot->children();
	for (size_t i = 0; i < childList.size(); i++)
	{
		UFirebaseDataSnapshot* tmp = NewObject<UFirebaseDataSnapshot>();
		tmp->mDataSnapshot = TSharedPtr<::firebase::database::DataSnapshot>(new ::firebase::database::DataSnapshot(childList[i]));
		ret.Add(tmp);
	}

	return ret;
}

int UFirebaseDataSnapshot::ChildrenCount()
{
	if (!mDataSnapshot.IsValid())
	{
		return 0;
	}
	
	return mDataSnapshot->children_count();
}

bool UFirebaseDataSnapshot::HasChildren()
{
	if (!mDataSnapshot.IsValid())
	{
		return false;
	}

	return mDataSnapshot->has_children();
}

FString UFirebaseDataSnapshot::GetKey()
{
	if (!mDataSnapshot.IsValid())
	{
		return TEXT("");
	}

	if (mDataSnapshot->key() != nullptr)
	{
		return FString(UTF8_TO_TCHAR(mDataSnapshot->key() ) );
	}

	return TEXT("");
}

UFirebaseVariant* makeFirebaseVariant(firebase::Variant v)
{
	UFirebaseVariant* ret = NewObject<UFirebaseVariant>();
	if (v.type() == firebase::Variant::Type::kTypeInt64)
	{
		ret->DataType = VariantType::Int;
		ret->IntValue = (int)(v.int64_value());
	}
	else if (v.type() == firebase::Variant::Type::kTypeBool)
	{
		ret->DataType = VariantType::Int;
		ret->IntValue = v.bool_value();
	}
	else if (v.type() == firebase::Variant::Type::kTypeDouble)
	{
		ret->DataType = VariantType::Float;
		ret->FloatValue = (float)v.double_value();
	}
	else if (v.type() == firebase::Variant::Type::kTypeMutableString || v.type() == firebase::Variant::Type::kTypeStaticString)
	{
		ret->DataType = VariantType::String;
		ret->StringValue = UTF8_TO_TCHAR(v.string_value());
	}
	else if (v.type() == firebase::Variant::Type::kTypeVector)
	{
		ret->DataType = VariantType::Vector;
		const std::vector<firebase::Variant>& tmpList = v.vector();
		TArray<UFirebaseVariant*> valueList;
		for (size_t i = 0; i < tmpList.size(); i++)
		{
			valueList.Add(makeFirebaseVariant(tmpList[i]));
		}

		ret->DataType = VariantType::Vector;
		ret->VectorValue = valueList;
	}
	else if (v.type() == firebase::Variant::Type::kTypeMap)
	{
		ret->DataType = VariantType::Map;
		const std::map<firebase::Variant, firebase::Variant> tmpMap = v.map();
		TMap<FString, UFirebaseVariant*> valueMap;
		for (std::map<firebase::Variant, firebase::Variant>::const_iterator it = tmpMap.begin(); it != tmpMap.end(); it++)
		{
			firebase::Variant tmpKey = it->first;
			if (tmpKey.type() != firebase::Variant::Type::kTypeMutableString && tmpKey.type() != firebase::Variant::Type::kTypeStaticString)
			{
				continue;
			}

			FString strKey = UTF8_TO_TCHAR(tmpKey.string_value());
			valueMap.Add(strKey, makeFirebaseVariant(it->second) );
			//valueMap[strKey] = makeFirebaseVariant(it->second);
		}

		ret->MapValue = valueMap;
	}

	return ret;
}

UFirebaseVariant* UFirebaseDataSnapshot::GetValue()
{
	if (!mDataSnapshot.IsValid())
	{
		return nullptr;
	}

	auto result = mDataSnapshot->value();
	auto ret = makeFirebaseVariant(result);

	return ret;
}

bool UFirebaseDataSnapshot::HasChild(const FString& path)
{
	if (!mDataSnapshot.IsValid())
	{
		return false;
	}

	return mDataSnapshot->HasChild(TCHAR_TO_UTF8(*path) );
}

bool UFirebaseDataSnapshot::IsValid()
{
	if (!mDataSnapshot.IsValid())
	{
		return false;
	}

	return mDataSnapshot->is_valid();
}

