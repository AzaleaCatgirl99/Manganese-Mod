#pragma once
#include "Config/Options.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_MultiList.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_List.h"
#include "Hooks/Minecraft/Client/UI/UIString.h"
#include "Hooks/Minecraft/Client/Minecraft.h"

namespace UIHelper {
	void setUIStringLabel(UIControl_List* _this, int id, std::wstring string);

	void handleOptionChange(Option option, int oldValue, int value, bool isPreset, void(*onChange)());

	void addNewSlider(void* _this, const std::wstring& label, Option option, int minValue, int maxValue, int defaultValue, bool isEnabled);

	void addNewCheckbox(void* _this, const std::wstring& label, Option option, bool defaultValue);

	void addNewLabel(void* _this, const std::wstring& label, int id);
}