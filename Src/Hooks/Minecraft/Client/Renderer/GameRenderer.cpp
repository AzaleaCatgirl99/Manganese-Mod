#include "GameRenderer.h"
#include "Hooks/Minecraft/World/Level.h"
#include "Hooks/Minecraft/Client/Minecraft.h"
#include "Helper/RendererHelper.h"

void GameRenderer::SetupFog(GameRenderer* _this, int param_1, float param_2)
{
	RendererHelper::renderFog(_this, param_1, param_2);
	/*GameRenderer_SetupFog(_this, param_1, param_2);*/

	//float f = (RenderDistance::get() - 2) * 16;
	///*GlStateManager::fogMode(1);*/
	//if (param_1 == -1) {
	//	GlStateManager::fogStart(0.0);
	//	GlStateManager::fogEnd(f);
	//}
	//else {
	//	GlStateManager::fogStart(f * 0.75);
	//	GlStateManager::fogEnd(f);
	//}

	//GlStateManager::disableFog();
}

void GameRenderer::RenderEyePass(GameRenderer* _this, int param_1, float param_2, void* param_3, bool param_4)
{
	/*std::cout << param_2 << std::endl;
	param_2 = param_2/2;*/
	GameRenderer_RenderEyePass(_this, param_1, param_2, param_3, param_4);
}

void GameRenderer::SetupCamera(GameRenderer* _this, int param_2, float param_3)
{
	/**(int*)(Minecraft::GetInstance() + 104) = 1;*/
	/*param_2 = -1;*/
	GameRenderer_SetupCamera(_this, param_2, param_3);
}

void GameRenderer::getCamera()
{
	GameRenderer_GetCamera();
}

void GameRenderer::resetFogColor(bool val)
{
	GameRenderer_ResetFogColor(this, val);
}

FloatBuffer* GameRenderer::getBuffer(float one, float two, float three, float four)
{
	return GameRenderer_GetBuffer(this, one, two, three, four);
}