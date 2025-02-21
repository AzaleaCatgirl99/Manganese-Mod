using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Minecraft.Interop;

namespace Minecraft.Client.Renderer;

public unsafe class Renderer(Renderer.Native* handle) : NativeClassWrapper<Renderer.Native>(handle)
{
    public void SetFogStateUniversal(Renderer.Native* self, bool value)
    {
        NativeMethods.SetFogStateUniversal(self, value);
    }

    public void SetLightStateUniversal(Renderer.Native* self, bool useLight)
    {
        NativeMethods.SetLightStateUniversal(self, useLight);
    }

    public void SetMipmapStateUniversal(Renderer.Native* self, bool value)
    {
        NativeMethods.SetMipmapStateUniversal(self, value);
    }

    public void SomethingWithBanners(Renderer.Native* self, int i)
    {
        NativeMethods.SomethingWithBanners(self, i);
    }

    public int Q(Renderer.Native* self, int q)
    {
        return NativeMethods.Q(self, q);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x117)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x117];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged[Thiscall]<Native*, bool, void> SetFogStateUniversal;
        public static readonly delegate* unmanaged[Thiscall]<Native*, bool, void> SetLightStateUniversal;
        public static readonly delegate* unmanaged[Thiscall]<Native*, bool, void> SetMipmapStateUniversal;
        public static readonly delegate* unmanaged[Thiscall]<Native*, int, void> SomethingWithBanners;
        public static readonly delegate* unmanaged[Thiscall]<Native*, int, int> Q;

        static NativeMethods()
        {
            SetFogStateUniversal = (delegate* unmanaged[Thiscall]<Native*, bool, void>)HandleHelper.GetProcessHandle(Addresses.Renderer.StateSetFogEnable);
            SetLightStateUniversal = (delegate* unmanaged[Thiscall]<Native*, bool, void>)HandleHelper.GetProcessHandle(Addresses.Renderer.StateSetLightEnable);
            SetMipmapStateUniversal = (delegate* unmanaged[Thiscall]<Native*, bool, void>)HandleHelper.GetProcessHandle(Addresses.Renderer.SetMipmapStateUniversal);
            SomethingWithBanners = (delegate* unmanaged[Thiscall]<Native*, int, void>)HandleHelper.GetProcessHandle(Addresses.Renderer.SomethingWithBanners);
            Q = (delegate* unmanaged[Thiscall]<Native*, int, int>)HandleHelper.GetProcessHandle(Addresses.Renderer.Q);
        }
    }
}
