include(FetchContent)

cmake_minimum_required(VERSION 3.8.2)
project(Manganese)
set (CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/Src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/Src/*.h)

set(SRC_FILES
	${HEADER_FILES}
	${SOURCE_FILES}
	${PROJECT_SOURCE_DIR}/Src/Assets/Resource.rc
)

# Safetyhook
FetchContent_Declare(
safetyhook
    GIT_REPOSITORY "https://github.com/cursey/safetyhook.git"
    GIT_TAG "origin/main"
)

FetchContent_MakeAvailable(safetyhook)

add_subdirectory(Lib/Lantern)
include_directories(Lib/Lantern/lantern)
include_directories(Src)

add_library(Manganese SHARED ${SRC_FILES})
target_link_libraries(Manganese PRIVATE Lantern ${CMAKE_BINARY_DIR}/Lib/Lantern/Lantern.lib)
target_link_libraries(Manganese PRIVATE lib_detours ${CMAKE_BINARY_DIR}/Lib/Lantern/lib/detours/lib_detours.lib)
target_link_libraries(Manganese PUBLIC safetyhook)