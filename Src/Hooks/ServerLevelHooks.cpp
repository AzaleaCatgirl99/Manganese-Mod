#include "ServerLevelHooks.h"

SafetyHookInline g_ServerLevel_Constructor_hook{};

void* TrueServerLevel_Constructor = GetProcessHandle(0x14090e0e0);
uintptr_t TrueConstructor_GetViewDistance = GetProcessHandleAddress(0x1400f6490);

void* ServerLevel_this = nullptr;

void* ServerLevel_ConstructorHook(void* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5)
{
    if (_this != nullptr) {
        ServerLevel_this = _this;
    }
    *(uint64_t*)(Call<uint64_t, void*>(TrueConstructor_GetViewDistance, minecraftServer) + 260) = RenderDistance::get();
    return g_ServerLevel_Constructor_hook.call<void*, void*, void*, void*, void*, int*>(_this, minecraftServer, LevelStorage_shared_ptr, levelData, a5);
}

void ServerLevel::RegisterHooks()
{
    g_ServerLevel_Constructor_hook = safetyhook::create_inline(TrueServerLevel_Constructor, ServerLevel_ConstructorHook);
}

void ServerLevel::ResetHooks()
{
    g_ServerLevel_Constructor_hook.reset();
    ServerLevel_this = nullptr;
}

void* getServerLevel_this()
{
    return ServerLevel_this;
}