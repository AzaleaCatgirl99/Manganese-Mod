using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Durangling;
using Minecraft.Client.Renderer;

namespace Manganese.Hooks;

using unsafe StateSetFogEnable = delegate* unmanaged[Thiscall]<Renderer.Native*, bool, void>;

public static unsafe class RendererHooks
{
    private static void* TrueStateSetFogEnable = Renderer.NativeMethods.StateSetFogEnable;

    public static void Attach()
    {
        Detour.Attach(TrueStateSetFogEnable, (StateSetFogEnable)(&StateSetFogEnableHook));
    }

    public static void Detach()
    {
        Detour.Detach(TrueStateSetFogEnable, (StateSetFogEnable)(&StateSetFogEnableHook));
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void StateSetFogEnableHook(Renderer.Native* handle, bool useFog)
    {
        ((StateSetFogEnable)TrueStateSetFogEnable)(handle, false);
    }
}