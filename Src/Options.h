#pragma once
#include <format>

class RenderDistance
{
public:
	static int get();

	static void set(int value);

	static const std::wstring getLabel();

	static const std::string getLogLabel();
};

class LeavesType
{
public:
	static int get();

	static void set(int value);

	static const std::wstring getLabel();

	static const std::string getLogLabel();
};

class MipmapType
{
public:
	static int get();

	static void set(int value);

	static const std::wstring getLabel();

	static const std::string getLogLabel();
};

class FogMode
{
public:
	static int get();

	static void set(int value);

	static const std::wstring getLabel();

	static const std::string getLogLabel();
};