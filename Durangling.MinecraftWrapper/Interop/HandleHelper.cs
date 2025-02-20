using System.Diagnostics;

namespace Minecraft.Interop;

public static unsafe class HandleHelper
{
    public const long ImageBaseAddress = 0x140000000;
    
    public static void* GetProcessHandle(long imageAddress)
    {
        Process process = Process.GetCurrentProcess();
        Debug.Assert(process.MainModule != null);
        return (void*)(process.MainModule!.BaseAddress + (imageAddress - ImageBaseAddress));
    }
}