#include "LevelHelper.h"

namespace LevelHelper {
	void reloadChunks()
	{
		if (Minecraft::GetInstance()->level != nullptr)
			Minecraft::GetInstance()->levelRenderer->AllChanged();
	}
}