#include "FireBaseBPLibrary.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "firebase/database.h"
#include "firebase/util.h"
#include "FireBase.h"

::firebase::App* g_firebaseApp = nullptr;

UFireBaseBPLibrary::UFireBaseBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

static void callVoidFunction(const FString& strFunName)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		jmethodID signFun = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, TCHAR_TO_UTF8(*strFunName), "()V", bIsOptional);
		if (signFun == nullptr)
		{
			UE_LOG(FireBase, Error, TEXT("%s not found"), *strFunName);
			return;
		}

		UE_LOG(FireBase, Error, TEXT("Call Sign Function:%s"), *strFunName);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, signFun);
	}
}

static bool callBoolFunction(const FString& strFunName)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		jmethodID tmpFun = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, TCHAR_TO_UTF8(*strFunName), "()Z", bIsOptional);
		if (tmpFun == nullptr)
		{
			UE_LOG(FireBase, Error, TEXT("%s not found"), *strFunName);
			return false;
		}

		UE_LOG(FireBase, Error, TEXT("Call Sign Function:%s"), *strFunName);
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, tmpFun);
	}

	return false;
}

static FString callStringFunction(const FString& strFunName)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		jmethodID tmpFun = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, TCHAR_TO_UTF8(*strFunName), "()Ljava/lang/String;", bIsOptional);
		if (tmpFun == nullptr)
		{
			UE_LOG(FireBase, Error, TEXT("%s not found"), *strFunName);
			return FString();
		}

		jstring ret = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, tmpFun);
		if (ret != NULL)
		{
			const char* charsRet = Env->GetStringUTFChars(ret, 0);
			return FString(UTF8_TO_TCHAR(charsRet));
		}
	}

	return FString();
}

void UFireBaseBPLibrary::GoogleSign()
{
	callVoidFunction(TEXT("AndroidThunkJava_GoogleSignIn") );
}

void UFireBaseBPLibrary::GoogleSignOut()
{
	UE_LOG(FireBase, Error, TEXT("Call Google SignOut"));
	callVoidFunction(TEXT("AndroidThunkJava_GoogleSignOut"));
}

void UFireBaseBPLibrary::FacebookSignIn()
{
	callVoidFunction(TEXT("AndroidThunkJava_FacebookSignIn"));
}

void UFireBaseBPLibrary::FacebookSignOut()
{
	UE_LOG(FireBase, Error, TEXT("Call FaceBook SignOut") );
	callVoidFunction(TEXT("AndroidThunkJava_FacebookSignOut"));
}

void UFireBaseBPLibrary::TwitterSignIn()
{
	UE_LOG(FireBase, Error, TEXT("Call Twitter SignIn"));
	callVoidFunction(TEXT("AndroidThunkJava_TwitterSignIn"));
}

void UFireBaseBPLibrary::TwitterSignOut()
{
	UE_LOG(FireBase, Error, TEXT("Call Twitter SignOut"));
	callVoidFunction(TEXT("AndroidThunkJava_TwitterSignOut"));
}

void UFireBaseBPLibrary::AnonymouslySignIn()
{
	UE_LOG(FireBase, Error, TEXT("Call Anonymously SignIn"));
	callVoidFunction(TEXT("AndroidThunkJava_AnonymouslySignIn"));
}

void UFireBaseBPLibrary::AnonymouslySignOut()
{
	UE_LOG(FireBase, Error, TEXT("Call Anonymously SignOut"));
	callVoidFunction(TEXT("AndroidThunkJava_AnonymouslySignOut"));
}

void UFireBaseBPLibrary::GetFirebaseUserInfo()
{
	UE_LOG(FireBase, Error, TEXT("Call GetFirebaseUserInfo"));
	callVoidFunction(TEXT("AndroidThunkJava_TryGetUserInfo"));
}

void UFireBaseBPLibrary::FireBaseInitialize()
{
	UE_LOG(FireBase, Error, TEXT("FireBaseInitialize to initialize Firebase Database."));
	g_firebaseApp = ::firebase::App::Create(FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);

	::firebase::database::Database* database = nullptr;
	void* initialize_targets[] = {&database };

	const firebase::ModuleInitializer::InitializerFn initializers[] = {

		[](::firebase::App* app, void* data) {

		UE_LOG(FireBase, Error, TEXT("Attempt to initialize Firebase Database."));
		void** targets = reinterpret_cast<void**>(data);
		::firebase::InitResult result;
		*reinterpret_cast<::firebase::database::Database**>(targets[0]) =
			::firebase::database::Database::GetInstance(app, &result);
		return result;
	} };

	::firebase::ModuleInitializer initializer;
	initializer.Initialize(g_firebaseApp, initialize_targets, initializers,
		sizeof(initializers) / sizeof(initializers[0]));

	if (initializer.InitializeLastResult().error() != 0) 
	{
		UE_LOG(FireBase, Error, TEXT("Failed to initialize Firebase libraries: %s"), initializer.InitializeLastResult().error_message() );
	}
}

