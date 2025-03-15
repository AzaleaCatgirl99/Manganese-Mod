#pragma once
#include "Hooks/HookIncludes.h"

class Renderer
{
public:
	// Hook functions
	static void StateSetFogEnable(Renderer* _this, bool value);
	static void StateSetLightingEnable(Renderer* _this, bool value);
	static void TextureSetTextureLevels(Renderer* _this, int value);
	static void C(Renderer* _this, int value); // TODO figure out this function's actual name
	static void Q(Renderer* _this, int a, bool value); // TODO figure out this function's actual name
	static void A(Renderer* _this, int value); // TODO figure out this function's actual name

	static void S(Renderer* _this, float param_2, float param_3);
};

// Original functions
CREATE_FUNC(Renderer_StateSetFogEnable, 0x1400eaff0, void, Renderer* _this, bool value);
CREATE_FUNC(Renderer_StateSetLightingEnable, 0x1400eb290, void, Renderer* _this, bool value);
CREATE_FUNC(Renderer_TextureSetTextureLevels, 0x1400ec440, void, Renderer* _this, int value);
CREATE_FUNC(Renderer_C, 0x1400eb040, void, Renderer* _this, int value); // TODO figure out this function's actual name 0x1400eb020  0x1400eb040   0x1400eb070
CREATE_FUNC(Renderer_Q, 0x1400ebb90, void, Renderer* _this, int a, bool value);
CREATE_FUNC(Renderer_A, 0x1400eb070, void, Renderer* _this, int value);// 0x1400eb0a0

CREATE_FUNC(Renderer_S, 0x1400eaf70, void, Renderer* _this, float param_2, float param_3);