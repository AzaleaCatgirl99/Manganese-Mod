using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;

namespace Durangling;

public static unsafe class Detour
{
    private const string LibName = "detours";

    [DllImport(LibName, EntryPoint = "DetourIsHelperProcess")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    [return: MarshalAs(UnmanagedType.Bool)]
    public static extern bool IsHelperProcess();

    [DllImport(LibName, EntryPoint = "DetourRestoreAfterWith")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long RestoreAfterWith();

    [DllImport(LibName, EntryPoint = "DetourUpdateThread")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long UpdateThread(HANDLE hThread);

    [DllImport(LibName, EntryPoint = "DetourTransactionBegin")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long TransactionBegin();

    [DllImport(LibName, EntryPoint = "DetourTransactionCommit")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long TransactionCommit();

    [DllImport(LibName, EntryPoint = "DetourAttach")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long Attach(in void* ppPointer, void* pDetour);

    [DllImport(LibName, EntryPoint = "DetourDetach")]
    [UnmanagedCallConv(CallConvs = [typeof(CallConvStdcall)])]
    public static extern long Detach(in void* ppPointer, void* pDetour);
}