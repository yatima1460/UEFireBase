
#pragma once

#include "ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FFireBaseEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};