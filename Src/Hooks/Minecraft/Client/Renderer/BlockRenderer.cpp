#include "BlockRenderer.h"

void BlockRenderer::TesselateBlockInWorld(BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6)
{
    return BlockRenderer_TesselateBlockInWorld(_this, blockState, blockPos, param_4, param_5, param_6);
}

void BlockRenderer::TesselateBlockInWorldWithAmbienceOcclusionTexLighting(BlockRenderer* _this, void* blockState, void* blockPos, int param_4, float param_5, float param_6, float param_7, int param_8)
{
    if (SmoothLighting::get() == false) {
        BlockRenderer::TesselateBlockInWorld(_this, blockState, blockPos, param_4, param_5, param_6);
        return;
    }
    BlockRenderer_TesselateBlockInWorldWithAmbienceOcclusionTexLighting(_this, blockState, blockPos, param_4, param_5, param_6, param_7, param_8);
}

// GetLightColor hook
uint64_t BlockRenderer::GetLightColor(BlockRenderer* _this, void* block, void* levelSource, void* blockPos)
{
    return BlockRenderer_GetLightColor(_this, block, levelSource, blockPos);
}