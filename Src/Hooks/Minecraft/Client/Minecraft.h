#pragma once
#include "Hooks/HookIncludes.h"
#include "Hooks/Minecraft/World/Level.h"
#include "Hooks/Minecraft/Client/Renderer/LevelRenderer.h"

class Minecraft
{
public:
	VTable vftable;
	Level* level;
	uint8_t skip[0x40];
	LevelRenderer* levelRenderer;

	static Minecraft* GetInstance();

};

CREATE_FUNC(Minecraft_GetInstance, 0x1408727a0, Minecraft*);