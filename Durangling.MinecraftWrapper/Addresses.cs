namespace Minecraft;

// Addresses of methods from Minecraft: Xbox One Edition 1.61.1924.0
internal static class Addresses
{
    public static class Minecraft
    {
        public const long GetInstance = 0x1408727a0;
        public const long InMiniGame = 0x140873320;
        public const long Tick = 0x1408fae20;
    }

    public static class MinecraftApp
    {
        public const long Constructor = 0x140763ec0;
        public const long HandleDlc = 0x140790e90;
        public const long SetGameMode = 0x1407af500;
        public const long GetNextTip = 0x14078d040;
    }

    public static class Block
    {
        public const long Destructor = 0x14013cf90;
        public const long IsDebugInformationVisible = 0x140051660;
        public const long GetMiningSpeed = 0x1401771b0;
        public const long SetLuminescence = 0x1401a5e50;
    }

    public static class Texture
    {
        public const long CrispBlend = 0x140934550;
    }

    public static class Renderer
    {
        public const long StateSetFogEnable = 0x1400eaff0;
    }
}