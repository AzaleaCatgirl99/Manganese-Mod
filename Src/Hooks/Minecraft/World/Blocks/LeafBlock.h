#pragma once
#include "Hooks/HookIncludes.h"

class LeafBlock
{
public:
	// Hook functions
	static bool IsSolidRender(void* blockState);
	static bool ShouldRenderFace(LeafBlock* _this, void* blockState, void* levelSource, void* blockPos, void* direction);
	static void SetFancy(LeafBlock* _this, bool value);
};

// Original functions
CREATE_FUNC(LeafBlock_IsSolidRender, 0x1403bc360, bool, void* blockState);
CREATE_FUNC(LeafBlock_ShouldRenderFace, 0x1403fac50, bool, LeafBlock* _this, void* blockState, void* levelSource, void* blockPos, void* direction);
CREATE_FUNC(LeafBlock_SetFancy, 0x1403f7550, void, LeafBlock* _this, bool value);