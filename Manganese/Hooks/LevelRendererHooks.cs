using System.Runtime.InteropServices;
using Durangling;
using Minecraft.Client.Renderer;

namespace Manganese.Hooks;

using unsafe Z = delegate* unmanaged<long, long, int, byte, uint, void>;
using unsafe H = delegate* unmanaged<long, uint, int, uint, void>;
using unsafe F = delegate* unmanaged<long, int, byte, void>;
using unsafe S = delegate* unmanaged<long, int, void>;
using unsafe GetViewDistance = delegate* unmanaged<long, int>;

public static unsafe class LevelRendererHooks
{
    private static void* TrueZ = LevelRenderer.NativeMethods.Z;
    private static void* TrueH = LevelRenderer.NativeMethods.H;
    private static void* TrueF = LevelRenderer.NativeMethods.F;
    private static void* TrueS = LevelRenderer.NativeMethods.S;
    private static GetViewDistance TrueGetViewDistance = LevelRenderer.NativeMethods.GetViewDistance;

    public static void Attach()
    {
        //Detour.Attach(TrueZ, (Z)(&ZHook));
        Detour.Attach(TrueH, (H)(&HHook));
        Detour.Attach(TrueF, (F)(&FHook));
        Detour.Attach(TrueS, (S)(&SHook));
        Detour.Attach(TrueGetViewDistance, (GetViewDistance)(&GetViewDistanceHook));
    }

    public static void Detach()
    {
        //Detour.Detach(TrueZ, (Z)(&ZHook));
        Detour.Detach(TrueH, (H)(&HHook));
        Detour.Detach(TrueF, (F)(&FHook));
        Detour.Detach(TrueS, (S)(&SHook));
        Detour.Detach(TrueGetViewDistance, (GetViewDistance)(&GetViewDistanceHook));
    }

    [UnmanagedCallersOnly]
    private static void ZHook(long self, long a, int b, byte c, uint d)
    {
        ((Z)TrueZ)(self, a, b, c, d);
    }

    [UnmanagedCallersOnly]
    private static void HHook(long self, uint a, int b, uint c)
    {
        ((H)TrueH)(self, a, b, c);
    }

    [UnmanagedCallersOnly]
    private static void FHook(long self, int a, byte b)
    {
        ((F)TrueF)(self, a, b);
    }

    [UnmanagedCallersOnly]
    private static void SHook(long self, int a)
    {
        ((S)TrueS)(self, a);
    }

    [UnmanagedCallersOnly]
    private static int GetViewDistanceHook(long self)
    {
        return 10;
    }
}
