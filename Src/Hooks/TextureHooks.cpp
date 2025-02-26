#include "TextureHooks.h"

SafetyHookInline g_CrispBlend_hook{};

void* TrueCrispBlend = GetProcessHandle(0x140934550);

int CrispBlendHook(int* one, int* two)
{
    return JavaBlend(JavaBlend((int)one, (int)two), JavaBlend((int)two, (int)one));
}

void AttachTextureHooks()
{
    g_CrispBlend_hook = safetyhook::create_inline(TrueCrispBlend, CrispBlendHook);
}

void DetachTextureHooks()
{
    g_CrispBlend_hook.reset();
}