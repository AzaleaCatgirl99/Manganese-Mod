using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Minecraft.Interop;

namespace Minecraft.Client.Renderer;

public unsafe class LevelRenderer(LevelRenderer.Native* handle) : NativeClassWrapper<LevelRenderer.Native>(handle)
{
    public static void Z(long self, long a, int b, byte c, uint d)
    {
        NativeMethods.Z(self, a, b, c, d);
    }

    public static void H(long self, uint a, int b, uint c)
    {
        NativeMethods.H(self, a, b, c);
    }

    public static void F(long self, int a, byte b)
    {
        NativeMethods.F(self, a, b);
    }

    public static void S(long self, int a)
    {
        NativeMethods.S(self, a);
    }

    public static int GetViewDistance(long self)
    {
        return NativeMethods.GetViewDistance(self);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x110)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x110];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<long, long, int, byte, uint, void> Z;
        public static readonly delegate* unmanaged<long, uint, int, uint, void> H;
        public static readonly delegate* unmanaged<long, int, byte, void> F;
        public static readonly delegate* unmanaged<long, int, void> S;

        public static readonly delegate* unmanaged<long, int> GetViewDistance;

        static NativeMethods()
        {
            Z = (delegate* unmanaged<long, long, int, byte, uint, void> )HandleHelper.GetProcessHandle(Addresses.LevelRenderer.Z);
            H = (delegate* unmanaged<long, uint, int, uint, void>)HandleHelper.GetProcessHandle(Addresses.LevelRenderer.H);
            F = (delegate* unmanaged<long, int, byte, void>)HandleHelper.GetProcessHandle(Addresses.LevelRenderer.F);
            S = (delegate* unmanaged<long, int, void>)HandleHelper.GetProcessHandle(Addresses.LevelRenderer.S);

            GetViewDistance = (delegate* unmanaged<long, int>)HandleHelper.GetProcessHandle(Addresses.LevelRenderer.GetViewDistance);
        }
    }
}
