#pragma once
#include "DefaultHooks.h"

class Level
{
public:
	static void RegisterHooks();

	static void ResetHooks();
};

void* getLevelInstance();