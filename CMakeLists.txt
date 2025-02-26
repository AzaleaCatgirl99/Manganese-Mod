cmake_minimum_required(VERSION 3.8.2)
project(Manganese)
set (CMAKE_CXX_STANDARD 23)

set(SRC_FILES
	dllmain.cpp
	framework.h 
	pch.cpp 
	pch.h

	Src/Hooks.cpp 
	Src/Hooks.h 
	Src/Hooks/DefaultHooks.h 
	Src/Hooks/LeafBlockHooks.cpp 
	Src/Hooks/LeafBlockHooks.h 
	Src/Hooks/LevelRendererHooks.cpp
	Src/Hooks/LevelRendererHooks.h
	Src/Hooks/RendererHooks.cpp
	Src/Hooks/RendererHooks.h
	Src/Hooks/ServerLevelHooks.cpp
	Src/Hooks/ServerLevelHooks.h
	Src/Hooks/TextureHooks.cpp
	Src/Hooks/TextureHooks.h
	Src/Hooks/UIScene_SettingsListMenuHooks.cpp
	Src/Hooks/UIScene_SettingsListMenuHooks.h 

	Src/Utils/HandleHelper.cpp 
	Src/Utils/HandleHelper.h 
	Src/Utils/Logger.cpp 
	Src/Utils/Logger.h 
	Src/Utils/TextureHelper.cpp 
	Src/Utils/TextureHelper.h 
)

include(FetchContent)

# Safetyhook
FetchContent_Declare(
safetyhook
    GIT_REPOSITORY "https://github.com/cursey/safetyhook.git"
    GIT_TAG "origin/main"
)

FetchContent_MakeAvailable(safetyhook)



add_library(Manganese SHARED ${SRC_FILES})

target_link_libraries(Manganese PUBLIC safetyhook)