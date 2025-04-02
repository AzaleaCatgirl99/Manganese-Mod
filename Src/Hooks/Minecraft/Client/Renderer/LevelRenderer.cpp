#include "LevelRenderer.h"
#include "Hooks/Minecraft/Client/Minecraft.h"

SafetyHookMid g_AllChanged_ViewDistance_hook{};
SafetyHookMid g_AAA_hook{};
SafetyHookMid g_BBB_hook{};

//uintptr_t TrueAllChanged_ViewDistance = GET_ADDRESS(0x14087ce4b);
uintptr_t TrueAAA = GET_ADDRESS(0x1400e8d34);
uintptr_t TrueBBB = GET_ADDRESS(0x1400e8655);
uintptr_t LevelRenderer::SetupFog_param_1 = GET_ADDRESS(0x1408eb8b5);

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

//void SetupFog_param_1Hook(SafetyHookContext& ctx)
//{
//	/*int value = FogMode::get() == 1 ? 0 : -1;*/
//	ctx.rax = value;
//}

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
	/*GameRenderer_SetupFog_param_1 = registerMidHook(LevelRenderer::SetupFog_param_1, SetupFog_param_1Hook);*/
	/*g_BBB_hook = safetyhook::create_mid(TrueBBB, BBBHook);
	g_AAA_hook = safetyhook::create_mid(TrueAAA, AAAHook);*/
}

void LevelRenderer::ResetHooks()
{
	LevelRenderer_AllChanged_ViewDistance.reset();
	/*GameRenderer_SetupFog_param_1.reset();*/
	/*g_BBB_hook.reset();
	g_AAA_hook.reset();*/
}