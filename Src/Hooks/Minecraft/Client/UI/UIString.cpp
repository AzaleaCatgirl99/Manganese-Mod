#include "UIString.h"

UIString::UIString()
{
	UIString_Constructor_A(this);
}

UIString::UIString(wchar_t* string)
{
	UIString_Constructor_B(this, string);
}