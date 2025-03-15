#pragma once

#include "Hooks/Minecraft/World/Blocks/LeafBlock.h"
#include "Hooks/Minecraft/Client/Renderer/Renderer.h"
#include "Hooks/Minecraft/Client/Renderer/BlockRenderer.h"
#include "Hooks/Minecraft/Client/Renderer/Texture/BufferedImage.h"
#include "Hooks/Minecraft/Client/Renderer/Texture/Texture.h"
#include "Hooks/Minecraft/Client/Renderer/LevelRenderer.h"
#include "Hooks/Minecraft/Client/UI/Scene/UIScene_SettingsListMenu.h"
#include "Hooks/Minecraft/Server/ServerLevel.h"
#include "Hooks/Minecraft/World/Level.h"
#include "Hooks/Minecraft/Client/UI/FUI/Fui.h"

// Registers all hooks
void RegisterHooks();

// Resets all hooks
void ResetHooks();