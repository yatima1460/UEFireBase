// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseChildListenerCallback.h"
#include "FirebaseDatabaseRef.h"

class ChildListenerImp :public firebase::database::ChildListener
{
public:

	ChildListenerImp(UFirebaseChildListenerCallback* cb):mListernerCb(cb)
	{
	}

	void OnChildAdded(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key) override
	{
		mListernerCb->OnChildAdded(snapshot, previous_sibling_key);
	}

	void OnChildChanged(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key) override
	{
		mListernerCb->OnChildChanged(snapshot, previous_sibling_key);
	}

	void OnChildMoved(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key) override
	{
		mListernerCb->OnChildMoved(snapshot, previous_sibling_key);
	}

	void OnChildRemoved(const firebase::database::DataSnapshot& snapshot) override
	{
		mListernerCb->OnChildRemoved(snapshot);
	}

	void OnCancelled(const firebase::database::Error& error, const char* error_message) override
	{

	}

private:

	UFirebaseChildListenerCallback* mListernerCb;
};

UFirebaseChildListenerCallback::UFirebaseChildListenerCallback()
{
	mListenerImp = TSharedPtr<firebase::database::ChildListener>(new ChildListenerImp(this));
}

void UFirebaseChildListenerCallback::BeginDestroy()
{
	Super::BeginDestroy();

	if (mQuery != nullptr && mQuery->IsValid())
	{
		mQuery->GetQuery()->RemoveChildListener(mListenerImp.Get());
		mQuery = nullptr;
	}
}

void UFirebaseChildListenerCallback::Activate()
{

}

UFirebaseChildListenerCallback* UFirebaseChildListenerCallback::AddChildListener(UFirebaseQuery* query)
{
	if (query == nullptr || !query->IsValid())
	{
		return nullptr;
	}

	UFirebaseChildListenerCallback* ret = NewObject<UFirebaseChildListenerCallback>();
	ret->mQuery = query;
	ret->mQuery->GetQuery()->AddChildListener(ret->mListenerImp.Get());

	return ret;
}

void UFirebaseChildListenerCallback::RemoveChildListener()
{
	if (mQuery != nullptr && mQuery->IsValid())
	{
		mQuery->GetQuery()->RemoveChildListener(mListenerImp.Get());
		mQuery = nullptr;
	}

	SetReadyToDestroy();
}

void UFirebaseChildListenerCallback::OnChildAdded(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{
	UFirebaseDataSnapshot* pSnapshot = NewObject<UFirebaseDataSnapshot>();
	pSnapshot->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(snapshot));

	FString strPreviousSliblingKey = UTF8_TO_TCHAR(previous_sibling_key);
	OnChildAdd.Broadcast(this, pSnapshot, strPreviousSliblingKey);
}

void UFirebaseChildListenerCallback::OnChildChanged(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{
	UFirebaseDataSnapshot* pSnapshot = NewObject<UFirebaseDataSnapshot>();
	pSnapshot->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(snapshot));

	FString strPreviousSliblingKey = UTF8_TO_TCHAR(previous_sibling_key);
	OnChildChange.Broadcast(this, pSnapshot, strPreviousSliblingKey);
}

void UFirebaseChildListenerCallback::OnChildMoved(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key)
{
	UFirebaseDataSnapshot* pSnapshot = NewObject<UFirebaseDataSnapshot>();
	pSnapshot->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(snapshot));

	FString strPreviousSliblingKey = UTF8_TO_TCHAR(previous_sibling_key);
	OnChildMove.Broadcast(this, pSnapshot, strPreviousSliblingKey);
}

void UFirebaseChildListenerCallback::OnChildRemoved(const firebase::database::DataSnapshot& snapshot)
{
	UFirebaseDataSnapshot* pSnapshot = NewObject<UFirebaseDataSnapshot>();
	pSnapshot->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(snapshot));

	OnChildRemove.Broadcast(this, pSnapshot);
}


