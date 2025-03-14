#include "Options.h"
#include "Util/Logger.h"

// Default values for all options
int graphicsPreset = 3;
int renderDistance = 18;
int leavesType = 1;
int mipmapType = 1;
int fogMode = 1;
bool smoothLighting = true;

// Gets the graphics preset value
int GraphicsPreset::get()
{
	return graphicsPreset;
}

// Sets the graphics preset value
void GraphicsPreset::set(int value)
{
	graphicsPreset = value;
}

// Gets the render distance value
int RenderDistance::get()
{
	return renderDistance;
}

// Sets the render distance value
void RenderDistance::set(int value)
{
	renderDistance = value;
}

// Gets the leaves type value
int LeavesType::get()
{
	return leavesType;
}

// Sets the leaves type value
void LeavesType::set(int value)
{
	leavesType = value;
}

// Gets the mipmap type value
int MipmapType::get()
{
	return mipmapType;
}

// Sets the mipmap type value
void MipmapType::set(int value)
{
	mipmapType = value;
}

// Gets the fog mode value
int FogMode::get()
{
	return fogMode;
}

// Sets the fog mode value
void FogMode::set(int value)
{
	fogMode = value;
}

// Gets the smooth lighting value
bool SmoothLighting::get()
{
	return smoothLighting;
}

// Sets the smooth lighting value
void SmoothLighting::set(bool value)
{
	smoothLighting = value;
}

std::wstring getGraphicsPresetLabel()
{
	switch (GraphicsPreset::get()) {
	case 0: 
		return L"Potato";
	case 1:
		return L"Low";
	case 2:
		return L"Medium";
	case 3:
		return L"High";
	case 4:
		return L"Very High [MIGHT CRASH]";
	case 5:
		return L"EXTREME [MIGHT CRASH]";
	case 6:
		return L"Custom";
	default:
		return L"NULL";
	}
}

/*
* Gets the option's label. Checks whether isLog is true and then if so, returns the log format instead
*/
const std::wstring getLabel(Option option, bool isLog)
{
	std::wstring optionName;
	std::wstring currentValue;

	switch (option) {
	case GRAPHICS_PRESET:
		optionName = L"Graphics Preset";
		currentValue = getGraphicsPresetLabel();
		break;
	case RENDER_DISTANCE:
		optionName = L"Render Distance";
		currentValue = std::format(L"{} {}", RenderDistance::get(), RenderDistance::get() > 18 ? L"Chunks [MIGHT CRASH]" : L"Chunks");
		break;
	case LEAVES_TYPE:
		optionName = L"Leaves Type";
		currentValue = LeavesType::get() == 0 ? L"Fast" : LeavesType::get() == 2 ? L"Fabulous" : L"Fancy";
		break;
	case MIPMAP_TYPE:
		optionName = L"Mipmap Type";
		currentValue = MipmapType::get() == 0 ? L"OFF" : MipmapType::get() == 2 ? L"Java [WIP]" : L"LCE";
		break;
	case FOG_MODE:
		optionName = L"Fog Mode";
		currentValue = FogMode::get() == 0 ? L"OFF" : FogMode::get() == 2 ? L"Java [WIP]" : L"LCE";
		break;
	case SMOOTH_LIGHTING:
		optionName = L"Smooth Lighting";
		currentValue = SmoothLighting::get() == true ? L"true" : L"false";
		if (isLog == false) return optionName;
		break;
	default:
		optionName = L"NULL SETTING";
		currentValue = L"NULL VALUE";
		break;
	};

	if (isLog == true) {
		optionName = L"Set " + optionName + L" to";
	}

	return std::format(L"{}: {}", optionName, currentValue);
}

/*
* Sets the graphics preset values based on the current changed option
*/
void setGraphicsPreset(Option option, char oldValue, char value)
{
	if (option == GRAPHICS_PRESET && oldValue != value) {
		switch (value) {
		case 0:
			RenderDistance::set(4);
			LeavesType::set(0);
			FogMode::set(0);
			SmoothLighting::set(false);

			GraphicsPreset::set(0);
			break;
		case 1:
			RenderDistance::set(7);
			LeavesType::set(0);
			FogMode::set(1);
			SmoothLighting::set(false);

			GraphicsPreset::set(1);
			break;
		case 2:
			RenderDistance::set(10);
			LeavesType::set(1);
			FogMode::set(1);
			SmoothLighting::set(true);

			GraphicsPreset::set(2);
			break;
		case 3:
			RenderDistance::set(18);
			LeavesType::set(1);
			FogMode::set(1);
			SmoothLighting::set(true);

			GraphicsPreset::set(3);
			break;
		case 4:
			RenderDistance::set(24);
			LeavesType::set(2);
			FogMode::set(2);
			SmoothLighting::set(true);

			GraphicsPreset::set(4);
			break;
		case 5:
			RenderDistance::set(32);
			LeavesType::set(2);
			FogMode::set(2);
			SmoothLighting::set(true);

			GraphicsPreset::set(5);
			break;
		default:
			break;
		}
	}

	if (option != GRAPHICS_PRESET && oldValue != value) {
		GraphicsPreset::set(6);
	}
}