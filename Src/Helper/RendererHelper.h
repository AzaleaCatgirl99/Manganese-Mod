#pragma once
#include "Hooks/Minecraft/Client/Renderer/GameRenderer.h"
#include "Hooks/Minecraft/World/Level.h"
#include "Hooks/Minecraft/Client/Renderer/GlStateManager.h"
#include "Hooks/Minecraft/Client/Renderer/Camera.h"
#include "Config/Options.h"
#include "Hooks/Minecraft/World/EnchantmentHelper.h"

namespace RendererHelper {
	static enum Fog : int
	{
		LINEAR = 0,
		EXP = 1,
		EXP2 = 2
	};

    template<typename Base, typename T>
    inline bool instanceof(const T* ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }

    void renderFog(GameRenderer* _this, int i, float tickDelta);
}