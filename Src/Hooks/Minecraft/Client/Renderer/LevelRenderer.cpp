#include "LevelRenderer.h"

SafetyHookMid g_AllChanged_ViewDistance_hook{};

uintptr_t TrueAllChanged_ViewDistance = GetProcessHandleAddress(0x14087ce4b);

void AllChanged_ViewDistanceHook(SafetyHookContext& ctx)
{
	ctx.r8 = RenderDistance::get() * 2;
}

void LevelRenderer::RegisterHooks()
{
    g_AllChanged_ViewDistance_hook = safetyhook::create_mid(TrueAllChanged_ViewDistance, AllChanged_ViewDistanceHook);
}

void LevelRenderer::ResetHooks()
{
	g_AllChanged_ViewDistance_hook.reset();
}