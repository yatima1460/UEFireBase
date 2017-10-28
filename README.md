# UnrealEngine4-EZ-Mobile-Ads
this is a firebase basic plugin for unreal engine 4 mobile developer, both c++ and blueprint supported.

This plugin currently is only support android(ios will later support), it contains firbase authentication and fireabse realtime database.
With authentication, you can easily use blueprint or c++ to implement login with facebook, twitter, google and anonymously.
With realtime database, you can do a lot of amazing things.


# FEATURES: 

★  firebase authentication(google, facebook, twitter, anonymously).

★  firebase realtime database.

★  support unreal engine 4 4.17 and 4.18.

★  support via e-mail feixuwu@outlook.com


# PLATFORM SUPPORTED:
★ Android(you can only test on device)



# Install

1.This is a normal c++ plugin, if you do not familiar with how to add plugin to your project,
see [this video](https://youtu.be/DRtkq0ewTz4) to learn how to add c++ plugin to your project.

2.put your google-services.json file under the folder ProjectRoot/Build/Android

3.configure, open the project setting, find the firebase configure section.

4.**to use realtime database, you need first call FirebaseInitialize first in c++ or blueprint.

5.**important if the engine version is 4.18, then you need open android sdk manager and update google repository,
because the engine did not include full firebase 11.0.4.


# Usage
  The best practice to learn how to use this plugin, is to read my demo project blueprint code. To test the project, you need to 
  package the project to android with distribution setting.
  To see this demo how to work, you can direct download the apk from [this](https://www.dropbox.com/s/tsv5ajjgymzcl5n/UEFireBase-Android-Shipping-armv7-es2.apk?dl=0).
  
  ****Note:please do not use my google-services.json for your own product, you should create your own project on firebase console.
  
  
★ Facebook Login
	![ScreenShot](docs/firebasefacebooklogin.PNG)
	
★ Twitter Login
	![ScreenShot](docs/firebasetwitter.PNG)
  
★ Google Login  
	![ScreenShot](docs/firebasegooglelogin.PNG)
	
★ Firebase Logout
	![ScreenShot](docs/firebaselogout.PNG)
  
★ Firebase Realtime Database ReadValue
	![ScreenShot](docs/firebasereadvalue.PNG)
	
★ Firebase Realtime Database SetValue
	![ScreenShot](docs/firebasesetvalue.PNG)
		
★ Firebase Realtime Database Value Listener
	![ScreenShot](docs/firebasevaluelistener.PNG)

★ Firebase Realtime Database Child Listener
	![ScreenShot](docs/firebasechildlistener.PNG)

  
# License
 This is an open source project, you can use it free. If you think this project useful, please give me a star to let me know 
it is useful, so I'll continue make it better and add more firebase module.
