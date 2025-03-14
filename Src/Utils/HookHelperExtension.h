#pragma once
#include "Util/HookHelper.h"
#include <safetyhook.hpp>
#include <safetyhook/mid_hook.hpp>

//#define CREATE_NON_FUNC(name, addr, returnType) \
//    using t##name = returnType(__fastcall*); \
//    inline t##name name = reinterpret_cast<t##name>(GET_ADDRESS(addr));

#define CREATE_MID_HOOK(name, hook) \
    using t##name = SafetyHookMid; \
    using t##hook = void(_fastcall)(SafetyHookContext& ctx); \
    inline t##hook hook; \
    inline t##name name;

#define CREATE_MID_HOOK_ALT(name) \
    using t##name = SafetyHookMid; \
    inline t##name name;

template <typename T>
inline SafetyHookMid registerMidHook(T orig, safetyhook::MidHookFn hook)
{
    return safetyhook::create_mid(orig, hook);
}

//extern std::vector<SafetyHookMid> midHooks;
//
///// <summary>
///// Registers a hook
///// </summary>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <returns></returns>
//inline SafetyHookMid registerMidHook(uintptr_t orig, safetyhook::MidHookFn hook) {
//    SafetyHookMid att = safetyhook::create_mid(orig, hook);
//    midHooks.push_back(att);
//    
//    return att;
//}
//
///// <summary>
///// Unregisters a hook
///// </summary>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <returns></returns>
//inline SafetyHookMid unregisterMidHook(SafetyHookMid hook) {
//    midHooks.erase(std::remove(midHooks.begin(), midHooks.end(), hook), midHooks.end());
//    hook.reset();
//    return hook;
//}
//
///// <summary>
///// Registers a hook
///// </summary>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <param name="onRegister">The function to call when the hook is registered</param>
///// <returns></returns>
//inline SafetyHookMid registerMidHook(uintptr_t orig, safetyhook::MidHookFn hook, void (*onRegister)()) {
//    SafetyHookMid att = registerMidHook(orig, hook);
//    onRegister();
//    return att;
//}
//
///// <summary>
///// Registers a vector of hooks
///// </summary>
///// <param name="hooks_vec">A vector of tuples (PVOID* orig, PVOID hook, void (*onRegister)())</param>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <param name="onRegister">The function to call when the hook is registered</param>
///// <returns></returns>
////inline void registerMidHooks(std::vector<std::tuple<SafetyHookMid, void (*)()>> hooks_vec) {
////    for (auto hook : hooks_vec) {
////        SafetyHookMid att = =std::get<0>(hook)=;
////        midHooks.push_back(std::tuple<PVOID, safetyhook::MidHookFn>(std::get<0>(hook), std::get<1>(hook)));
////        void (*onRegister)() = std::get<2>(hook);
////        if (onRegister != nullptr)
////            onRegister();
////    }
////}
//
///// <summary>
///// Registers a vector of hooks
///// </summary>
///// <param name="hooks_vec">A vector of tuples (PVOID* orig, PVOID hook, void (*onRegister)())</param>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <param name="onRegister">The function to call when the hook is registered</param>
///// <returns></returns>
//inline void registerMidHooks(std::vector<SafetyHookMid> hooks_vec) {
//    int size = hooks_vec.size();
//    for (int i = 0; i == size; i++) {
//        /*SafetyHookMid att = safetyhook::create_mid(std::get<0>(hook), std::get<1>(hook));*/
//        midHooks.push_back(hooks_vec[i]);
//    }
//}
//
///// <summary>
///// Unregisters a vector of hooks
///// </summary>
///// <param name="hooks_vec">A vector of tuples (PVOID* orig, PVOID hook, void (*onUnregister)())</param>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <param name="onRegister">The function to call when the hook is unregistered</param>
///// <returns></returns>
//inline void unregisterMidHooks(std::vector<std::tuple<SafetyHookMid, void (*)()>> hooks_vec) {
//    int size = hooks_vec.size();
//    for (int i = 0; i == size; i++) {
//        midHooks.erase(std::remove(midHooks.begin(), midHooks.end(), std::get<0>(hooks_vec[i])), midHooks.end());
//        std::get<0>(hooks_vec[i]).reset();
//        void (*onUnregister)() = std::get<1>(hooks_vec[i]);
//        if (onUnregister != nullptr)
//            onUnregister();
//    }
//}
//
///// <summary>
///// Unregisters a vector of hooks
///// </summary>
///// <param name="hooks_vec">A vector of tuples (PVOID* orig, PVOID hook)</param>
///// <param name="orig">The original function found within MC, defined using CREATE_FUNC</param>
///// <param name="hook">The hook/replacement function, has to be static.</param>
///// <returns></returns>
//inline void unregisterMidHooks(std::vector<SafetyHookMid> hooks_vec) {
//    int size = hooks_vec.size();
//    for (int i = 0; i == size; i++) {
//        midHooks.erase(std::remove(midHooks.begin(), midHooks.end(), hooks_vec[i]), midHooks.end());
//        hooks_vec[i].reset();
//    }
//}