#pragma once
#include "Hooks/HookIncludes.h"

class UIString
{
public:
	UIString();
	UIString(wchar_t* string);
};

// Original functions
CREATE_FUNC(UIString_Constructor_A, 0x1407724d0, UIString*, UIString* _this);
CREATE_FUNC(UIString_Constructor_B, 0x140772230, UIString*, UIString* _this, wchar_t* string);