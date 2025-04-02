#pragma once
#include <format>

// Option to change the graphics preset
class GraphicsPreset
{
public:
	static int get();

	static void set(int value);
};

// Option to change the render distance
class RenderDistance
{
public:
	static int get();

	static void set(int value);
};

// Option to change the leaves type
class LeavesType
{
public:
	static int get();

	static void set(int value);
};

// Option to change the mipmap type
class MipmapType
{
public:
	static int get();

	static void set(int value);
};

// Option to change the fog shape
class FogShape
{
public:
	static int get();

	static void set(int value);
};

// Option to change the fog start
class FogStart
{
public:
	static int get();

	static void set(int value);
};

// Option to change the fog end
class FogEnd
{
public:
	static int get();

	static void set(int value);
};

// Option to change the cloud height
class CloudHeight
{
public:
	static int get();

	static void set(int value);
};

// Option to change smooth lighting
class SmoothLighting
{
public:
	static bool get();

	static void set(bool value);
};

class SkyFog
{
public:
	static bool get();

	static void set(bool value);
};

// Enum for option ids
enum Option : int
{
	GRAPHICS_PRESET = 100,
	RENDER_DISTANCE = 99,
	LEAVES_TYPE = 98,
	MIPMAP_TYPE = 97,
	FOG_SHAPE = 96,
	FOG_START = 95,
	FOG_END = 94,
	CLOUD_HEIGHT = 93,
	SMOOTH_LIGHTING = 92,
	SKY_FOG = 91
};

// Gets the option's label and checks for whether to use the log varient
const std::wstring getLabel(Option option, bool isLog);


void setGraphicsPreset(Option option, char oldValue, char value);

void setOptionValue(Option option, int value);