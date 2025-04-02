#include "UIControl_MultiList.h"

void UIControl_MultiList::AddNewSlider(UIControl_MultiList* _this, const std::wstring& sliderName, int id, int minValue, int maxValue, int defaultValue, bool isEnabled, int fastIncrement, int fastMove)
{
	UIControl_MultiList_AddNewSlider(_this, sliderName, id, minValue, maxValue, defaultValue, isEnabled, fastIncrement, fastMove);
}

void UIControl_MultiList::AddNewCheckbox(UIControl_MultiList* _this, const std::wstring& checkboxName, int id, bool defaultValue)
{
	UIControl_MultiList_AddNewCheckbox(_this, checkboxName, id, defaultValue);
}

void UIControl_MultiList::AddNewLabel(UIControl_MultiList* _this, const std::wstring& label, int id)
{
	UIControl_MultiList_AddNewLabel(_this, label, id);
}