#include "RendererHooks.h"

SafetyHookInline g_StateSetFogEnable_hook{};
SafetyHookInline g_StateSetLightEnable_hook{};
SafetyHookInline g_StateSetMipmapEnable_hook{};
SafetyHookInline g_SomethingWithBanners_hook{};
SafetyHookInline g_Q_hook{};
SafetyHookInline g_C_hook{};
SafetyHookInline g_X_hook{};
SafetyHookInline g_V_hook{};

void* TrueStateSetFogEnable = GetProcessHandle(0x1400eaff0);
void* TrueStateSetLightEnable = GetProcessHandle(0x1400eb290);
void* TrueStateSetMipmapEnable = GetProcessHandle(0x1400ec440);
void* TrueSomethingWithBanners = GetProcessHandle(0x1400eb630);
void* TrueQ = GetProcessHandle(0x140092990); // TODO Figure out what this does
void* TrueC = GetProcessHandle(0x1400eb020);
//void* TrueX = GetProcessHandle(0x1400eadf0);
//void* TrueX = GetProcessHandle(0x1400eabc0);
void* TrueX = GetProcessHandle(0x1400eab10);
void* TrueV = GetProcessHandle(0x1400ea890);



void StateSetFogEnableHook(long* _this, bool* value)
{
    g_StateSetFogEnable_hook.call(_this, false);
}

void StateSetLightEnableHook(long* _this, bool* value)
{
    g_StateSetLightEnable_hook.call(_this, value);
}

void StateSetMipmapEnableHook(long* _this, bool* value)
{
    g_StateSetMipmapEnable_hook.call(_this, false);
}

void SomethingWithBannersHook(long* _this, int* value)
{
    g_SomethingWithBanners_hook.call(_this, value);
}

int QHook(long* _this, int* q)
{
    return 1;
}

void CHook(long* _this, bool* value)
{
    g_C_hook.call(_this, false);
}

void XHook(long* _this, char* value)
{
    g_X_hook.call(_this, value);
}

void VHook(long* _this, char* a, char* b)
{
    g_V_hook.call(_this, a, b);
}

void AttachRendererHooks()
{
    g_StateSetFogEnable_hook = safetyhook::create_inline(TrueStateSetFogEnable, StateSetFogEnableHook);
    g_StateSetLightEnable_hook = safetyhook::create_inline(TrueStateSetLightEnable, StateSetLightEnableHook);
    g_StateSetMipmapEnable_hook = safetyhook::create_inline(TrueStateSetMipmapEnable, StateSetMipmapEnableHook);
    g_SomethingWithBanners_hook = safetyhook::create_inline(TrueSomethingWithBanners, SomethingWithBannersHook);
    g_Q_hook = safetyhook::create_inline(TrueQ, QHook);
    g_C_hook = safetyhook::create_inline(TrueC, CHook);
    g_X_hook = safetyhook::create_inline(TrueX, XHook);
    g_V_hook = safetyhook::create_inline(TrueV, VHook);
}

void DetachRendererHooks()
{
    g_StateSetFogEnable_hook.reset();
    g_StateSetLightEnable_hook.reset();
    g_StateSetMipmapEnable_hook.reset();
    g_SomethingWithBanners_hook.reset();
    g_Q_hook.reset();
    g_C_hook.reset();
    g_X_hook.reset();
    g_V_hook.reset();
}