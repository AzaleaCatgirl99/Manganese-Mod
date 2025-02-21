using System.Runtime.InteropServices;
using Durangling;
using Minecraft.Client.Renderer.Texture;
using static Manganese.Utils.TextureUtil;

namespace Manganese.Hooks;

using unsafe CrispBlend = delegate* unmanaged<uint, uint, uint>;

public static unsafe class TextureHooks
{
    private static CrispBlend TrueCrispBlend = Texture.NativeMethods.CrispBlend;

    public static void Attach()
    {
        Detour.Attach(TrueCrispBlend, (CrispBlend)(&CrispBlendHook));
    }

    public static void Detach()
    {
        Detour.Detach(TrueCrispBlend, (CrispBlend)(&CrispBlendHook));
    }

    [UnmanagedCallersOnly]
    private static uint CrispBlendHook(uint one, uint two)
    {
        return JavaBlend(JavaBlend(one, two), JavaBlend(two, one));
    }
}
