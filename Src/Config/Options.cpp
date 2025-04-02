#include "Options.h"
#include "Util/Logger.h"

// Default values for all options
int graphicsPreset = 3;
int renderDistance = 18;
int leavesType = 1;
int mipmapType = 1;
int fogShape = 0;
int fogStart = 75;
int fogEnd = 16;
int cloudHeight = 128;
bool smoothLighting = true;
bool skyFog = true;

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

// Gets the fog shape value
int FogShape::get()
{
	return fogShape;
}

// Sets the fog shape value
void FogShape::set(int value)
{
	fogShape = value;
}

// Gets the fog start value
int FogStart::get()
{
	return fogStart;
}

// Sets the fog start value
void FogStart::set(int value)
{
	fogStart = value;
}

// Gets the fog end value
int FogEnd::get()
{
	return fogEnd;
}

// Sets the fog end value
void FogEnd::set(int value)
{
	fogEnd = value;
}

// Gets the cloud height value
int CloudHeight::get()
{
	return cloudHeight;
}

// Sets the cloud height value
void CloudHeight::set(int value)
{
	cloudHeight = value;
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

// Gets the sky fog value
bool SkyFog::get()
{
	return skyFog;
}

// Sets the sky fog value
void SkyFog::set(bool value)
{
	skyFog = value;
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
		currentValue = std::format(L"{} Chunks{}", RenderDistance::get(), RenderDistance::get() > 18 ? L" [MIGHT CRASH]" : L"");
		break;
	case LEAVES_TYPE:
		optionName = L"Leaves Type";
		currentValue = LeavesType::get() == 0 ? L"Fast" : LeavesType::get() == 2 ? L"Fabulous" : L"Fancy";
		break;
	case MIPMAP_TYPE:
		optionName = L"Mipmap Type";
		currentValue = MipmapType::get() == 0 ? L"OFF" : MipmapType::get() == 2 ? L"Java [WIP]" : L"LCE";
		break;
	case FOG_SHAPE:
		optionName = L"Fog Shape";
		currentValue = FogShape::get() == 1 ? L"Cylindrical [WIP]" : FogShape::get() == 2 ? L"Spherical [WIP]" : L"Planar";
		break;
	case FOG_START:
		optionName = L"Fog Start";
		currentValue = std::format(L"{}", (double)(FogStart::get())/100.0);
		break;
	case FOG_END:
		optionName = L"Fog End";
		currentValue = FogEnd::get() == 0 ? L"Auto" : std::format(L"{} Chunks", FogEnd::get());
		break;
	case CLOUD_HEIGHT:
		optionName = L"Cloud Height";
		currentValue = CloudHeight::get() == 108 ? L"Beta" : CloudHeight::get() == 128 ? L"LCE" : CloudHeight::get() == 192 ? L"Java" : std::to_wstring(CloudHeight::get());
		break;
	case SMOOTH_LIGHTING:
		optionName = L"Smooth Lighting";
		currentValue = SmoothLighting::get() == true ? L"true" : L"false";
		if (isLog == false) return optionName;
		break;
	case SKY_FOG:
		optionName = L"Sky Fog";
		currentValue = SkyFog::get() == true ? L"true" : L"false";
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
			SmoothLighting::set(false);
			SkyFog::set(false);

			GraphicsPreset::set(0);
			break;
		case 1:
			RenderDistance::set(7);
			LeavesType::set(0);
			SmoothLighting::set(false);
			SkyFog::set(true);

			GraphicsPreset::set(1);
			break;
		case 2:
			RenderDistance::set(10);
			LeavesType::set(1);
			SmoothLighting::set(true);
			SkyFog::set(true);

			GraphicsPreset::set(2);
			break;
		case 3:
			RenderDistance::set(18);
			LeavesType::set(1);
			SmoothLighting::set(true);
			SkyFog::set(true);

			GraphicsPreset::set(3);
			break;
		case 4:
			RenderDistance::set(24);
			LeavesType::set(2);
			SmoothLighting::set(true);
			SkyFog::set(true);

			GraphicsPreset::set(4);
			break;
		case 5:
			RenderDistance::set(32);
			LeavesType::set(2);
			SmoothLighting::set(true);
			SkyFog::set(true);

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

void setOptionValue(Option option, int value)
{
	switch (option)
	{
	case GRAPHICS_PRESET:
		break;
	case RENDER_DISTANCE:
		RenderDistance::set(value);
		break;
	case LEAVES_TYPE:
		LeavesType::set(value);
		break;
	case MIPMAP_TYPE:
		MipmapType::set(value);
		break;
	case FOG_SHAPE:
		FogShape::set(value);
		break;
	case FOG_START:
		FogStart::set(value);
		break;
	case FOG_END:
		FogEnd::set(value);
		break;
	case CLOUD_HEIGHT:
		CloudHeight::set(value);
		break;
	case SMOOTH_LIGHTING:
		SmoothLighting::set(value);
		break;
	case SKY_FOG:
		SkyFog::set(value);
		break;
	default:
		break;
	}
}