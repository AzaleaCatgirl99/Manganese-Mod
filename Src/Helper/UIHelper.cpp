#include "UIHelper.h"

namespace UIHelper {
	void setUIStringLabel(UIControl_List* _this, int id, std::wstring string)
	{
		wchar_t label[256];

		swprintf_s(label, 256, string.c_str());

		UIString uiLabel(label);
		UIControl_List::SetItemLabel(_this, id, &uiLabel, false);
	}

	void handleOptionChange(Option option, int oldValue, int value, bool isPreset, void(*onChange)())
	{
		std::string funcName = "Manganese Settings";

		if (isPreset == true) setGraphicsPreset(option, oldValue, value);
		setOptionValue(option, value);
		M_LOGW_C(funcName.c_str(), GREEN, getLabel(option, true));

		if (onChange != nullptr)
			onChange();
	}

	void addNewSlider(void* _this, const std::wstring& label, Option option, int minValue, int maxValue, int defaultValue, bool isEnabled)
	{
		UIControl_MultiList::AddNewSlider((UIControl_MultiList*)_this, label, option, minValue, maxValue, defaultValue, isEnabled, 3, 7);
	}

	void addNewCheckbox(void* _this, const std::wstring& label, Option option, bool defaultValue)
	{
		UIControl_MultiList::AddNewCheckbox((UIControl_MultiList*)_this, label, option, defaultValue);
	}

	void addNewLabel(void* _this, const std::wstring& label, int id)
	{
		UIControl_MultiList::AddNewLabel((UIControl_MultiList*)_this, label, id);
	}
};