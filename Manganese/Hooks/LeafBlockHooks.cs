using System.Runtime.InteropServices;
using Durangling;
using Minecraft.World.Blocks;

namespace Manganese.Hooks;

using unsafe IsSolidRender = delegate* unmanaged<long, bool>;
using unsafe ShouldRenderFace = delegate* unmanaged<long, long, long, long, long, bool>;
using unsafe SetFancy = delegate* unmanaged<long, char, void>;

public static unsafe class LeafBlockHooks
{
    private static IsSolidRender TrueIsSolidRender = LeafBlock.NativeMethods.IsSolidRender;
    private static ShouldRenderFace TrueShouldRenderFace = LeafBlock.NativeMethods.ShouldRenderFace;
    private static void* TrueSetFancy = LeafBlock.NativeMethods.SetFancy;

    public static void Attach()
    {
        Detour.Attach(TrueIsSolidRender, (IsSolidRender)(&IsSolidRenderHook));
        Detour.Attach(TrueShouldRenderFace, (ShouldRenderFace)(&ShouldRenderFaceHook));
        Detour.Attach(TrueSetFancy, (SetFancy)(&SetFancyHook));
    }

    public static void Detach()
    {
        Detour.Detach(TrueIsSolidRender, (IsSolidRender)(&IsSolidRenderHook));
        Detour.Detach(TrueShouldRenderFace, (ShouldRenderFace)(&ShouldRenderFaceHook));
        Detour.Detach(TrueSetFancy, (SetFancy)(&SetFancyHook));
    }

    [UnmanagedCallersOnly]
    private static bool IsSolidRenderHook(long self)
    {
        return true;
    }

    [UnmanagedCallersOnly]
    private static bool ShouldRenderFaceHook(long a, long b, long c, long d, long e)
    {
        return true;
    }

    [UnmanagedCallersOnly]
    private static void SetFancyHook(long self, char value)
    {
        ((SetFancy)TrueSetFancy)(self, '\0');
    }
}
