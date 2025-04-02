#include "Renderer.h"
#include <mfobjects.h>
#include <cstddef>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>

// StateSetFogEnable hook; sets the value of fog depending on the FogMode
void Renderer::StateSetFogEnable(Renderer* _this, bool value)
{
    if (SkyFog::get() == false) {
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

template <int I>
__m256 vinsertps_avx(__m256 a, float x) {
    __m256 b = _mm256_broadcast_ss(&x);

    return _mm256_blend_ps(a, b, I);
}

void** GET_MC_RENDERER_CONTEXT1()
{
    DWORD DAT_140fe7e8c = *(DWORD*)GET_ADDRESS(0x140fe7e8c);
    return (void**)TlsGetValue(DAT_140fe7e8c);
}

ID3D11DeviceContext2* GET_MC_RENDERER_CONTEXT()
{
    DWORD DAT_140fe7e8c = *(DWORD*)GET_ADDRESS(0x140fe7e8c);
    return *(ID3D11DeviceContext2**)TlsGetValue(DAT_140fe7e8c);
}

void Renderer::updateFogState()
{
    typedef unsigned __int64 uint;
    typedef __int64 int64;
    typedef unsigned long ulong;

    uint _DAT_140be9910 = *(uint*)GET_ADDRESS(0x140be9910);
    uint auVar2;
    uint auVar3;
    uint* local_38[6];

    auVar3 = 0.0f;
    void** context = GET_MC_RENDERER_CONTEXT1();
    ID3D11DeviceContext2* deviceContext = GET_MC_RENDERER_CONTEXT();
    if (*(bool*)(context + 0x1059) == false) {
        auVar3 = 0.0f;
    }
    else if (*(int*)(context + 0x1074) == 1) {
        auVar3 = 1.0f / (*(float*)(context + 0x20c) - *(float*)(context + 0x105c));
        auVar3 += 0x3f800000;
    }
    else {
        auVar3 = *(float*)(context + 0x1064) + 0x40000000;
    }
    auVar2 = _DAT_140be9910 + *(float*)(context + 0x20d);
    auVar2 += *(float*)(context + 0x20e);
    auVar2 += *(float*)(context + 0x106c);

    D3D11_TILED_RESOURCE_COORDINATE coord(0, 0, 0, 0);
    D3D11_TILE_REGION_SIZE region(0, false, 0, 0, 0);
    
    deviceContext->UpdateTiles((ID3D11Resource*)(context[0x3a7]), &coord, &region, local_38, D3D11_TILE_COPY_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER);
    *local_38[0] = auVar3;
    deviceContext->ResizeTilePool((ID3D11Buffer*)(context[0x3a7]), 0);
    *local_38[0] = auVar2;
    deviceContext->UpdateTiles((ID3D11Resource*)(context[0x3b0]), &coord, &region, local_38, D3D11_TILE_COPY_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER);
    deviceContext->ResizeTilePool((ID3D11Buffer*)(context[0x3b0]), 0);
    return;
}

//void Renderer::updateFogState()
//{
//    __m256 _DAT_140be9910 = *(__m256*)GET_ADDRESS(0x140be9910);
//    float auVar2;
//    float auVar3;
//    float(*local_38[6]);
//
//    float zero = 0.0f;
//    auVar3 = zero;
//    void** context = (void**)GET_ADDRESS(0x140fe7e8c);
//    ID3D11DeviceContext2* deviceContext = D3D11_X::GET_MC_RENDERER_CONTEXT();
//    if (*(bool*)(context + 0x1059) == false) {
//        auVar3 = *vinsertps_avx<0x20>(_mm256_broadcast_ss(&auVar3), 0).m256_f32;
//    }
//    else if (*(int*)(context + 0x1074) == 1) {
//        auVar3 = *vinsertps_avx<0x10>((*(__m256*)(context + 0x20c)), 1.0f / (*(float*)(context + 0x20c) - *(float*)(context + 0x105c))).m256_f32;
//        auVar3 = *vinsertps_avx<0x20>(_mm256_broadcast_ss(&auVar3), 0x3f800000).m256_f32;
//    }
//    else {
//        auVar3 = *vinsertps_avx<0x20>((*(__m256*)(context + 0x1064)), 0x40000000).m256_f32;
//    }
//    auVar2 = *vinsertps_avx<0x0>(_DAT_140be9910, *(float*)(context + 0x20d)).m256_f32;
//    auVar2 = *vinsertps_avx<0x10>(_mm256_broadcast_ss(&auVar2), *(float*)(context + 0x20e)).m256_f32;
//    auVar2 = *vinsertps_avx<0x20>(_mm256_broadcast_ss(&auVar2), *(float*)(context + 0x106c)).m256_f32;
//    
//    /*CALL_FUNC<0x140fe82dc, void, void*, int, int, int, float*[]>(&context[0x3a7], 0, 4, 0, local_38);
//    *local_38[0] = auVar3;
//    CALL_FUNC<0x140fe82e4, void, void*, int>(&context[0x3a7], 0);
//    CALL_FUNC<0x140fe82dc, void, void*, int, int, int, float*[]>(&context[0x3b0], 0, 4, 0, local_38);
//    *local_38[0] = auVar2;
//    CALL_FUNC<0x140fe82e4, void, void*, int>(&context[0x3b0], 0);*/
//
//    /*D3D11_TILED_RESOURCE_COORDINATE coord(0, 0, 0, 4);
//    D3D11_TILE_REGION_SIZE region_size(0, false, 16, 16, 16);
//    
//    UPDATE_TILES(deviceContext + 0x3a7, &coord, &region_size, &zero, 4);
//    CALL_VTABLE_FUNC<void, 0x458, void*, int>(deviceContext, deviceContext + 0x3a7, 0);
//    UPDATE_TILES(deviceContext + 0x3b0, &coord, &region_size, &zero, 4);
//    CALL_VTABLE_FUNC<void, 0x458, void*, int>(deviceContext, deviceContext + 0x3b0, 0);*/
//
//    //typedef unsigned __int64 uint;
//
//    //uint* ccontext = (uint*)GET_MC_RENDERER_CONTEXT1();
//
//    //CALL_VTABLE_FUNC<void, 0x450, void*, int, int, int, float*>(deviceContext, context + 0x3a7, 0, 4, 0, &zero);
//    ///**local_38[0] = auVar3;*/
//    //CALL_VTABLE_FUNC<void, 0x458, void*, int>(deviceContext, context + 0x3a7, 0);
//    //CALL_VTABLE_FUNC<void, 0x450, void*, int, int, int, float*>(deviceContext, context + 0x3b0, 0, 4, 0, &zero);
//    ///**local_38[0] = auVar2;*/
//    //CALL_VTABLE_FUNC<void, 0x458, void*, int>(deviceContext, context + 0x3b0, 0);
//
//    /*D3D11_TILED_RESOURCE_COORDINATE coord(0, 0, 0, 4);
//    D3D11_TILE_REGION_SIZE region_size(0, false, 16, 16, 16);*/
//
//    //
//    ////deviceContext->CopyTiles((ID3D11Resource*)(context + 0x3a7), &coord, &region_size, (ID3D11Buffer*)(context + 0x3a7), zero, 4);
//
//
//    deviceContext->UpdateTiles((ID3D11Resource*)(context + 0x3a7), 0LL, 4LL, 0, local_38);
//    *local_38[0] = auVar3;
//    deviceContext->ResizeTilePool((ID3D11Buffer*)(context + 0x3a7), 0);
//    *local_38[0] = auVar2;
//    deviceContext->UpdateTiles((ID3D11Resource*)(context + 0x3b0), 0LL, 4LL, 0, local_38);
//    
//    deviceContext->ResizeTilePool((ID3D11Buffer*)(context + 0x3b0), 0);
//    return;
//}

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