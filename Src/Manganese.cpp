#include "Framework.h"
#include "Hooks/Hooks.h"
#include "Manganese.h"
#include "Utils/LanternLoggerExtension.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/*
* Initializes Manganese and spits out completetion in the log
*/
Manganese* Initialize()
{
    std::string funcName = "Manganese Initializer";
    M_LOGW_C(funcName.c_str(), MAGENTA, L"Mod has been initialized by the durangler.");

    // This was added on International Women's Day, 3/8/2025
    M_LOGW_C(funcName.c_str(), MAGENTA, L"Also women are cool! :3"); // Women are super cool :3
    return new Manganese();
}