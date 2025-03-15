#pragma once
#include "Hooks/HookIncludes.h"

class Level
{
public:
	static int GetFogDistance(Level* _this);
	static int GetCloudHeight(Level* _this);
};

CREATE_FUNC(Level_GetFogDistance, 0x1403a6b30, int, Level* _this);
CREATE_FUNC(Level_GetCloudHeight, 0x1403a0a40, int, Level* _this);