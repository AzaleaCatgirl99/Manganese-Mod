using System.Runtime.Versioning;
using Windows.Win32;
using Durangling.Modding;
using Durangling.Utilities;

namespace Durangling;

public static unsafe class DuranglingEntrypoint
{
    private const int DLL_PROCESS_ATTACH = 1;
    private const int DLL_PROCESS_DETACH = 0;
    
    public static bool Initialize(ReadOnlySpan<Mod> mods, uint reason)
    {
        if (reason is not (DLL_PROCESS_ATTACH or DLL_PROCESS_DETACH))
        {
            return true;
        }
        
        foreach (Mod mod in mods)
        {
            Logger.Write(Logger.Level.Debug, $"{(reason == DLL_PROCESS_ATTACH ? "Loading" : "Unloading")} {mod.Details.Name} ({mod.Details.Id}) {mod.Details.Version}");
            switch (reason)
            {
                case DLL_PROCESS_ATTACH:
                    mod.Initialize();
                    Logger.Write(Logger.Level.Debug, "Finished initializing");
                    break;
            
                case DLL_PROCESS_DETACH:
                    mod.Dispose();
                    Logger.Write(Logger.Level.Debug, "Finished disposing");
                    break;
            }
        }

        return true;
    }
}