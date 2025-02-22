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
        public const long StateSetLightEnable = 0x1400eb290;
        public const long SetMipmapStateUniversal = 0x1400ec440;
        public const long SomethingWithBanners = 0x1400eb630;
        public const long Q = 0x140092990; // TODO Figure out what this does

        public const long C = 0x1400eb020;
        //public const long X = 0x1400eadf0;
        //public const long X = 0x1400eabc0;
        public const long X = 0x1400eab10;
        public const long V = 0x1400ea890;
    }

    public static class LeafBlock
    {
        public const long IsSolidRender = 0x1403bc360;
        public const long ShouldRenderFace = 0x1403fac50;
        public const long SetFancy = 0x1403f7550;

        // List of unknown functions

        //public const long B = 0x1403afbf0;
        //public const long B = 0x140169d90;
        //public const long A = 0x14017ae60;
        //public const long A = 0x140186fb0;
        //public const long A = 0x1401771b0;
        //public const long A = 0x1401874e0;
        //public const long A = 0x140142b70;
        //public const long A = 0x140171690;
    }

    public static class LevelRenderer
    {
        public const long Z = 0x1408a2cf0;
        public const long H = 0x1408897a0;
        public const long F = 0x14089a050;
        public const long S = 0x14087f390;

        public const long GetViewDistance = 0x1400f6490;
    }

    public static class ServerLevel
    {
        public const long Constructor = 0x14090e0e0;
        //public const long GetViewDistance = 0x1400f6490;
        public const long GetViewDistance = 0x14090e48c;
    }
}