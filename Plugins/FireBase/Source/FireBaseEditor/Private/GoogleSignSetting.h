// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GoogleSignSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UGoogleSignSetting : public UObject
{
	GENERATED_BODY()
	
	// if the android admob enable
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Android Google Signin Enable"))
	bool bAndroidEnabled;

	// the android admob appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "WebClient ID"))
	FString webClientID;
	

#if WITH_EDITOR

	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
