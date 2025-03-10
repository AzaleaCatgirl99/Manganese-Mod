#pragma once
#include "Hooks/HookIncludes.h"

class BufferedImage
{
public:
	// Hook functions
	static bool IsMipmapDisabled(BufferedImage* _this);
};

// Original functions
CREATE_FUNC(BufferedImage_IsMipmapDisabled, 0x14004e160, bool, BufferedImage* _this);