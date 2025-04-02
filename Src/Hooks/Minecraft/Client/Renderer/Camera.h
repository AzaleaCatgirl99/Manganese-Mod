#pragma once
#include "Hooks/HookIncludes.h"
#include "Hooks/Minecraft/World/Level.h"
#include "Hooks/Minecraft/World/Entities/Entity.h"

class Camera
{
public:
	// Hook functions
	static void* getBlockAt(Level* level, Entity* entity, float param_3);
};

// Original functions
CREATE_FUNC(Camera_GetBlockAt, 0x1407d0790, void*, Level* level, Entity* entity, float param_3);