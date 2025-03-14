#pragma once
#include "Hooks/HookIncludes.h"

class BlockRenderer
{
public:
	// Hook functions
	static void TesselateBlockInWorld(BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6);
	static void TesselateBlockInWorldWithAmbienceOcclusionTexLighting(BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6, float param_7, int param_8);
	static uint64_t GetLightColor(BlockRenderer* _this, void* block, void* levelSource, void* blockPos);
};

// Original functions
CREATE_FUNC(BlockRenderer_TesselateBlockInWorld, 0x140827600, void, BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6);
CREATE_FUNC(BlockRenderer_TesselateBlockInWorldWithAmbienceOcclusionTexLighting, 0x140827f70, void, BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6, float param_7, int param_8);
CREATE_FUNC(BlockRenderer_GetLightColor, 0x1407d3950, uint64_t, BlockRenderer* _this, void* block, void* levelSource, void* blockPos);