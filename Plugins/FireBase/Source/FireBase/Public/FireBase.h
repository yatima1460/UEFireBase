// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "FireBaseBPLibrary.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FFireBaseSignSuccedComplete, FFireBaseUser);
typedef FFireBaseSignSuccedComplete::FDelegate FFireBaseSignSuccedCompleteDelegate;


DECLARE_MULTICAST_DELEGATE(FFireBaseSignOutComplete);
typedef FFireBaseSignOutComplete::FDelegate FFireBaseSignOutCompleteDelegate;

DECLARE_MULTICAST_DELEGATE_OneParam(FFireBaseGetUserComplete, FFireBaseUser);
typedef FFireBaseGetUserComplete::FDelegate FFireBaseGetUserCompleteDelegate;

DECLARE_MULTICAST_DELEGATE(FFireBaseUserNotLogin);
typedef FFireBaseUserNotLogin::FDelegate FFireBaseUserNotLoginDelegate;


#define DEFINE_SIGN_DELEGATE_BASE(DelegateName) \
public: \
	F##DelegateName DelegateName##Delegates; \
public: \
	virtual FDelegateHandle Add##DelegateName##Delegate_Handle(const F##DelegateName##Delegate& Delegate) \
	{ \
		DelegateName##Delegates.Add(Delegate); \
		return Delegate.GetHandle(); \
	} \
	virtual void Clear##DelegateName##Delegate_Handle(FDelegateHandle& Handle) \
	{ \
		DelegateName##Delegates.Remove(Handle); \
		Handle.Reset(); \
	}\
	virtual void ClearAll##DelegateName##Delegate_Handle() \
	{ \
		DelegateName##Delegates.Clear(); \
	}


#define DEFINE_SIGN_DELEGATE_ONE_PARAM(DelegateName, Param1Type) \
	DEFINE_SIGN_DELEGATE_BASE(DelegateName) \
	virtual void Trigger##DelegateName##Delegates(Param1Type Param1) \
	{ \
		DelegateName##Delegates.Broadcast(Param1); \
	}


class FFireBaseModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


	DEFINE_SIGN_DELEGATE_ONE_PARAM(FireBaseSignSuccedComplete, FFireBaseUser);
	DEFINE_SIGN_DELEGATE_BASE(FireBaseSignOutComplete);

	DEFINE_SIGN_DELEGATE_ONE_PARAM(FireBaseGetUserComplete, FFireBaseUser);
	DEFINE_SIGN_DELEGATE_BASE(FireBaseUserNotLogin);
};