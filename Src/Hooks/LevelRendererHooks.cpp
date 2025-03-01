#include "LevelRendererHooks.h"

SafetyHookInline g_AllChanged_hook{};
SafetyHookMid g_AllChanged_ViewDistance_hook{};

void* TrueAllChanged = GetProcessHandle(0x14087d460);
uintptr_t TrueAllChanged_ViewDistance = GetProcessHandleAddress(0x14087ce4b);

uintptr_t AllChanged_this;

void AllChanged_ViewDistanceHook(SafetyHookContext& ctx)
{
	ctx.r8 = RenderDistance::get() * 2;
}

void AllChangedHook(uintptr_t _this)
{
	AllChanged_this = _this;
	g_AllChanged_hook.call(_this);
}

void AttachLevelRendererHooks()
{
    g_AllChanged_ViewDistance_hook = safetyhook::create_mid(TrueAllChanged_ViewDistance, AllChanged_ViewDistanceHook);
	g_AllChanged_hook = safetyhook::create_inline(TrueAllChanged, AllChangedHook);
}

void DetachLevelRendererHooks()
{
	g_AllChanged_ViewDistance_hook.reset();
	g_AllChanged_hook.reset();
}

uintptr_t getAllChanged_this()
{
	return AllChanged_this;
}