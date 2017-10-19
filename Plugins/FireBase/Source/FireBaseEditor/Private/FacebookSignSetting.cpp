// Fill out your copyright notice in the Description page of Project Settings.

#include "FireBaseEditor.h"
#include "FacebookSignSetting.h"



#if WITH_EDITOR
void UFacebookSignSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig(CPF_Config, *GetDefaultConfigFilename());
}
#endif
