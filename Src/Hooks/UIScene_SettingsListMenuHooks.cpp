#include "UIScene_SettingsListMenuHooks.h"
#include "LevelRendererHooks.h"
#include "LevelHooks.h"
#include "ServerLevelHooks.h"
#include "../Framework.h"

SafetyHookInline g_Init_hook{};
SafetyHookInline g_HandleSliderElementMove_hook{};
SafetyHookInline g_AddNewSlider_hook{};

void* TrueInit = GetProcessHandle(0x140796B00);
void* TrueHandleSliderElementMove = GetProcessHandle(0x1407F6AA0);
uintptr_t TrueAddNewSlider = GetProcessHandleAddress(0x14069F400);
uintptr_t TrueAddNewToggle = GetProcessHandleAddress(0x1407c5340);

void createSlider(uintptr_t settingsListInit, const std::wstring& sliderName, int id, int min, int max, int defaultValue, bool isEnabled, int fastIncrement, int fastMove)
{
	Call<void, uintptr_t, const std::wstring&, int, unsigned int, int, int, char, int, int>(TrueAddNewSlider, settingsListInit + 328, sliderName, id, min, max, defaultValue, isEnabled, fastIncrement, fastMove);
}

void createToggle(uintptr_t settingsListInit, int id, int c, const std::wstring& sliderName, int d, char defaultValue)
{
	Call<void, uintptr_t, int, int, const std::wstring&, int, char>(TrueAddNewToggle, settingsListInit + 328, id, c, sliderName, d, defaultValue);
}

void InitHook(uintptr_t _this)
{
	if (*(int*)(_this + 1816) == 2) {
		createSlider(_this, RenderDistance::getLabel(), 99, 2, 32, RenderDistance::get(), 1, 7, 3);
		createSlider(_this, LeavesType::getLabel(), 98, 0, 2, LeavesType::get(), 1, 7, 3);
		createSlider(_this, MipmapType::getLabel(), 97, 0, 2, MipmapType::get(), 1, 7, 3);
		createSlider(_this, FogMode::getLabel(), 96, 0, 2, FogMode::get(), 1, 7, 3);
	}
	
	g_Init_hook.call(_this);
}

void HandleSliderElementMoveHook(uintptr_t _this, int a, int id, int value)
{
	std::wstring label;

	switch (id) {
	case 99:
		RenderDistance::set(value);
		label = RenderDistance::getLabel();
		Write(Info, "Manganese", RenderDistance::getLogLabel());

		if (getLevelInstance() != nullptr) {
			Call<void, uintptr_t>(GetProcessHandleAddress(0x14087d460), getAllChanged_this());
			FlushInstructionCache(GetCurrentProcess(), getServerLevel_this(), sizeof(getServerLevel_this()));
		}
		break;
	case 98:
		LeavesType::set(value);
		label = LeavesType::getLabel();
		Write(Info, "Manganese", LeavesType::getLogLabel());

		if (getLevelInstance() != nullptr)
			Call<void, uintptr_t>(GetProcessHandleAddress(0x14087d460), getAllChanged_this());
		break;
	case 97:
		MipmapType::set(value);
		label = MipmapType::getLabel();
		Write(Info, "Manganese", MipmapType::getLogLabel());
		break;
	case 96:
		FogMode::set(value);
		label = FogMode::getLabel();
		Write(Info, "Manganese", FogMode::getLogLabel());
		break;
	}

	wchar_t awStack_208[256];
	uintptr_t auStack_218[16];

	swprintf_s(awStack_208, 256, label.c_str());

	void* newLabel = Call<void*, uintptr_t[], wchar_t*>(GetProcessHandleAddress(0x140772230), auStack_218, awStack_208);

	Call<void, uintptr_t, int, void*, int>(GetProcessHandleAddress(0x1406cb980), _this + 328, id, newLabel, 0);

	g_HandleSliderElementMove_hook.call(_this, a, id, value);
}

void AttachUIScene_SettingsListMenuHooks()
{
	g_Init_hook = safetyhook::create_inline(TrueInit, InitHook);
	g_HandleSliderElementMove_hook = safetyhook::create_inline(TrueHandleSliderElementMove, HandleSliderElementMoveHook);
}

void DetachUIScene_SettingsListMenuHooks()
{
	g_Init_hook.reset();
	g_HandleSliderElementMove_hook.reset();
}