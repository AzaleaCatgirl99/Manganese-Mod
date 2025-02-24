#include "Hooks.h"

void AttachHooks()
{
    AttachLeafBlockHooks();
    AttachRendererHooks();
    AttachTextureHooks();
    AttachServerLevelHooks();
    AttachLevelRendererHooks();
}

void DetachHooks()
{
    DetachLeafBlockHooks();
    DetachRendererHooks();
    DetachTextureHooks();
    DetachServerLevelHooks();
    DetachLevelRendererHooks();
}