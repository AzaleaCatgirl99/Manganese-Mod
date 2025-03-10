#pragma once
#include "Hooks/HookIncludes.h"

class BlockRenderer
{
public:
	// Hook functions
	static uint64_t GetLightColor(BlockRenderer* _this, void* block, void* levelSource, void* blockPos);
};

// Original functions
CREATE_FUNC(BlockRenderer_GetLightColor, 0x1407d3950, uint64_t, BlockRenderer* _this, void* block, void* levelSource, void* blockPos);