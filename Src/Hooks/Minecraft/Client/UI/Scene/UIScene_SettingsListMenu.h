#pragma once
#include "Hooks/HookIncludes.h"

class UIScene_SettingsListMenu
{
public:
	// Hook functions
	static void Init(UIScene_SettingsListMenu* _this);
	static void HandleSliderElementMove(UIScene_SettingsListMenu* _this, int a, int id, int value);
	static void HandleCheckboxElementToggled(UIScene_SettingsListMenu* _this, int param_2, int id, bool value);
};

// Original functions
CREATE_FUNC(UIScene_SettingsListMenu_Init, 0x140796B00, void, UIScene_SettingsListMenu* _this);
CREATE_FUNC(UIScene_SettingsListMenu_HandleSliderElementMove, 0x1407F6AA0, void, UIScene_SettingsListMenu* _this, int a, int id, int value);
//CREATE_FUNC(UIScene_SettingsListMenu_HandleCheckboxElementToggled, 0x14072aa10, void, UIScene_SettingsListMenu* _this, int param_2, int id, bool value);
CREATE_FUNC(UIScene_SettingsListMenu_HandleCheckboxElementToggled, 0x1407e1bb0, void, UIScene_SettingsListMenu * _this, int param_2, int id, bool value);