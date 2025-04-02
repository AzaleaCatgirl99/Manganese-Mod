#pragma once
#include "Hooks/HookIncludes.h"
#include "Helper/RendererHelper.h"

namespace GlStateManager
{
	// Hook functions
	void enableFog();
	void disableFog();
	void fogMode(int mode);
	void fogStart(float value);
	void fogEnd(float value);
	void fogDensity(float value);
	void enableColorMaterial();
	void disableColorMaterial();
	void colorMaterial(int face, int mode);
	void color4f(float red, float green, float blue, float alpha);
	void normal3f(float f, float g, float h);
	void glFog(int pname, FloatBuffer* floatBuffer);
	void pushMatrix();
	void popMatrix();
}

// Original functions
//CREATE_FUNC(GlStateManager_FogMode, 0x140fe7a98 + 0x2a0, void, int rendererPtr, int mode); //  0x140fe7d38    
//CREATE_FUNC(GlStateManager_FogStart, 0x140fcf6c8, void, float value);
//CREATE_FUNC(GlStateManager_FogEnd, 0x140fcf6b8 + 0x14, void, float value); // 0x140fcf6cc
//CREATE_FUNC(GlStateManager_FogDensity, 0x140fcf6c4, void, float value);
//CREATE_FUNC(GlStateManager_EnableColorMaterial, 0x140fe7d40, void);
//CREATE_FUNC(GlStateManager_ColorMaterial, 0x140fe7d48, void, int face, int mode);
//CREATE_FUNC(GlStateManager_Color4f, 0x140fe7cb0, void, float red, float green, float blue, float alpha);
//CREATE_FUNC(GlStateManager_Normal3f, 0x140fe7d58, void, float f, float g, float h);