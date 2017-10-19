// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class FireBase : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public FireBase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"FireBase/Public"
				
				// ... add public include paths required here ...
			}
			);

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Android)
        {


            PrivateIncludePaths.Add("Private/Common");
            PrivateIncludePaths.Add("Private/Android");
            PrivateIncludePaths.Add("FireBase/ThirdParty/FireBaseCpp/include");

            PrivateDependencyModuleNames.AddRange(
                new string[] {
                "Launch",
                }
                );

            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModulePath, "ThirdParty/FireBaseCpp/libs/android/armeabi")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModulePath, "ThirdParty/FireBaseCpp/libs/android/armeabi-v7a")));
            //PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModulePath, "ThirdParty/FireBaseCpp/libs/android/arm64-v8a")));

            string[] StaticLibrariesAndroid = new string[] {
                "app",
                "database",
            };

            foreach (string Lib in StaticLibrariesAndroid)
            {
                PublicAdditionalLibraries.Add(Lib);
            }

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "FireBase_UPL.xml")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            PrivateIncludePaths.Add("FireBase/Private/Common");
            PrivateIncludePaths.Add("FireBase/Private/Windows");
            PrivateIncludePaths.Add("FireBase/ThirdParty/FireBaseCpp/include");

            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModulePath, "ThirdParty/FireBaseCpp/libs/windows")));

            /*string[] StaticLibrariesAndroid = new string[] {
                "libapp.a",
                "libdatabase.a",
            };

            foreach (string Lib in StaticLibrariesAndroid)
            {
                PublicAdditionalLibraries.Add(Lib);
            }*/
        }

    }
}
