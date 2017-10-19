// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseUpdateChildrenCallback.h"
#include "FirebaseDatabaseRef.h"

extern firebase::Variant makeVariant(UFirebaseVariant* value);

UFirebaseUpdateChildrenCallback* UFirebaseUpdateChildrenCallback::UpdateChildren(UFirebaseDatabaseRef* databaseRef, const TMap<FString, UFirebaseVariant*>& value)
{
	if (databaseRef == nullptr || (databaseRef->IsValid() == false))
	{
		return nullptr;
	}

	UFirebaseUpdateChildrenCallback* ret = NewObject<UFirebaseUpdateChildrenCallback>();

	std::map<std::string, firebase::Variant> valuesToUpdate;
	for (auto it = value.CreateConstIterator(); it; ++it)
	{
		std::string strValue = TCHAR_TO_UTF8(*(it->Key));

		firebase::Variant tmpvalue = makeVariant(it->Value);
		valuesToUpdate[strValue] = tmpvalue;
	}

	ret->mFutureData = databaseRef->mDatabaseRef->UpdateChildren(valuesToUpdate);

	return ret;
}
