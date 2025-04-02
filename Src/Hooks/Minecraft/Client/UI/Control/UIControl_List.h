#pragma once
#include "Hooks/HookIncludes.h"
#include "Hooks/Minecraft/Client/UI/UIString.h"

class UIControl_List
{
public:
	static void SetItemLabel(UIControl_List* _this, int id, UIString* uiString, bool unknown);
};

// Original functions
CREATE_FUNC(UIControl_List_SetItemLabel, 0x1406cb980, void, UIControl_List* _this, int id, UIString* uiString, bool unknown);