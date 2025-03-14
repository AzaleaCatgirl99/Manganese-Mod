include(FetchContent)

cmake_minimum_required(VERSION 3.8.2)
project(Manganese)
set (CMAKE_CXX_STANDARD 20)

set(SRC_FILES
	resource.h 
	Resource.rc

	Src/Manganese.cpp
	Src/Manganese.h
	Src/Framework.h 
	Src/Mod.cpp 
	Src/Mod.h

	Src/Hooks/HookIncludes.h

	Src/Hooks/Hooks.cpp
	Src/Hooks/Hooks.h
	Src/Hooks/Minecraft/World/Blocks/LeafBlock.cpp
	Src/Hooks/Minecraft/World/Blocks/LeafBlock.h
	Src/Hooks/Minecraft/Client/Renderer/LevelRenderer.cpp
	Src/Hooks/Minecraft/Client/Renderer/LevelRenderer.h
	Src/Hooks/Minecraft/Client/Renderer/Renderer.cpp
	Src/Hooks/Minecraft/Client/Renderer/Renderer.h
	Src/Hooks/Minecraft/Server/ServerLevel.cpp
	Src/Hooks/Minecraft/Server/ServerLevel.h
	Src/Hooks/Minecraft/Client/Renderer/Texture/Texture.cpp
	Src/Hooks/Minecraft/Client/Renderer/Texture/Texture.h
	Src/Hooks/Minecraft/Client/UI/Scene/UIScene_SettingsListMenu.cpp
	Src/Hooks/Minecraft/Client/UI/Scene/UIScene_SettingsListMenu.h

	Src/Hooks/Minecraft/Client/Renderer/BlockRenderer.cpp 
	Src/Hooks/Minecraft/Client/Renderer/BlockRenderer.h 

	Src/Hooks/Minecraft/Client/Renderer/Texture/BufferedImage.h
	Src/Hooks/Minecraft/Client/Renderer/Texture/BufferedImage.cpp
	Src/Hooks/Minecraft/Client/UI/Control/UIControl_MultiList.cpp
	Src/Hooks/Minecraft/Client/UI/Control/UIControl_MultiList.h
	Src/Hooks/Minecraft/Client/UI/Control/UIControl_List.h
	Src/Hooks/Minecraft/Client/UI/Control/UIControl_List.cpp
	Src/Hooks/Minecraft/Client/UI/UIString.h
	Src/Hooks/Minecraft/Client/UI/UIString.cpp

	 
	 
	 
	Src/Utils/LanternLoggerExtension.h
	Src/Utils/TextureHelper.cpp 
	Src/Utils/TextureHelper.h 
	 
	Src/Utils/MemoryHandler.h
	Src/Config/Options.cpp
	Src/Config/Options.h
   "Src/Utils/HookHelperExtension.h" "Src/Hooks/Minecraft/Client/Minecraft.h" "Src/Hooks/Minecraft/Client/Minecraft.cpp" "Src/Hooks/Minecraft/World/Level.h" "Src/Hooks/Minecraft/World/Level.cpp")

# Safetyhook
FetchContent_Declare(
safetyhook
    GIT_REPOSITORY "https://github.com/Permdog99/safetyhook.git"
    GIT_TAG "origin/patch-1"
)

FetchContent_MakeAvailable(safetyhook)

add_subdirectory(Lib/Lantern)
include_directories(Lib/Lantern/lantern Lib/Lantern/lantern/lib/detours)
link_directories(${CMAKE_BINARY_DIR}/Lib/Lantern/Lantern ${CMAKE_BINARY_DIR}/Lib/Lantern/Lantern/lib/detours)

include_directories(Src)

add_library(Manganese SHARED ${SRC_FILES})
target_link_libraries(Manganese PRIVATE lib_detours ${CMAKE_BINARY_DIR}/Lib/Lantern/Lantern.lib)
target_link_libraries(Manganese PUBLIC safetyhook)