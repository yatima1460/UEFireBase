// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TwitterSignSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UTwitterSignSetting : public UObject
{
	GENERATED_BODY()
	
	
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Android Google Signin Enable"))
	bool bAndroidEnabled;

	// the android admob appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "api key"))
	FString apiKey;

	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "api secret"))
	FString apiSecret;


#if WITH_EDITOR

	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
