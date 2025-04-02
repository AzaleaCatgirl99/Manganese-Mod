#pragma once
#include "Hooks/HookIncludes.h"

class EnchantmentHelper
{
public:
	static int getRespiration(void* livingEntity);
};

CREATE_FUNC(EnchantmentHelper_GetRespiration, 0x140255080, int, void* livingEntity);