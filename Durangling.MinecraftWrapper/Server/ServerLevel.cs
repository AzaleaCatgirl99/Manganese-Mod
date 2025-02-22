using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Minecraft.Interop;

namespace Minecraft.Server;

public unsafe class ServerLevel(ServerLevel.Native* handle) : NativeClassWrapper<ServerLevel.Native>(handle)
{
    public static UInt64 GetViewDistance(void* self)
    {
        return NativeMethods.GetViewDistance(self);
    }

    public static void Constructor(ServerLevel.Native* self, void* minecraftServer, void* levelStorage, void* levelData, int a5)
    {
        NativeMethods.Constructor(self,  minecraftServer, levelStorage, levelData, a5);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x110)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x110];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<void*, UInt64> GetViewDistance;
        public static readonly delegate* unmanaged<Native*, void*, void*, void*, int, void> Constructor;

        static NativeMethods()
        {
            GetViewDistance = (delegate* unmanaged<void*, UInt64>)HandleHelper.GetProcessHandle(Addresses.ServerLevel.GetViewDistance);
            Constructor = (delegate* unmanaged<Native*, void*, void*, void*, int, void>)HandleHelper.GetProcessHandle(Addresses.ServerLevel.Constructor);
        }
    }
}
