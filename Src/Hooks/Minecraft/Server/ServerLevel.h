#pragma once
#include "Hooks/HookIncludes.h"

class ServerLevel
{
public:
	// Hook functions
	static ServerLevel* Constructor(ServerLevel* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5);
};

// Original functions
CREATE_FUNC(ServerLevel_Constructor, 0x14090e0e0, ServerLevel*, ServerLevel* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5);