using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Minecraft.Interop;

namespace Minecraft.World.Blocks;

public unsafe class LeafBlock(LeafBlock.Native* handle) : NativeClassWrapper<LeafBlock.Native>(handle)
{
    public static bool SetFancy(int i)
    {
        return NativeMethods.SetFancy(i);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x110)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x110];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<int, bool> SetFancy;

        static NativeMethods()
        {
            SetFancy = (delegate* unmanaged<int, bool>)HandleHelper.GetProcessHandle(Addresses.LeafBlock.SetFancy);
        }
    }
}
