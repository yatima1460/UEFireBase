// Fill out your copyright notice in the Description page of Project Settings.

#include "FirebaseRunTransactionCallback.h"


UFirebaseRunTransactionCallback::UFirebaseRunTransactionCallback()
{
	mGetValueComplete = false;
}

UFirebaseRunTransactionCallback* UFirebaseRunTransactionCallback::RunTransaction(UFirebaseDatabaseRef* databaseRef, FFireBaseTransactionDelegate transation)
{
	UFirebaseRunTransactionCallback* ret = NewObject<UFirebaseRunTransactionCallback>();
	ret->OnTransaction = transation;
	ret->mDataBaseRef = databaseRef;
	ret->mFutureData = databaseRef->mDatabaseRef->RunTransaction(
		[](firebase::database::MutableData* data,void* ctx)
	{
		//size_t childCount = data->GetChildrenCount();
		//UE_LOG(FireBase, Error, TEXT("UFirebaseRunTransactionCallback*****************:childcnt:%d"), childCount);
		UFirebaseMutableData* pMetaData = NewObject<UFirebaseMutableData>();
		pMetaData->mMutableData = TSharedPtr<firebase::database::MutableData>(new firebase::database::MutableData(*data) );

		UFirebaseRunTransactionCallback* pCb = (UFirebaseRunTransactionCallback*)ctx;
		if (pCb->OnTransaction.IsBound())
		{
			TransactionResult result = TransactionResult::kTransactionResultAbort;
			pCb->OnTransaction.Execute(pMetaData, result);
			if (result == TransactionResult::kTransactionResultAbort)
			{
				return firebase::database::TransactionResult::kTransactionResultAbort;
			}
			else if (result == TransactionResult::kTransactionResultSuccess)
			{
				return firebase::database::TransactionResult::kTransactionResultSuccess;
			}
		}

		return firebase::database::TransactionResult::kTransactionResultAbort;
	}, ret);

	return ret;
}

void UFirebaseRunTransactionCallback::Activate()
{
	CheckFutureState();
}

void UFirebaseRunTransactionCallback::Tick(float DeltaTime)
{
	CheckFutureState();
}

bool UFirebaseRunTransactionCallback::IsTickable() const
{
	return !mGetValueComplete;
}

TStatId UFirebaseRunTransactionCallback::GetStatId() const
{
	return TStatId();
}

void UFirebaseRunTransactionCallback::CheckFutureState()
{
	if (mFutureData.status() == firebase::kFutureStatusPending)
	{
		return;
	}

	mGetValueComplete = true;

	if (mFutureData.status() != firebase::kFutureStatusComplete)
	{
		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), nullptr);
	}
	else if (mFutureData.error() != 0)
	{
		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), nullptr);
	}
	else
	{
		UFirebaseDataSnapshot* pResult = NewObject<UFirebaseDataSnapshot>();
		pResult->mDataSnapshot = TSharedPtr<firebase::database::DataSnapshot>(new firebase::database::DataSnapshot(*mFutureData.result()));

		OnComplete.Broadcast(mFutureData.error(), FString(UTF8_TO_TCHAR(mFutureData.error_message())), pResult);
	}


	SetReadyToDestroy();
}