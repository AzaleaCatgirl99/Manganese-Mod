using System.Runtime.InteropServices;
using Minecraft.Interop;

namespace Minecraft.Client.Dlc;

public unsafe class DlcPack(DlcPack.Native* handle) : NativeClassWrapper<DlcPack.Native>(handle)
{
    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x300)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x300];
        
        [FieldOffset(0x228)] public int Id;
    }
}