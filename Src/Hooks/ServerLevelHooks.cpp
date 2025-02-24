#include "ServerLevelHooks.h"
#include "DefaultHooks.h"

SafetyHookInline g_Constructor_hook{};
SafetyHookInline g_GetViewDistance_hook{};

void* TrueConstructor = GetProcessHandle(0x14090e0e0);
void* TrueGetViewDistance = GetProcessHandle(0x1400f6490);

uint64_t GetViewDistanceHook(void* _this)
{
    return g_GetViewDistance_hook.call<uint64_t>(_this);
}

void* ConstructorHook(void* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5)
{
    *(uint64_t*)(GetViewDistanceHook(minecraftServer) + 260) = 10;
    return g_Constructor_hook.call<void*, void*, void*, void*, void*, int*>(_this, minecraftServer, LevelStorage_shared_ptr, levelData, a5);
}

void AttachServerLevelHooks()
{
    g_GetViewDistance_hook = safetyhook::create_inline(TrueGetViewDistance, GetViewDistanceHook);
    g_Constructor_hook = safetyhook::create_inline(TrueConstructor, ConstructorHook);
}

void DetachServerLevelHooks()
{
    g_GetViewDistance_hook.reset();
    g_Constructor_hook.reset();
}