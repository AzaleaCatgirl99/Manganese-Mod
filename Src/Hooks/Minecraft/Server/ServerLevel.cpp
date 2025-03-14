#include "ServerLevel.h"

// Constructor hook; sets the server render distance based on the setting value
ServerLevel* ServerLevel::Constructor(ServerLevel* _this, void* minecraftServer, void* LevelStorage_shared_ptr, void* levelData, int* a5)
{
    int renderDistance = RenderDistance::get();

    /*if (renderDistance >= 18)
        renderDistance -= 2;*/

    *(uint64_t*)(Call<uint64_t, void*>(GET_ADDRESS(0x1400f6490), minecraftServer) + 260) = renderDistance;
    return ServerLevel_Constructor(_this, minecraftServer, LevelStorage_shared_ptr, levelData, a5);
}