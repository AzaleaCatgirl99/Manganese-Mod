#include "Hooks.h"

void AttachHooks()
{
    AttachLeafBlockHooks();
    AttachRendererHooks();
    AttachTextureHooks();
}

void DetachHooks()
{
    DetachLeafBlockHooks();
    DetachRendererHooks();
    DetachTextureHooks();
}