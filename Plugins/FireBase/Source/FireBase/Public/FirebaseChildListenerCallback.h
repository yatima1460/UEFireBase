// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "firebase/database.h"
#include "FirebaseChildListenerCallback.generated.h"

class UFirebaseChildListenerCallback;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFireBaseChildAddListenerDelegate, UFirebaseChildListenerCallback*, thiz, UFirebaseDataSnapshot*, dataSnapshot, const FString&, preSiblingKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFireBaseChildChangeListenerDelegate, UFirebaseChildListenerCallback*, thiz, UFirebaseDataSnapshot*, dataSnapshot, const FString&, preSiblingKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFireBaseChildMoveListenerDelegate, UFirebaseChildListenerCallback*, thiz, UFirebaseDataSnapshot*, dataSnapshot, const FString&, preSiblingKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFireBaseChildRemoveListenerDelegate, UFirebaseChildListenerCallback*, thiz, UFirebaseDataSnapshot*, dataSnapshot);


class UFirebaseQuery;
/**
 * 
 */
UCLASS()
class FIREBASE_API UFirebaseChildListenerCallback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	UFirebaseChildListenerCallback();

	UPROPERTY(BlueprintAssignable)
	FFireBaseChildAddListenerDelegate OnChildAdd;

	UPROPERTY(BlueprintAssignable)
	FFireBaseChildChangeListenerDelegate OnChildChange;

	UPROPERTY(BlueprintAssignable)
	FFireBaseChildMoveListenerDelegate OnChildMove;
	
	UPROPERTY(BlueprintAssignable)
	FFireBaseChildRemoveListenerDelegate OnChildRemove;

	virtual void BeginDestroy() override;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddChildListener", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "FireBase")
	static UFirebaseChildListenerCallback* AddChildListener(UFirebaseQuery* query);

	UFUNCTION(BlueprintCallable, Category = "FireBase")
	void RemoveChildListener();

	void OnChildAdded(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key);
	void OnChildChanged(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key);
	void OnChildMoved(const firebase::database::DataSnapshot& snapshot, const char* previous_sibling_key);
	void OnChildRemoved(const firebase::database::DataSnapshot& snapshot);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireBase")
	UFirebaseQuery* mQuery;
	

	TSharedPtr<firebase::database::ChildListener> mListenerImp;
};
