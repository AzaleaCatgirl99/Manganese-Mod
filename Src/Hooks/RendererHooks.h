#pragma once
#include "DefaultHooks.h"

class Renderer
{
public:

	class StateSetFogEnable
	{
	public:
		static void* getTrue();

		static void Call(void* _this, bool value);

		static void Register();

		static void Reset();
	};

	class StateSetLightEnable
	{
	public:
		static void* getTrue();

		static void Call(void* _this, bool value);

		static void Register();

		static void Reset();
	};

	class StateSetMipmapEnable
	{
	public:
		static void* getTrue();

		static void Call(void* _this, bool value);

		static void Register();

		static void Reset();
	};


	static void RegisterHooks();

	static void ResetHooks();
};
