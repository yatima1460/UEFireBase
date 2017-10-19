// Fill out your copyright notice in the Description page of Project Settings.

#include "FireBaseEditor.h"
#include "TwitterSignSetting.h"

#if WITH_EDITOR
void UTwitterSignSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig(CPF_Config, *GetDefaultConfigFilename());
}
#endif


