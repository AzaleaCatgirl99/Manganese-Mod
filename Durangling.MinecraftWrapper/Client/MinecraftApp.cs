using System.Runtime.InteropServices;
using Minecraft.Client.Dlc;
using Minecraft.Client.MiniGames;
using Minecraft.Interop;

namespace Minecraft.Client;

public unsafe class MinecraftApp(MinecraftApp.Native* handle) : NativeClassWrapper<MinecraftApp.Native>(handle)
{
    public static MinecraftApp Create()
    {
        // not sure if this is the correct way to create objects
        Native* n = (Native*)NativeMemory.AllocZeroed((nuint)sizeof(Native));
        NativeMethods.Constructor(n);
        return new MinecraftApp(n);
    }

    public void HandleDlc(DlcPack.Native* pack)
    {
        NativeMethods.HandleDlc(Handle, pack);
    }

    public void HandleDlc(DlcPack pack) => NativeMethods.HandleDlc(Handle, pack.Handle);

    public void SetGameMode(GameMode gameMode)
    {
        NativeMethods.SetGameMode(Handle, gameMode);
    }

    public int GetNextTip(bool inMiniGame, MiniGameId miniGame)
    {
        return NativeMethods.GetNextTip(Handle, (byte)(inMiniGame ? 1 : 0), miniGame);
    }

    [StructLayout(LayoutKind.Explicit, Pack = 0x1, Size = 0x9ed)]
    public struct Native
    {
        [FieldOffset(0x0)] public fixed byte _Fill[0x9ed];
    }

    public static class NativeMethods
    {
        public static readonly delegate* unmanaged[Thiscall]<Native*, void**> Constructor;
        public static readonly delegate* unmanaged[Thiscall]<Native*, DlcPack.Native*, void> HandleDlc;
        public static readonly delegate* unmanaged[Thiscall]<Native*, GameMode, void> SetGameMode;
        public static readonly delegate* unmanaged[Thiscall]<Native*, byte, MiniGameId, int> GetNextTip;

        static NativeMethods()
        {
            Constructor = (delegate* unmanaged[Thiscall]<Native*, void**>)HandleHelper.GetProcessHandle(Addresses.MinecraftApp.Constructor);
            HandleDlc = (delegate* unmanaged[Thiscall]<Native*, DlcPack.Native*, void>)HandleHelper.GetProcessHandle(Addresses.MinecraftApp.HandleDlc);
            SetGameMode = (delegate* unmanaged[Thiscall]<Native*, GameMode, void>)HandleHelper.GetProcessHandle(Addresses.MinecraftApp.SetGameMode);
            GetNextTip = (delegate* unmanaged[Thiscall]<Native*, byte, MiniGameId, int>)HandleHelper.GetProcessHandle(Addresses.MinecraftApp.GetNextTip);
        }
    }
}