using System.Runtime.InteropServices;
using Minecraft.Client.MiniGames;
using Minecraft.Interop;

namespace Minecraft.Client;

public unsafe class Minecraft(Minecraft.Native* handle) : NativeClassWrapper<Minecraft.Native>(handle)
{
    public static Minecraft Instance => new(NativeMethods.GetInstance());

    public void Tick(bool p1, bool p2)
    {
        NativeMethods.Tick(Handle, (byte)(p1 ? 1 : 0), (byte)(p2 ? 1 : 0));
    }

    public static bool InMiniGame(MiniGameId id, bool inMiniGame)
    {
        return NativeMethods.InMiniGame(id, (byte)(inMiniGame ? 1 : 0)) != 0;
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x10)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x10];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged<Native*> GetInstance;
        public static readonly delegate* unmanaged<MiniGameId, byte, byte> InMiniGame;
        public static readonly delegate* unmanaged[Thiscall]<Native*, byte, byte, void> Tick;
        
        static NativeMethods()
        {
            GetInstance = (delegate* unmanaged<Native*>)HandleHelper.GetProcessHandle(Addresses.Minecraft.GetInstance);
            InMiniGame = (delegate* unmanaged<MiniGameId, byte, byte>)HandleHelper.GetProcessHandle(Addresses.Minecraft.InMiniGame);
            Tick = (delegate* unmanaged[Thiscall]<Native*, byte, byte, void>)HandleHelper.GetProcessHandle(Addresses.Minecraft.Tick);
        }
    }
}