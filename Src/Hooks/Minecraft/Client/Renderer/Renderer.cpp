#include "Renderer.h"

// StateSetFogEnable hook; sets the value of fog depending on the FogMode
void Renderer::StateSetFogEnable(Renderer* _this, bool value)
{
    if (FogMode::get() == 0) {
        Renderer_StateSetFogEnable(_this, false);
    }
    else {
        Renderer_StateSetFogEnable(_this, value);
    }
}

// StateSetLightEnable hook
void Renderer::StateSetLightingEnable(Renderer* _this, bool value)
{
    Renderer_StateSetLightingEnable(_this, value);
}

// TextureSetTextureLevels hook; sets the value of mipmap depending on the MipmapType
void Renderer::TextureSetTextureLevels(Renderer* _this, int value)
{
    if (MipmapType::get() == 0) {
        Renderer_TextureSetTextureLevels(_this, 0);
    }
    else {
        Renderer_TextureSetTextureLevels(_this, value);
    }
}

// C hook; TODO figure out the true name of this function
void Renderer::C(Renderer* _this, int value)
{
    /*if (FogMode::get() == 0) {
        Renderer_C(_this, false);
    }
    else {
        Renderer_C(_this, value);
    }*/
    std::cout << value << std::endl;
    Renderer_C(_this, (RenderDistance::get()) * 16);
}

// Q hook; TODO figure out the true name of this function
void Renderer::Q(Renderer* _this, int a, bool value)
{
    Renderer_Q(_this, a, value);
}

// A hook; TODO figure out the true name of this function
void Renderer::A(Renderer* _this, int value)
{
    Renderer_A(_this, (RenderDistance::get() - 1) * 16);
}

void Renderer::S(Renderer* _this, float param_2, float param_3)
{
    /*std::cout << param_2 << std::endl;
    std::cout << param_3 << std::endl;
    float distance = (RenderDistance::get() - 1) * 16;
    std::cout << distance << std::endl;*/
    Renderer_S(_this, 0, 0);
}