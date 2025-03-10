#include "LeafBlock.h"

// IsSolidRender hook; returns the bool value based on the LeavesType setting value
bool LeafBlock::IsSolidRender(void* blockState)
{
    if (LeavesType::get() == 0) {
        return true;
    }
    else {
        return LeafBlock_IsSolidRender(blockState);
    }
}

// ShouldRenderFace hook; returns the bool value based on the LeavesType setting value
bool LeafBlock::ShouldRenderFace(LeafBlock* _this, void* blockState, void* levelSource, void* blockPos, void* direction)
{
    if (LeavesType::get() == 0) {
        return true;
    }
    else {
        return LeafBlock_ShouldRenderFace(_this, blockState, levelSource, blockPos, direction);
    }
}

// SetFancy hook; sets the bool value based on the LeavesType setting value
void LeafBlock::SetFancy(LeafBlock* _this, bool value)
{
    if (LeavesType::get() == 0) {
        LeafBlock_SetFancy(_this, false);
    }
    else if (LeavesType::get() == 2) {
        LeafBlock_SetFancy(_this, true);
    }
    else {
        LeafBlock_SetFancy(_this, value);
    }
}