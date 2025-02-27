#include "HandleHelper.h"
#include "../Framework.h"

void* GetProcessHandle(uintptr_t address)
{
    return (void*)((char*)GetModuleHandle(nullptr) + (address - 0x140000000));
}

uintptr_t GetProcessHandleAddress(uintptr_t address)
{
    return ((uintptr_t)GetModuleHandle(nullptr) + (address - 0x140000000));
}