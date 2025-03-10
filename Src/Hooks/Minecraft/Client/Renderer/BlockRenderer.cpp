#include "BlockRenderer.h"

// GetLightColor hook
uint64_t BlockRenderer::GetLightColor(BlockRenderer* _this, void* block, void* levelSource, void* blockPos)
{
    /*return 255 << 16 | 255 << 8 | 255;*/
    return BlockRenderer_GetLightColor(_this, block, levelSource, blockPos);
}