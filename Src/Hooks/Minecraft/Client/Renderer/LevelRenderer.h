#pragma once
#include "Hooks/HookIncludes.h"

class LevelRenderer
{
public:
	static uintptr_t AllChanged_ViewDistance;
	static uintptr_t SetupFog_param_1;

	void AllChanged();

	static void RegisterHooks();

	static void ResetHooks();
};

CREATE_MID_HOOK(LevelRenderer_AllChanged_ViewDistance, AllChanged_ViewDistanceHook);

CREATE_MID_HOOK(GameRenderer_SetupFog_param_1, SetupFog_param_1Hook);

CREATE_FUNC(LevelRenderer_AllChanged, 0x14087d460, void, LevelRenderer* _this);