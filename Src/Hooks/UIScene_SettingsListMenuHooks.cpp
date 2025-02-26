#include "UIScene_SettingsListMenuHooks.h"
#include "DefaultHooks.h"

SafetyHookInline g_Init_hook{};
SafetyHookInline g_HandleSliderElementMove_hook{};
SafetyHookInline g_AddNewSlider_hook{};

void* TrueInit = GetProcessHandle(0x140796B00);
void* TrueHandleSliderElementMove = GetProcessHandle(0x1407F6AA0);
void* TrueAddNewSlider = GetProcessHandle(0x14069f400);

//void AddNewSliderHook(uintptr_t* _this, const std::wstring& str, int id, int min, int max, int defaultValue, bool enabled, int fastIncrement, int fastMove)
//{
//	g_AddNewSlider_hook.call(_this, str, id, min, max, defaultValue, enabled, fastIncrement, fastMove);
//}

void InitHook(void* _this)
{

	static auto func = reinterpret_cast<void(*)(void*, const std::wstring&, char, char, char, char, char, char, char)>(GetProcessHandle(0x14069F400));
	
	/*typedef int func(void*, const std::wstring&, int, int, int, int, int, int, int);
	func* f = (func*)GetProcessHandle(0x14069F400);*/
	
	/*func(_this, L"Render Distance: %i", 99, 32, 2, 18, 1, 7, 3);*/

	/*((void(*)(uintptr_t, const std::wstring &, int, int, int, int, bool, int, int))GetProcessHandleAddress(0x14069F400))(*(uintptr_t*)(_this + 328), L"Render Distance: %i", 99, 2, 32, 18, true, 7, 3);*/

	/*AddNewSliderHook(_this + 328, L"Render Distance: %i", 99, 2, 32, 18, true, 7, 3);*/
	g_Init_hook.call(_this);
	
}

void HandleSliderElementMoveHook(void* _this, int a, int b, int c)
{
	if (b == 99) {

	}
	g_HandleSliderElementMove_hook.call(_this, a, b, c);
}



void AttachUIScene_SettingsListMenuHooks()
{
	/*g_AddNewSlider_hook = safetyhook::create_inline(TrueAddNewSlider, AddNewSliderHook);*/
	g_Init_hook = safetyhook::create_inline(TrueInit, InitHook);
	/*g_HandleSliderElementMove_hook = safetyhook::create_inline(TrueHandleSliderElementMove, HandleSliderElementMoveHook);*/
}

void DetachUIScene_SettingsListMenuHooks()
{
	/*g_AddNewSlider_hook.reset();*/
	g_Init_hook.reset();
	/*g_HandleSliderElementMove_hook.reset();*/
}