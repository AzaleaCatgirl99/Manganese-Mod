#include "UIScene_SettingsListMenu.h"
#include "Framework.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_MultiList.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_List.h"
#include "Hooks/Minecraft/Client/UI/UIString.h"

/*
* Init hook
* Registers Manganese settings sliders and checkboxes for the Graphics section
*/
void UIScene_SettingsListMenu::Init(UIScene_SettingsListMenu* _this)
{
	if (*(int*)(_this + 1816) == 2) {
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)(_this + 328), getLabel(GRAPHICS_PRESET, false), GRAPHICS_PRESET, 0, 6, GraphicsPreset::get(), 1, 7, 3);
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)(_this + 328), getLabel(RENDER_DISTANCE, false), RENDER_DISTANCE, 2, 32, RenderDistance::get(), 1, 7, 3);
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)(_this + 328), getLabel(LEAVES_TYPE, false), LEAVES_TYPE, 0, 2, LeavesType::get(), 1, 7, 3);
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)(_this + 328), getLabel(MIPMAP_TYPE, false), MIPMAP_TYPE, 0, 2, MipmapType::get(), 1, 7, 3);
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)(_this + 328), getLabel(FOG_MODE, false), FOG_MODE, 0, 2, FogMode::get(), 1, 7, 3);

		UIControl_MultiList::AddNewCheckbox((UIControl_MultiList*)(_this + 328), getLabel(FOG_MODE, false).c_str(), SMOOTH_LIGHTING, SmoothLighting::get());
	}
	
	UIScene_SettingsListMenu_Init(_this);
}

/*
* HandleSliderElementMove hook
* Handles the sliders
* Sets the option's value, sets the slider's label, and spits out the new option value in the log
*/
void UIScene_SettingsListMenu::HandleSliderElementMove(UIScene_SettingsListMenu* _this, int a, int id, int value)
{
	std::wstring label;
	std::string funcName = "Manganese Settings";

	int oldValue;

	switch (id) {
	case GRAPHICS_PRESET:
		oldValue = GraphicsPreset::get();
		setGraphicsPreset(GRAPHICS_PRESET, oldValue, value);
		label = getLabel(GRAPHICS_PRESET, false);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(GRAPHICS_PRESET, true));
		break;
	case RENDER_DISTANCE:
		oldValue = RenderDistance::get();
		setGraphicsPreset(RENDER_DISTANCE, oldValue, value);
		RenderDistance::set(value);
		label = getLabel(RENDER_DISTANCE, false);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(RENDER_DISTANCE, true));
		break;
	case LEAVES_TYPE:
		oldValue = LeavesType::get();
		setGraphicsPreset(LEAVES_TYPE, oldValue, value);
		LeavesType::set(value);
		label = getLabel(LEAVES_TYPE, false);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(LEAVES_TYPE, true));
		break;
	case MIPMAP_TYPE:
		oldValue = MipmapType::get();
		setGraphicsPreset(MIPMAP_TYPE, oldValue, value);
		MipmapType::set(value);
		label = getLabel(MIPMAP_TYPE, false);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(MIPMAP_TYPE, true));
		break;
	case FOG_MODE:
		oldValue = FogMode::get();
		setGraphicsPreset(FOG_MODE, oldValue, value);
		FogMode::set(value);
		label = getLabel(FOG_MODE, false);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(FOG_MODE, true));
		break;
	}

	wchar_t awStack_208[256];
	uintptr_t auStack_218[16];

	swprintf_s(awStack_208, 256, label.c_str());

	UIString* newLabel = UIString::_UIString(auStack_218, awStack_208);
	UIControl_List::SetItemLabel((UIControl_List*)(_this + 328), id, newLabel, false);

	UIScene_SettingsListMenu_HandleSliderElementMove(_this, a, id, value);
}