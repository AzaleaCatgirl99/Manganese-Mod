#pragma once
#include "DefaultHooks.h"

class ServerLevel
{
public:
	static void RegisterHooks();

	static void ResetHooks();
};

void* getServerLevel_this();