#include "Hooks.h"

void AttachHooks()
{
    AttachLeafBlockHooks();
    AttachRendererHooks();
    AttachTextureHooks();
    AttachServerLevelHooks();
    AttachLevelRendererHooks();
    /*AttachUIScene_SettingsListMenuHooks();*/
}

void DetachHooks()
{
    DetachLeafBlockHooks();
    DetachRendererHooks();
    DetachTextureHooks();
    DetachServerLevelHooks();
    DetachLevelRendererHooks();
    /*DetachUIScene_SettingsListMenuHooks();*/
}