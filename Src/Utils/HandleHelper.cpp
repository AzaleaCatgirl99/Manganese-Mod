#include "HandleHelper.h"
#include "../../pch.h"

void* GetProcessHandle(uintptr_t address)
{
    return (void*)((char*)GetModuleHandle(nullptr) + (address - 0x140000000));
}