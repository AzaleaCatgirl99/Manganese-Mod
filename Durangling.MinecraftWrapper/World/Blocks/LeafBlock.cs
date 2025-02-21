using System.Runtime.InteropServices;
using Minecraft.Interop;

namespace Minecraft.World.Blocks;

public unsafe class LeafBlock(LeafBlock.Native* handle) : NativeClassWrapper<LeafBlock.Native>(handle)
{
    public static bool IsSolidRender(long self)
    {
        return NativeMethods.IsSolidRender(self);
    }

    public static bool ShouldRenderFace(long a, long b, long c, long d, long e)
    {
        return NativeMethods.ShouldRenderFace(a, b, c, d, e);
    }

    public static void SetFancy(long self, char value)
    {
        NativeMethods.SetFancy(self, value);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x110)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x110];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<long, bool> IsSolidRender;
        public static readonly delegate* unmanaged<long, long, long, long, long, bool> ShouldRenderFace; // TODO figure out the true args for function
        public static readonly delegate* unmanaged<long, char, void> SetFancy;

        static NativeMethods()
        {
            IsSolidRender = (delegate* unmanaged<long, bool>)HandleHelper.GetProcessHandle(Addresses.LeafBlock.IsSolidRender);
            ShouldRenderFace = (delegate* unmanaged<long, long, long, long, long, bool>)HandleHelper.GetProcessHandle(Addresses.LeafBlock.ShouldRenderFace);
            SetFancy = (delegate* unmanaged<long, char, void>)HandleHelper.GetProcessHandle(Addresses.LeafBlock.SetFancy);
        }
    }
}
