using Durangling.Modding;
using Manganese.Hooks;

namespace Manganese;

public class Manganese : Mod
{
    public Manganese() 
        : base(new ModDetails("manganese", "Manganese", new Version(0, 0, 1)))
    {
    }

    protected override void AttachHooks()
    {
        TextureHooks.Attach();
        RendererHooks.Attach();
        BlockHooks.Attach();
    }

    protected override void DetachHooks()
    {
        TextureHooks.Detach();
        RendererHooks.Detach();
        BlockHooks.Detach();
    }
}