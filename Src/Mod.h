#pragma once
#include <LanternMod.h>


class Manganese : public LanternMod
{
public:
	// Runs when the mod is enabled
	void Enable() override;
	
	// Runs when the mod is disabled
	void Disable() override;

	// Gets the version of the mod
	std::wstring GetVersion() override;

	// Gets the name of the mod
	std::wstring GetName() override;

	// Gets the description of the mod
	std::wstring GetDescription();

	// Gets the author of the mod
	std::wstring GetAuthorName();

	// Gets the id of the mod
	std::wstring GetID();

	// Gets the targeted Lantern version of the mod
	uint64_t GetTargetedLanternVersion();
};