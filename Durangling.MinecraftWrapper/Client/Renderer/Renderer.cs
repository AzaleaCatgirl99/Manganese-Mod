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
    public void StateSetFogEnabled(Renderer.Native* handle, bool useFog)
    {
        NativeMethods.StateSetFogEnable(handle, useFog);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x117)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x117];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged[Thiscall]<Native*, bool, void> StateSetFogEnable;

        static NativeMethods()
        {
            StateSetFogEnable = (delegate* unmanaged[Thiscall]<Native*, bool, void>)HandleHelper.GetProcessHandle(Addresses.Renderer.StateSetFogEnable);
        }
    }
}
