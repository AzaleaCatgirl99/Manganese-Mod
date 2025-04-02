#include "GlStateManager.h"

static inline void** rendererPtr = (void**)GET_ADDRESS(0x140fe7a98);

void GlStateManager::enableFog()
{
	CALL_VTABLE_FUNC<void, 720>(*rendererPtr);
}

void GlStateManager::disableFog()
{
	CALL_VTABLE_FUNC<void, 728>(*rendererPtr);
}

void GlStateManager::fogMode(int mode)
{
	CALL_VTABLE_FUNC<void, 0x2a0, int>(*rendererPtr, mode);
}

void GlStateManager::fogStart(float value)
{
	CALL_VTABLE_FUNC<void, 0x2a8, float>(*rendererPtr, value);
}

void GlStateManager::fogEnd(float value)
{
	CALL_VTABLE_FUNC<void, 0x2b0, float>(*rendererPtr, value);
}

void GlStateManager::fogDensity(float value)
{
	CALL_VTABLE_FUNC<void, 0x2b8, float>(*rendererPtr, value);
}

void GlStateManager::enableColorMaterial()
{
	
	CALL_VTABLE_FUNC<void, 704>(*rendererPtr);
}

void GlStateManager::disableColorMaterial()
{
	CALL_VTABLE_FUNC<void, 448, void*>(*rendererPtr, *rendererPtr);
}

void GlStateManager::colorMaterial(int face, int mode)
{
	
	CALL_VTABLE_FUNC<void, 712, int, int>(*rendererPtr, face, mode);
}

void GlStateManager::color4f(float red, float green, float blue, float alpha)
{
	CALL_VTABLE_FUNC<void, 0x218, void*, float, float, float, float>(*rendererPtr, *rendererPtr, red, green, blue, alpha);
}

void GlStateManager::normal3f(float f, float g, float h)
{
	CALL_VTABLE_FUNC<void, 624, void*, float, float, float>(*rendererPtr, *rendererPtr, f, g, h);
}

void GlStateManager::glFog(int pname, FloatBuffer* floatBuffer)
{
	float *puVar4 = *(float **)(floatBuffer + 0x20);
	CALL_VTABLE_FUNC<void, 0x2c0, float, float, float>(*rendererPtr, *puVar4, puVar4[1], puVar4[2]);
}

void GlStateManager::pushMatrix()
{
	CALL_VTABLE_FUNC<void, 504, void*>(*rendererPtr, *rendererPtr);
}

void GlStateManager::popMatrix()
{
	CALL_VTABLE_FUNC<void, 544, void*>(*rendererPtr, *rendererPtr);
}