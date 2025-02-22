using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Durangling;
using Minecraft.Interop;
using Minecraft.Server;

namespace Manganese.Hooks;

using unsafe GetViewDistance = delegate* unmanaged<void*, UInt64>;
using unsafe Constructor = delegate* unmanaged<ServerLevel.Native*, void*, void*, void*, int, void>;

public static unsafe class ServerLevelHooks
{
    private static GetViewDistance TrueGetViewDistance = ServerLevel.NativeMethods.GetViewDistance;
    private static void* TrueConstructor = ServerLevel.NativeMethods.Constructor;

    public static void Attach()
    {
        //Detour.Attach(TrueGetViewDistance, (GetViewDistance)(&GetViewDistanceHook));
        Detour.Attach(TrueConstructor, (Constructor)(&ConstructorHook));
    }

    public static void Detach()
    {
        //Detour.Detach(TrueGetViewDistance, (GetViewDistance)(&GetViewDistanceHook));
        Detour.Detach(TrueConstructor, (Constructor)(&ConstructorHook));
    }

    [UnmanagedCallersOnly]
    private static UInt64 GetViewDistanceHook(void* self)
    {
        return 10;
        //return ((GetViewDistance)TrueGetViewDistance)(self);
    }

    [UnmanagedCallersOnly]
    private static void ConstructorHook(ServerLevel.Native* self, void* minecraftServer, void* levelStorage, void* levelData, int a5)
    {
        Detour.Attach((GetViewDistance)TrueGetViewDistance(minecraftServer), (GetViewDistance)(&GetViewDistanceHook));
        ((Constructor)TrueConstructor)(self, minecraftServer, levelStorage, levelData, a5);
        Detour.Detach((GetViewDistance)TrueGetViewDistance(minecraftServer), (GetViewDistance)(&GetViewDistanceHook));
    }
}