bool UFireBaseBPLibrary::isFirebaseUserLogin()
{
	return callBoolFunction(TEXT("AndroidThunkJava_IsUserLogin") );
}

static void nativeSigninSuccedHelper(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		FFireBaseUser user;
		if(email != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(email, 0);
			user.email = FString(UTF8_TO_TCHAR(charsType));
		}

		if(displayName != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(displayName, 0);
			user.displayName = FString(UTF8_TO_TCHAR(charsType));
		}

		if(uid != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(uid, 0);
			user.uid = FString(UTF8_TO_TCHAR(charsType));
		}

		if(photourl != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(photourl, 0);
			user.photoUrl = FString(UTF8_TO_TCHAR(charsType));
		}

		user.isAnonymous = isAnonymous;
		Module->TriggerFireBaseSignSuccedCompleteDelegates(user);
	}
}

void UFireBaseBPLibrary::FirebaseSignout()
{
	FString strProvider = callStringFunction("AndroidThunkJava_GetLoginProvider");
	UE_LOG(FireBase, Error, TEXT("Login Provider: %s"), *strProvider);

	if (strProvider.ToLower() == TEXT("facebook") )
	{
		callVoidFunction(TEXT("AndroidThunkJava_FacebookSignOut"));
	}
	else if (strProvider.ToLower() == TEXT("google") )
	{
		callVoidFunction(TEXT("AndroidThunkJava_GoogleSignIn"));
	}
	else if (strProvider.ToLower() == TEXT("twitter"))
	{
		callVoidFunction(TEXT("AndroidThunkJava_TwitterSignOut"));
	}
	else
	{
		callVoidFunction(TEXT("AndroidThunkJava_FirebaseSignout"));
	}
}

static void nativeLogoutHelper(JNIEnv* jenv, jobject thiz)
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->FireBaseSignOutCompleteDelegates.Broadcast();
	}
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_GoogleLogin_nativeSigninSucced(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	nativeSigninSuccedHelper(jenv, thiz, email, displayName, uid, photourl, isAnonymous);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_GoogleLogin_nativeSignout(JNIEnv* jenv, jobject thiz)
{
	UE_LOG(FireBase, Error, TEXT("***************************Google SignOut Native Call"));
	nativeLogoutHelper(jenv, thiz);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_FacebookLogin_nativeSigninSucced(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	nativeSigninSuccedHelper(jenv, thiz, email, displayName, uid, photourl, isAnonymous);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_FacebookLogin_nativeSignout(JNIEnv* jenv, jobject thiz)
{
	nativeLogoutHelper(jenv, thiz);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_TwitterLogin_nativeSigninSucced(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	nativeSigninSuccedHelper(jenv, thiz, email, displayName, uid, photourl, isAnonymous);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_TwitterLogin_nativeSignout(JNIEnv* jenv, jobject thiz)
{
	nativeLogoutHelper(jenv, thiz);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_AnonymouslyLogin_nativeSigninSucced(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	nativeSigninSuccedHelper(jenv, thiz, email, displayName, uid, photourl, isAnonymous);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_AnonymouslyLogin_nativeSignout(JNIEnv* jenv, jobject thiz)
{
	nativeLogoutHelper(jenv, thiz);
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_FirebaseHelper_nativeUserInfo(JNIEnv* jenv, jobject thiz, jstring email, jstring displayName, jstring uid, jstring photourl, jboolean isAnonymous)
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		FFireBaseUser user;
		if (email != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(email, 0);
			user.email = FString(UTF8_TO_TCHAR(charsType));
		}

		if (displayName != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(displayName, 0);
			user.displayName = FString(UTF8_TO_TCHAR(charsType));
		}

		if (uid != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(uid, 0);
			user.uid = FString(UTF8_TO_TCHAR(charsType));
		}

		if (photourl != nullptr)
		{
			const char* charsType = jenv->GetStringUTFChars(photourl, 0);
			user.photoUrl = FString(UTF8_TO_TCHAR(charsType));
		}

		user.isAnonymous = isAnonymous;

		Module->TriggerFireBaseGetUserCompleteDelegates(user);
	}
}

__attribute__((visibility("default"))) extern "C" void Java_com_util_firebasehelper_FirebaseHelper_nativeUserNotLogin(JNIEnv* jenv, jobject thiz)
{
	FFireBaseModule * Module = FModuleManager::Get().LoadModulePtr<FFireBaseModule>("FireBase");
	if (Module != nullptr)
	{
		Module->FireBaseUserNotLoginDelegates.Broadcast();
	}
}