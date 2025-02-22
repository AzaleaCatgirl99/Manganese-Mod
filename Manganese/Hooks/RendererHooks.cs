using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Durangling;
using Minecraft.Client.Renderer;

namespace Manganese.Hooks;

using unsafe SetFogStateUniversal = delegate* unmanaged[Thiscall]<Renderer.Native*, bool, void>;
using unsafe SetLightStateUniversal = delegate* unmanaged[Thiscall]<Renderer.Native*, bool, void>;
using unsafe SetMipmapStateUniversal = delegate* unmanaged[Thiscall]<Renderer.Native*, bool, void>;
using unsafe SomethingWithBanners = delegate* unmanaged[Thiscall]<Renderer.Native*, int, void>;
using unsafe Q = delegate* unmanaged[Thiscall]<Renderer.Native*, int, int>;
using unsafe C = delegate* unmanaged[Thiscall]<Renderer.Native*, bool, void>;
using unsafe X = delegate* unmanaged[Thiscall]<Renderer.Native*, byte, void>;
using unsafe V = delegate* unmanaged[Thiscall]<Renderer.Native*, byte, byte, void>;

public static unsafe class RendererHooks
{
    private static void* TrueSetFogStateUniversal = Renderer.NativeMethods.SetFogStateUniversal;
    private static void* TrueSetLightStateUniversal = Renderer.NativeMethods.SetLightStateUniversal;
    private static void* TrueSetMipmapStateUniversal = Renderer.NativeMethods.SetMipmapStateUniversal;
    private static void* TrueSomethingWithBanners = Renderer.NativeMethods.SomethingWithBanners;
    private static Q TrueQ = Renderer.NativeMethods.Q;
    private static void* TrueC = Renderer.NativeMethods.C;
    private static void* TrueX = Renderer.NativeMethods.X;
    private static void* TrueV = Renderer.NativeMethods.V;

    public static void Attach()
    {
        Detour.Attach(TrueSetFogStateUniversal, (SetFogStateUniversal)(&SetFogStateUniversalHook));
        Detour.Attach(TrueSetLightStateUniversal, (SetLightStateUniversal)(&SetLightStateUniversalHook));
        Detour.Attach(TrueSetMipmapStateUniversal, (SetMipmapStateUniversal)(&SetMipmapStateUniversalHook));
        Detour.Attach(TrueSomethingWithBanners, (SomethingWithBanners)(&SomethingWithBannersHook));
        Detour.Attach(TrueQ, (Q)(&QHook));
        Detour.Attach(TrueC, (C)(&CHook));
        Detour.Attach(TrueX, (X)(&XHook));
        Detour.Attach(TrueV, (V)(&VHook));
    }

    public static void Detach()
    {
        Detour.Detach(TrueSetFogStateUniversal, (SetFogStateUniversal)(&SetFogStateUniversalHook));
        Detour.Detach(TrueSetLightStateUniversal, (SetLightStateUniversal)(&SetLightStateUniversalHook));
        Detour.Detach(TrueSetMipmapStateUniversal, (SetMipmapStateUniversal)(&SetMipmapStateUniversalHook));
        Detour.Detach(TrueSomethingWithBanners, (SomethingWithBanners)(&SomethingWithBannersHook));
        Detour.Detach(TrueQ, (Q)(&QHook));
        Detour.Detach(TrueC, (C)(&CHook));
        Detour.Detach(TrueX, (X)(&XHook));
        Detour.Detach(TrueV, (V)(&VHook));
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void SetFogStateUniversalHook(Renderer.Native* self, bool value)
    {
        ((SetFogStateUniversal)TrueSetFogStateUniversal)(self, false);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void SetLightStateUniversalHook(Renderer.Native* self, bool value)
    {
        ((SetLightStateUniversal)TrueSetLightStateUniversal)(self, value);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void SetMipmapStateUniversalHook(Renderer.Native* self, bool value)
    {
        ((SetMipmapStateUniversal)TrueSetMipmapStateUniversal)(self, false);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void SomethingWithBannersHook(Renderer.Native* self, int value)
    {
        ((SomethingWithBanners)TrueSomethingWithBanners)(self, value);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static int QHook(Renderer.Native* handle, int q)
    {
        return 1;
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void CHook(Renderer.Native* self, bool value)
    {
        ((C)TrueC)(self, false);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void XHook(Renderer.Native* self, byte value)
    {
        ((X)TrueX)(self, value);
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void VHook(Renderer.Native* self, byte a, byte b)
    {
        ((V)TrueV)(self, a, b);
    }
}