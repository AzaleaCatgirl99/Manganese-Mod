#pragma once
#include <cstdint>

void* GetProcessHandle(uintptr_t address);

uintptr_t GetProcessHandleAddress(uintptr_t address);

wchar_t* GetProcessHandleAddressWchar(uintptr_t address);