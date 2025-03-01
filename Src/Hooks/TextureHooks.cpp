#include "TextureHooks.h"

SafetyHookInline g_CrispBlend_hook{};

void* TrueCrispBlend = GetProcessHandle(0x140934550);

int CrispBlendHook(int* one, int* two)
{
    if (MipmapType::get() == 2) {
        return JavaBlend(JavaBlend((int)one, (int)two), JavaBlend((int)two, (int)one));
    }
    else {
        return g_CrispBlend_hook.call<int>(one, two);
    }
}

void Texture::RegisterHooks()
{
    g_CrispBlend_hook = safetyhook::create_inline(TrueCrispBlend, CrispBlendHook);
}

void Texture::ResetHooks()
{
    g_CrispBlend_hook.reset();
}