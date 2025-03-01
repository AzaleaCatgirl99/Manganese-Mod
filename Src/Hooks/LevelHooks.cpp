#include "LevelHooks.h"

SafetyHookInline g_FUN_14039dc10_hook{};

void* TrueFUN_14039dc10 = GetProcessHandle(0x14039dc10);

void* levelInstance;

void FUN_14039dc10Hook(void* _this, uintptr_t* a, int* b)
{
	levelInstance = _this;

	g_FUN_14039dc10_hook.call(_this, a, b);
}

void Level::RegisterHooks()
{
	g_FUN_14039dc10_hook = safetyhook::create_inline(TrueFUN_14039dc10, FUN_14039dc10Hook);
}

void Level::ResetHooks()
{
	g_FUN_14039dc10_hook.reset();
	levelInstance = nullptr;
}

void* getLevelInstance()
{
	return levelInstance;
}