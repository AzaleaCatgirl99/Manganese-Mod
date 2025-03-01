#include "Options.h"

int renderDistance = 18;
int leavesType = 1;
int mipmapType = 1;
int fogMode = 1;

int RenderDistance::get()
{
	return renderDistance;
}

void RenderDistance::set(int value)
{
	renderDistance = value;
}

const std::wstring RenderDistance::getLabel()
{
	if (RenderDistance::get() > 18) {
		return std::format(L"Render Distance: {} Chunks [WILL CRASH]", RenderDistance::get());
	}
	return std::format(L"Render Distance: {} Chunks", RenderDistance::get());
}

const std::string RenderDistance::getLogLabel()
{
	if (RenderDistance::get() > 18) {
		return std::format("Set Render Distance to: {} Chunks [WILL CRASH]", RenderDistance::get());
	}
	return std::format("Render Distance: {} Chunks", RenderDistance::get());
}




int LeavesType::get()
{
	return leavesType;
}

void LeavesType::set(int value)
{
	leavesType = value;
}

const std::wstring LeavesType::getLabel()
{
	return std::format(L"Leaves Type: {}", LeavesType::get() == 0 ? L"Fast" : LeavesType::get() == 2 ? L"Fabulous" : L"Fancy");
}

const std::string LeavesType::getLogLabel()
{
	return std::format("Set Leaves Type to: {}", LeavesType::get() == 0 ? "Fast" : LeavesType::get() == 2 ? "Fabulous" : "Fancy");
}




int MipmapType::get()
{
	return mipmapType;
}

void MipmapType::set(int value)
{
	mipmapType = value;
}

const std::wstring MipmapType::getLabel()
{
	return std::format(L"Mipmap Type: {}", MipmapType::get() == 0 ? L"OFF" : MipmapType::get() == 2 ? L"Java" : L"LCE");
}

const std::string MipmapType::getLogLabel()
{
	return std::format("Set Mipmap Type to: {}", MipmapType::get() == 0 ? "OFF" : MipmapType::get() == 2 ? "Java" : "LCE");
}




int FogMode::get()
{
	return fogMode;
}

void FogMode::set(int value)
{
	fogMode = value;
}

const std::wstring FogMode::getLabel()
{
	return std::format(L"Fog Mode: {}", FogMode::get() == 0 ? L"OFF" : FogMode::get() == 2 ? L"Java" : L"LCE");
}

const std::string FogMode::getLogLabel()
{
	return std::format("Fog Mode: {}", FogMode::get() == 0 ? "OFF" : FogMode::get() == 2 ? "Java" : "LCE");
}