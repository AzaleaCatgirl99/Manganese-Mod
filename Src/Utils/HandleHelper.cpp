#include "HandleHelper.h"
#include "../../pch.h"

void* GetProcessHandle(uintptr_t address)
{
    return (void*)((char*)GetModuleHandle(nullptr) + (address - 0x140000000));
}

uint8_t GetProcessHandleAddress(uint8_t address)
{
    return ((uint8_t)GetModuleHandle(nullptr) + (address - 0x140000000));
}
