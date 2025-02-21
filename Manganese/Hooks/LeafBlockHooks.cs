using System.Reflection.Metadata;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Durangling;
using Minecraft.World.Blocks;

namespace Manganese.Hooks;

using unsafe SetFancy = delegate* unmanaged<int, bool>;

public static unsafe class LeafBlockHooks
{
    private static SetFancy TrueSetFancy = LeafBlock.NativeMethods.SetFancy;

    public static void Attach()
    {
        Detour.Attach(TrueSetFancy, (SetFancy)(&SetFancyHook));
    }

    public static void Detach()
    {
        Detour.Detach(TrueSetFancy, (SetFancy)(&SetFancyHook));
    }

    [UnmanagedCallersOnly]
    private static bool SetFancyHook(int i)
    {
        return true; // TODO Make the culling better and rename from SetFancy
    }
}
