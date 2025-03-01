#include "LeafBlockHooks.h"

SafetyHookInline g_isSolidRender_hook{};
SafetyHookInline g_shouldRenderFace_hook{};
SafetyHookInline g_setFancy_hook{};

void* TrueIsSolidRender = GetProcessHandle(0x1403bc360);
void* TrueShouldRenderFace = GetProcessHandle(0x1403fac50);
void* TrueSetFancy = GetProcessHandle(0x1403f7550);

bool IsSolidRenderHook(long* _this)
{
    if (LeavesType::get() == 0) {
        return true;
    } else {
        return g_isSolidRender_hook.call<bool>(_this);
    }
}

bool ShouldRenderFaceHook(long* _this, long* a, long* b, long* c, long* d)
{
    if (LeavesType::get() == 0) {
        return true;
    }
    else {
        return g_shouldRenderFace_hook.call<bool>(_this, a, b, c, d);
    }
}

void SetFancyHook(long* _this, bool value)
{
    if (LeavesType::get() == 0) {
        g_setFancy_hook.call(_this, false);
    }
    else if (LeavesType::get() == 2) {
        g_setFancy_hook.call(_this, true);
    }
    else {
        g_setFancy_hook.call(_this, value);
    }
}

void LeafBlock::RegisterHooks()
{
    g_isSolidRender_hook = safetyhook::create_inline(TrueIsSolidRender, IsSolidRenderHook);
    g_shouldRenderFace_hook = safetyhook::create_inline(TrueShouldRenderFace, ShouldRenderFaceHook);
    g_setFancy_hook = safetyhook::create_inline(TrueSetFancy, SetFancyHook);
}

void LeafBlock::ResetHooks()
{
    g_isSolidRender_hook.reset();
    g_shouldRenderFace_hook.reset();
    g_setFancy_hook.reset();
}