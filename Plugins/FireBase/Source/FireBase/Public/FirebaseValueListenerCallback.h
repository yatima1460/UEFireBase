// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "FirebaseReadValueCallback.h"
#include "FirebaseValueListenerCallback.generated.h"

class UFirebaseDatabaseRef;
class UFirebaseQuery;
class UFirebaseValueListenerCallback;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FFireBaseValueListenerDelegate, UFirebaseValueListenerCallback*, thiz,   int, errcode, const FString&, errmsg, UFirebaseDataSnapshot*, dataSnapshot);

/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseValueListenerCallback : public UBlueprintAsyncActionBase 
{
	GENERATED_BODY()
	
public:

	UFirebaseValueListenerCallback();

	UPROPERTY(BlueprintAssignable)
	FFireBaseValueListenerDelegate OnChange;

	virtual void BeginDestroy() override;

	void OnValueChanged(const firebase::database::DataSnapshot& snapshot);
	void OnCancelled(const firebase::database::Error& error_code, const char* error_message);

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddValueListener", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseValueListenerCallback* AddValueListener (UFirebaseQuery* query);
	
	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void RemoveValueListener();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	UFirebaseQuery* mQuery;
	
	TSharedPtr<firebase::database::ValueListener> mListenerImp;
};
