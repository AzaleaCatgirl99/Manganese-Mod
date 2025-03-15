#pragma once
#include "Hooks/HookIncludes.h"

class Fui
{
public:
	static int GetResolution(Fui* _this);
};

// Original functions
CREATE_FUNC(Fui_GetResolution, 0x1403ad4d0, int, Fui* _this);