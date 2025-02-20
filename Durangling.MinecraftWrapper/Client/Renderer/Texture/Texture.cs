using Minecraft.Interop;
using System.Runtime.InteropServices;

namespace Minecraft.Client.Renderer.Texture;

public unsafe class Texture(Texture.Native* handle) : NativeClassWrapper<Texture.Native>(handle)
{
    public uint CrispBlend(uint one, uint two)
    {
        return NativeMethods.CrispBlend(one, two);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x110)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x110];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<uint, uint, uint> CrispBlend;

        static NativeMethods()
        {
            CrispBlend = (delegate* unmanaged<uint, uint, uint>)HandleHelper.GetProcessHandle(Addresses.Texture.CrispBlend);
        }
    }
}