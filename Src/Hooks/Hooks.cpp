#include "Hooks.h"
#include "Utils/HookHelperExtension.h"
#include "Framework.h"

// List of all current hooks
std::vector<std::tuple<PVOID*, PVOID>> hooks;

/*
* Registers all of Manganese's hooks
*/
void RegisterHooks()
{
    registerHook(&(PVOID&)LeafBlock_IsSolidRender, &LeafBlock::IsSolidRender);
    registerHook(&(PVOID&)LeafBlock_ShouldRenderFace, &LeafBlock::ShouldRenderFace);
    registerHook(&(PVOID&)LeafBlock_SetFancy, &LeafBlock::SetFancy);
    
    registerHook(&(PVOID&)BlockRenderer_TesselateBlockInWorldWithAmbienceOcclusionTexLighting, &BlockRenderer::TesselateBlockInWorldWithAmbienceOcclusionTexLighting);
    /*registerHook(&(PVOID&)BlockRenderer_GetLightColor, &BlockRenderer::GetLightColor);*/

    registerHook(&(PVOID&)Renderer_StateSetFogEnable, &Renderer::StateSetFogEnable);
    registerHook(&(PVOID&)Renderer_StateSetLightingEnable, &Renderer::StateSetLightingEnable);
    registerHook(&(PVOID&)Renderer_TextureSetTextureLevels, &Renderer::TextureSetTextureLevels);
    registerHook(&(PVOID&)Renderer_UpdateFogState, &Renderer::updateFogState);
    /*registerHook(&(PVOID&)Renderer_C, &Renderer::C);
    registerHook(&(PVOID&)Renderer_Q, &Renderer::Q);
    registerHook(&(PVOID&)Renderer_A, &Renderer::A);
    registerHook(&(PVOID&)Renderer_S, &Renderer::S);*/

    registerHook(&(PVOID&)ServerLevel_Constructor, &ServerLevel::Constructor);

    registerHook(&(PVOID&)Level_GetFogDistance, &Level::GetFogDistance);
    registerHook(&(PVOID&)Level_GetCloudHeight, &Level::GetCloudHeight);

    registerHook(&(PVOID&)BufferedImage_IsMipmapDisabled, &BufferedImage::IsMipmapDisabled);

    registerHook(&(PVOID&)Texture_CrispBlend, &Texture::CrispBlend);
    registerHook(&(PVOID&)Texture_TransferFromImage, &Texture::TransferFromImage);

    /*registerHook(&(PVOID&)Fui_GetResolution, &Fui::GetResolution);*/

    LevelRenderer::RegisterHooks();

    registerHook(&(PVOID&)UIScene_SettingsListMenu_Init, &UIScene_SettingsListMenu::Init);
    registerHook(&(PVOID&)UIScene_SettingsListMenu_HandleSliderElementMove, &UIScene_SettingsListMenu::HandleSliderElementMove);
    registerHook(&(PVOID&)UIScene_SettingsListMenu_HandleCheckboxElementToggled, &UIScene_SettingsListMenu::HandleCheckboxElementToggled);
    
    /*registerHook(&(PVOID&)GameRenderer_SetupFog, &GameRenderer::SetupFog);*/
}

/*
* Resets all of Manganese's hooks
*/
void ResetHooks()
{
    unregisterHooks(hooks);

    LevelRenderer::ResetHooks();
}