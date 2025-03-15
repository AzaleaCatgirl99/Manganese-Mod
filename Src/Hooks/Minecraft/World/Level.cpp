#include "Level.h"

int Level::GetFogDistance(Level* _this)
{
	int distance = Level_GetFogDistance(_this)/16;

	switch (FogMode::get()) {
	case 1:
		if (RenderDistance::get() > 18)
			distance = RenderDistance::get() - 2;
		break;
	case 2:
		distance = RenderDistance::get() - 2;
		if (RenderDistance::get() < 10)
			distance += 2;
		break;
	}

	return distance * 16;
}

int Level::GetCloudHeight(Level* _this)
{
	return CloudHeight::get();
}