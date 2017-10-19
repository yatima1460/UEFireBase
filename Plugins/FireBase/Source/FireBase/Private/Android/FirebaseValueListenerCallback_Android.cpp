// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseValueListenerCallback.h"
#include "FirebaseDatabaseRef.h"


class ValueListenerImp :public firebase::database::ValueListener
{
public:

	ValueListenerImp(UFirebaseValueListenerCallback* cb) :mCb(cb)
	{
	}

	~ValueListenerImp() 
	{

	}

	void OnValueChanged(const firebase::database::DataSnapshot& snapshot) override
	{
		mCb->OnValueChanged(snapshot);
	}
	void OnCancelled(const firebase::database::Error& error_code, const char* error_message) override
	{
		mCb->OnCancelled(error_code, error_message);
	}

private:

	UFirebaseValueListenerCallback* mCb;
};

UFirebaseValueListenerCallback::UFirebaseValueListenerCallback()
{
	mListenerImp = TSharedPtr<firebase::database::ValueListener>(new ValueListenerImp(this) );
}


void UFirebaseValueListenerCallback::BeginDestroy()
{
	Super::BeginDestroy();

	if (mQuery != nullptr && mQuery->IsValid() )
	{
		mQuery->GetQuery()->RemoveValueListener(mListenerImp.Get());
		mQuery = nullptr;
	}
}

void UFirebaseValueListenerCallback::OnValueChanged(const firebase::database::DataSnapshot& snapshot)
{
	UFirebaseDataSnapshot* pSnapshot = NewObject<UFirebaseDataSnapshot>();
	pSnapshot->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(snapshot));

	OnChange.Broadcast(this, 0, TEXT(""), pSnapshot);
}

void UFirebaseValueListenerCallback::OnCancelled(const firebase::database::Error& error_code, const char* error_message)
{
	FString errorMsg;
	if (error_message != nullptr)
	{
		errorMsg = UTF8_TO_TCHAR(error_message);
	}

	OnChange.Broadcast(this, error_code, errorMsg, nullptr);
}

void UFirebaseValueListenerCallback::Activate()
{

}

UFirebaseValueListenerCallback* UFirebaseValueListenerCallback::AddValueListener(UFirebaseQuery* query)
{
	if (query == nullptr || !query->IsValid() )
	{
		return nullptr;
	}

	UFirebaseValueListenerCallback* ret = NewObject<UFirebaseValueListenerCallback>();
	ret->mQuery = query;
	ret->mQuery->GetQuery()->AddValueListener(ret->mListenerImp.Get());

	return ret;
}

void UFirebaseValueListenerCallback::RemoveValueListener()
{
	if (mQuery != nullptr && mQuery->IsValid() )
	{
		mQuery->GetQuery()->RemoveValueListener(mListenerImp.Get());
		mQuery = nullptr;
	}

	SetReadyToDestroy();
}



