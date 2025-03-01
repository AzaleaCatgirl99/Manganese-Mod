#include "Hooks.h"

void RegisterHooks()
{
    LeafBlock::RegisterHooks();
    Renderer::RegisterHooks();
    Texture::RegisterHooks();
    ServerLevel::RegisterHooks();
    LevelRenderer::RegisterHooks();
    Level::RegisterHooks();
    UISceneSettingsListMenu::RegisterHooks();
}

void ResetHooks()
{
    LeafBlock::ResetHooks();
    Renderer::ResetHooks();
    Texture::ResetHooks();
    ServerLevel::ResetHooks();
    LevelRenderer::ResetHooks();
    Level::ResetHooks();
    UISceneSettingsListMenu::ResetHooks();
}