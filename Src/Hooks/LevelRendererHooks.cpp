#include "LevelRendererHooks.h"
#include "DefaultHooks.h"

SafetyHookInline g_AllChanged_hook{};

void* TrueAllChanged = GetProcessHandle(0x14087cd10);

void AllChangedHook(long* _this, int a)
{
	*(uint64_t*)(_this + 284) = 10;
	g_AllChanged_hook.call(_this, a);
}

void AttachLevelRendererHooks()
{
	g_AllChanged_hook = safetyhook::create_inline(TrueAllChanged, AllChangedHook);
}

void DetachLevelRendererHooks()
{
	g_AllChanged_hook.reset();
}