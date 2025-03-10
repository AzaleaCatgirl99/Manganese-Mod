#pragma once
#include "Hooks/HookIncludes.h"
#include "Utils/TextureHelper.h"
#include "BufferedImage.h"

class Texture
{
public:
	// Hook functions
	static int CrispBlend(int one, int two);
	static void TransferFromImage(Texture* _this, BufferedImage* bufferedImage);
};

// Original functions
CREATE_FUNC(Texture_CrispBlend, 0x140934550, int, int one, int two);
CREATE_FUNC(Texture_TransferFromImage, 0x140991cb0, void, Texture* _this, BufferedImage* bufferedImage);