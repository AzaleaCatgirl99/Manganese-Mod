#pragma once
#include "Hooks/HookIncludes.h"
#include "Hooks/Minecraft/Core/FloatBuffer.h"

class GameRenderer
{
public:
	/*VTable vtable;
	void* local_c0;
	void* entity[16];
	void* livingEntity;
	void* local_78;*/

	// Hook functions
	static void SetupFog(GameRenderer* _this, int param_2, float param_3);
	static void RenderEyePass(GameRenderer* _this, int param_1, float param_2, void* param_3, bool param_4);
	static void SetupCamera(GameRenderer* _this, int param_2, float param_3);
	
	static void getCamera();
	void resetFogColor(bool val);
	FloatBuffer* getBuffer(float one, float two, float three, float four);
};

// Original functions
CREATE_FUNC(GameRenderer_SetupFog, 0x1408eb630, void, GameRenderer* _this, int param_2, float param_3);
CREATE_FUNC(GameRenderer_RenderEyePass, 0x1408c9200, void, GameRenderer* _this, int param_1, float param_2, void* param_3, bool param_4);
CREATE_FUNC(GameRenderer_SetupCamera, 0x1408ea280, void, GameRenderer* _this, int param_2, float param_3);
CREATE_FUNC(GameRenderer_GetBuffer, 0x1408932b0, FloatBuffer*, GameRenderer* _this, float one, float two, float three, float four);

CREATE_FUNC(GameRenderer_GetCamera, 0x140893410, void);
CREATE_FUNC(GameRenderer_ResetFogColor, 0x1408dd3f0, void, GameRenderer* _this, bool val);