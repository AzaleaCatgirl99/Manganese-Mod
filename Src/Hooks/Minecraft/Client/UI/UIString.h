#pragma once
#include "Hooks/HookIncludes.h"

class UIString
{
public:
	static UIString* _UIString(uintptr_t* unknownOne, wchar_t* unknownTwo);
};

// Original functions
CREATE_FUNC(UIString_UIString, 0x140772230, UIString*, uintptr_t* unknownOne, wchar_t* unknownTwo);