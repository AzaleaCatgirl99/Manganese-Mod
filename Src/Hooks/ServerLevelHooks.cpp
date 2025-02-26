#include "ServerLevelHooks.h"
#include "DefaultHooks.h"

SafetyHookInline g_ServerLevel_Constructor_hook{};
SafetyHookInline g_Constructor_GetViewDistance_hook{};

void* TrueServerLevel_Constructor = GetProcessHandle(0x14090e0e0);
void* TrueConstructor_GetViewDistance = GetProcessHandle(0x1400f6490);

uint64_t Constructor_GetViewDistanceHook(void* _this)
{
    return g_Constructor_GetViewDistance_hook.call<uint64_t>(_this);
}

void* ServerLevel_ConstructorHook(void* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5)
{
    *(uint64_t*)(Constructor_GetViewDistanceHook(minecraftServer) + 260) = 10;
    return g_ServerLevel_Constructor_hook.call<void*, void*, void*, void*, void*, int*>(_this, minecraftServer, LevelStorage_shared_ptr, levelData, a5);
}

void AttachServerLevelHooks()
{
    g_Constructor_GetViewDistance_hook = safetyhook::create_inline(TrueConstructor_GetViewDistance, Constructor_GetViewDistanceHook);
    g_ServerLevel_Constructor_hook = safetyhook::create_inline(TrueServerLevel_Constructor, ServerLevel_ConstructorHook);
}

void DetachServerLevelHooks()
{
    g_Constructor_GetViewDistance_hook.reset();
    g_ServerLevel_Constructor_hook.reset();
}