#pragma once
#include "Hooks/HookIncludes.h"
#include "Hooks/Minecraft/Client/UI/UIString.h"

class UIControl_MultiList
{
public:
	static void AddNewSlider(UIControl_MultiList* _this, const std::wstring& sliderName, int id, int minValue, int maxValue, int defaultValue, bool isEnabled, int fastIncrement, int fastMove);
	static void AddNewCheckbox(UIControl_MultiList* _this, const std::wstring& checkboxName, int id, bool defaultValue);
	static void AddNewLabel(UIControl_MultiList* _this, const std::wstring& label, int id);
};

// Original functions
CREATE_FUNC(UIControl_MultiList_AddNewSlider, 0x14069F400, void, UIControl_MultiList* _this, const std::wstring& sliderName, int id, int minValue, int maxValue, int defaultValue, bool isEnabled, int fastIncrement, int fastMove);
CREATE_FUNC(UIControl_MultiList_AddNewCheckbox, 0x14069F070, void, UIControl_MultiList* _this, const std::wstring& checkboxName, int id, bool defaultValue);
CREATE_FUNC(UIControl_MultiList_AddNewLabel, 0x14069f380, void, UIControl_MultiList* _this, const std::wstring& label, int id);