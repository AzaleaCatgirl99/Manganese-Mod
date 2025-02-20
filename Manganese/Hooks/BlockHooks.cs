using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Durangling;
using Minecraft.World.Blocks;

namespace Manganese.Hooks;

using unsafe SetLuminescence = delegate* unmanaged[Thiscall]<Block.Native*, int, void>;

public static unsafe class BlockHooks
{
    private static void* TrueSetLuminiscence = Block.NativeMethods.SetLuminescence;

    public static void Attach()
    {
        //Detour.Attach(TrueSetLuminiscence, (SetLuminescence)(&SetLuminescenceHook));
    }

    public static void Detach()
    {
        //Detour.Detach(TrueSetLuminiscence, (SetLuminescence)(&SetLuminescenceHook));
    }

    [UnmanagedCallersOnly(CallConvs = [typeof(CallConvThiscall)])]
    private static void SetLuminescenceHook(Block.Native* self, int luminescence)
    {
        ((SetLuminescence)TrueSetLuminiscence)(self, luminescence);
    }
}