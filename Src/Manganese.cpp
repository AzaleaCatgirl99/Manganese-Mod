#include "Framework.h"
#include <iostream>
#include <Psapi.h>
#include "Hooks.h"
#include "Utils/Logger.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AttachHooks();
        break;
    case DLL_PROCESS_DETACH:
        DetachHooks();
        break;
    }
    return TRUE;
}

int main()
{
    Write(Info, "Manganese", "Mod has been durangled by the initalizer.");
}