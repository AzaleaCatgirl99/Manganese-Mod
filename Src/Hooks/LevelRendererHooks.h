#pragma once
#include "DefaultHooks.h"

class LevelRenderer
{
public:
	static void RegisterHooks();

	static void ResetHooks();
};

uintptr_t getAllChanged_this();