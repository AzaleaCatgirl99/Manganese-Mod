#include "Hooks.h"

void AttachHooks()
{
    AttachLeafBlockHooks();
    AttachRendererHooks();
    AttachTextureHooks();
    AttachServerLevelHooks();
    AttachLevelRendererHooks();
    AttachLevelHooks();
    AttachUIScene_SettingsListMenuHooks();
}

void DetachHooks()
{
    DetachLeafBlockHooks();
    DetachRendererHooks();
    DetachTextureHooks();
    DetachServerLevelHooks();
    DetachLevelRendererHooks();
    DetachLevelHooks();
    DetachUIScene_SettingsListMenuHooks();
}