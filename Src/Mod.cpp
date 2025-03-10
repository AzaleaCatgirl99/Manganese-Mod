#include "Mod.h"
#include "Utils/LanternLoggerExtension.h"
#include "Hooks/Hooks.h"

// Logger function name for the hooker
std::string hookRegisterFuncName = "Manganese Hooker";

// Registers the hooks and spits out completion in the log
void Manganese::Enable()
{
	RegisterHooks();
	M_LOG_C(hookRegisterFuncName.c_str(), CYAN, "Hooks Registered.");
}

// Resets the hooks and spits out completion in the log
void Manganese::Disable()
{
	ResetHooks();
	M_LOG_C(hookRegisterFuncName.c_str(), CYAN, "Hooks Reset.");
}

// Gets the Manganese version
std::wstring Manganese::GetVersion()
{
	return L"0.1.0-alpha";
}

// Gets the mod name for Manganese
std::wstring Manganese::GetName()
{
	return L"Manganese";
}