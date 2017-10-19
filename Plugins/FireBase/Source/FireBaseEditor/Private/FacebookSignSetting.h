// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FacebookSignSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UFacebookSignSetting : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Android Facebook Signin Enable"))
	bool bAndroidEnabled;

	// the android admob appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Appid"))
	FString facebookAppID;


#if WITH_EDITOR

	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	
};
