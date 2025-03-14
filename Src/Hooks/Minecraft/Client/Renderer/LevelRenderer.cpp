#include "LevelRenderer.h"
#include "Hooks/Minecraft/Client/Minecraft.h"

SafetyHookMid g_AllChanged_ViewDistance_hook{};
SafetyHookMid g_AAA_hook{};
SafetyHookMid g_BBB_hook{};

//uintptr_t TrueAllChanged_ViewDistance = GET_ADDRESS(0x14087ce4b);
uintptr_t TrueAAA = GET_ADDRESS(0x1400e8d34);
uintptr_t TrueBBB = GET_ADDRESS(0x1400e8655);

std::vector<SafetyHookMid> midHooks;

uintptr_t LevelRenderer::AllChanged_ViewDistance = GET_ADDRESS(0x14087ce4b);

void LevelRenderer::AllChanged()
{
	LevelRenderer_AllChanged(this);
}

void AllChanged_ViewDistanceHook(SafetyHookContext& ctx)
{
	ctx.r8 = RenderDistance::get() * 2;
}

void AAAHook(SafetyHookContext& ctx)
{
	ctx.rax = 128000;
}

void BBBHook(SafetyHookContext& ctx)
{
	ctx.r8 = 128;
}

void LevelRenderer::RegisterHooks()
{
	LevelRenderer_AllChanged_ViewDistance = registerMidHook(LevelRenderer::AllChanged_ViewDistance, AllChanged_ViewDistanceHook);
	/*g_BBB_hook = safetyhook::create_mid(TrueBBB, BBBHook);
	g_AAA_hook = safetyhook::create_mid(TrueAAA, AAAHook);*/
}

void LevelRenderer::ResetHooks()
{
	LevelRenderer_AllChanged_ViewDistance.reset();
	/*g_BBB_hook.reset();
	g_AAA_hook.reset();*/
}