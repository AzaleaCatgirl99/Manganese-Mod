using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Durangling;

namespace Manganese;

public static unsafe class ModEntrypoint
{
    private static readonly Manganese Instance = new();

    [UnmanagedCallersOnly(EntryPoint = "DllMain", CallConvs = [typeof(CallConvStdcall)])]
    public static bool DllMain(nint hinstDLL, uint fdwReason, void* lpvReserved)
    {
        return DuranglingEntrypoint.Initialize([Instance], fdwReason);
    }
}