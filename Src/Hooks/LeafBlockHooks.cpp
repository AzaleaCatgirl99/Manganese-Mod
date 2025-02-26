#include "LeafBlockHooks.h"

SafetyHookInline g_isSolidRender_hook{};
SafetyHookInline g_shouldRenderFace_hook{};
SafetyHookInline g_setFancy_hook{};

void* TrueIsSolidRender = GetProcessHandle(0x1403bc360);
void* TrueShouldRenderFace = GetProcessHandle(0x1403fac50);
void* TrueSetFancy = GetProcessHandle(0x1403f7550);

bool IsSolidRenderHook(long* _this)
{
    return true;
}

bool ShouldRenderFaceHook(long* _this, long* a, long* b, long* c, long* d)
{
    return true;
}

void SetFancyHook(long* _this, char* value)
{
    g_setFancy_hook.call(_this, '\0');
}

void AttachLeafBlockHooks()
{
    g_isSolidRender_hook = safetyhook::create_inline(TrueIsSolidRender, IsSolidRenderHook);
    g_shouldRenderFace_hook = safetyhook::create_inline(TrueShouldRenderFace, ShouldRenderFaceHook);
    g_setFancy_hook = safetyhook::create_inline(TrueSetFancy, SetFancyHook);
}

void DetachLeafBlockHooks()
{
    g_isSolidRender_hook.reset();
    g_shouldRenderFace_hook.reset();
    g_setFancy_hook.reset();
}