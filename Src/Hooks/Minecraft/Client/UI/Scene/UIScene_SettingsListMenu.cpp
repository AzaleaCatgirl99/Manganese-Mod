#include "UIScene_SettingsListMenu.h"
#include "Framework.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_MultiList.h"
#include "Hooks/Minecraft/Client/UI/Control/UIControl_List.h"
#include "Hooks/Minecraft/Client/UI/UIString.h"
#include "Hooks/Minecraft/Client/Minecraft.h"
#include "Helper/UIHelper.h"
#include "Helper/LevelHelper.h"

/*
* Init hook
* Registers Manganese settings sliders and checkboxes for the Graphics section
*/
void UIScene_SettingsListMenu::Init(UIScene_SettingsListMenu* _this)
{
	if (*(int*)(_this + 1816) == 2) {
		UIHelper::addNewLabel(_this + 328, L"=============== Manganese ==============", 101);

		UIHelper::addNewSlider(_this + 328, getLabel(GRAPHICS_PRESET, false), GRAPHICS_PRESET, 0, 6, GraphicsPreset::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(RENDER_DISTANCE, false), RENDER_DISTANCE, 2, 32, RenderDistance::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(LEAVES_TYPE, false), LEAVES_TYPE, 0, 2, LeavesType::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(MIPMAP_TYPE, false), MIPMAP_TYPE, 0, 2, MipmapType::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(FOG_SHAPE, false), FOG_SHAPE, 0, 2, FogShape::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(FOG_START, false), FOG_START, 0, 100, FogStart::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(FOG_END, false), FOG_END, 0, 32, FogEnd::get(), true);
		UIHelper::addNewSlider(_this + 328, getLabel(CLOUD_HEIGHT, false), CLOUD_HEIGHT, 108, 192, CloudHeight::get(), true);

		UIHelper::addNewCheckbox(_this + 328, getLabel(SMOOTH_LIGHTING, false), SMOOTH_LIGHTING, SmoothLighting::get());
		UIHelper::addNewCheckbox(_this + 328, getLabel(SKY_FOG, false), SKY_FOG, SkyFog::get());

		UIHelper::addNewLabel(_this + 328, L"=============== Minecraft ===============", 90);
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

	switch (id)
	{
	case GRAPHICS_PRESET:
		UIHelper::handleOptionChange(GRAPHICS_PRESET, GraphicsPreset::get(), value, true, LevelHelper::reloadChunks);
		label = getLabel(GRAPHICS_PRESET, false);
		break;
	case RENDER_DISTANCE:
		UIHelper::handleOptionChange(RENDER_DISTANCE, RenderDistance::get(), value, true, LevelHelper::reloadChunks);
		label = getLabel(RENDER_DISTANCE, false);
		break;
	case LEAVES_TYPE:
		UIHelper::handleOptionChange(LEAVES_TYPE, LeavesType::get(), value, true, LevelHelper::reloadChunks);
		label = getLabel(LEAVES_TYPE, false);
		break;
	case MIPMAP_TYPE:
		UIHelper::handleOptionChange(MIPMAP_TYPE, MipmapType::get(), value, false, nullptr);
		label = getLabel(MIPMAP_TYPE, false);
		break;
	case FOG_SHAPE:
		UIHelper::handleOptionChange(FOG_SHAPE, FogShape::get(), value, false, nullptr);
		label = getLabel(FOG_SHAPE, false);
		break;
	case FOG_START:
		UIHelper::handleOptionChange(FOG_START, FogStart::get(), value, false, nullptr);
		label = getLabel(FOG_START, false);
		break;
	case FOG_END:
		UIHelper::handleOptionChange(FOG_END, FogEnd::get(), value, false, nullptr);
		label = getLabel(FOG_END, false);
		break;
	case CLOUD_HEIGHT:
		UIHelper::handleOptionChange(CLOUD_HEIGHT, CloudHeight::get(), value, false, nullptr);
		label = getLabel(CLOUD_HEIGHT, false);
		break;
	}

	UIHelper::setUIStringLabel((UIControl_List*)(_this + 328), id, label);

	UIScene_SettingsListMenu_HandleSliderElementMove(_this, a, id, value);
}

void UIScene_SettingsListMenu::HandleCheckboxElementToggled(UIScene_SettingsListMenu* _this, int param_2, int id, bool value)
{
	switch (id)
	{
	case SMOOTH_LIGHTING:
		UIHelper::handleOptionChange(SMOOTH_LIGHTING, SmoothLighting::get(), value, true, LevelHelper::reloadChunks);
		break;
	case SKY_FOG:
		UIHelper::handleOptionChange(SKY_FOG, SkyFog::get(), value, false, nullptr);
		break;
	}

	UIScene_SettingsListMenu_HandleCheckboxElementToggled(_this, param_2, id, value);
}