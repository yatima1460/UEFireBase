#include "FireBaseEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
//#include "VungleSetting.h"
#include "AdMobSetting.h"
#include "GoogleSignSetting.h"
#include "FacebookSignSetting.h"
#include "TwitterSignSetting.h"
//#include "UnitySetting.h"
//#include "ChartBoostSetting.h"
#include "ISettingsModule.h"

#include "LevelEditor.h"

static const FName AdCollectionEditorTabName("FireBaseEditor");

#define LOCTEXT_NAMESPACE "FFireBaseEditorModule"

void FFireBaseEditorModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		
		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("FireBase"), TEXT("Google"),
			LOCTEXT("Google", "Google"),
			LOCTEXT("Google", "Settings for Google"),
			GetMutableDefault<UGoogleSignSetting>()
		);

		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("FireBase"), TEXT("FaceBook"),
			LOCTEXT("Facebook", "Facebook"),
			LOCTEXT("Facebook", "Settings for Facebook"),
			GetMutableDefault<UFacebookSignSetting>()
		);


		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("FireBase"), TEXT("Twitter"),
			LOCTEXT("Twitter", "Twitter"),
			LOCTEXT("Twitter", "Settings for Twitter"),
			GetMutableDefault<UTwitterSignSetting>()
		);
	}
}

void FFireBaseEditorModule::ShutdownModule()
{
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFireBaseEditorModule, FireBaseEditor)
