#include "RendererHelper.h"
#include "Hooks/Minecraft/Client/Renderer/Renderer.h"
#include "Hooks/Minecraft/Core/FloatBuffer.h"
#include "Hooks/Minecraft/World/Entities/Entity.h"

namespace RendererHelper {
    float fogDistance()
    {
        if (FogEnd::get() == 0)
            return RenderDistance::get() * 16.0f;

        return FogEnd::get() * 16.0f;
    }

    void renderFog(GameRenderer* gameRenderer, int i, float tickDelta) {
        void* local_c0;
        Entity local_b0[16];
        void* local_a0[8];
        uintptr_t local_80[8];

        /*GameRenderer::getCamera();*/
        /*GameRenderer _this = *gameRenderer;*/
        (*(GameRenderer*)gameRenderer).resetFogColor(false);
        GlStateManager::normal3f(0.0f, -1.0f, 0.0f);
        
        /*FloatBuffer* buffer = (*(GameRenderer*)gameRenderer).getBuffer(*(float*)(gameRenderer + 0x21b8), *(float*)(gameRenderer + 0x21bc), *(float*)(gameRenderer + 0x21c0), 1.0);
        GlStateManager::glFog(5, buffer);*/
        GlStateManager::color4f(1.0f, 1.0f, 1.0f, 1.0f);
        /*GlStateManager::normal3f(0.0f, -1.0f, 0.0f);*/
        /*int* blockAt = (int*)Camera::getBlockAt((Level*)(*(int*)(gameRenderer + 0x30) + 0x48), local_b0, tickDelta);*/
        /*BlockState blockState = Camera.method_9371(this.client.world, entity, tickDelta);*/

        /*unsigned int uVar7 = CALL_VTABLE_FUNC<unsigned int, 0x58, void*>(local_c0, local_c0);*/

        bool hasBlindness;
        //if ((uVar7 & 0xc000000) == 0xc000000)
        //{
        //    /*void* puVar11 = CALL_FUNC<0x140127b70, void*, void*, void*>(local_a0, &local_c0);
        //    void* 
        //    bool cVar6 = CALL_VTABLE_FUNC<bool, 0x7a8, void*, void*>(puVar11, puVar11, );
        //        (**(code**)(*(longlong*)*puVar11 + 0x7a8))((longlong*)*puVar11, DAT_140fa42c0);*/
        //    hasBlindness = true;
        //}
        //else {
            hasBlindness = false;
        /*}*/

        //void* qqq = Call<void*, int*>(*blockAt, blockAt); // (**(code**)*puVar10)(puVar10);
        //void* www = CALL_FUNC<0x140fa4578, void*>();
        /*bool isInWater = qqq != www;*/
        //int* dsds = (int*)CALL_FUNC<0x140127b70, int*, void*, void*>(local_80, &local_c0);
        ///*int* dsds = (undefined8*)FUN_140127b70(local_80, &local_c0);*/
        //uintptr_t cVar6 = CALL_VTABLE_FUNC<uintptr_t, 0x7a8>(dsds);
        //uintptr_t DAT_140fa42a8 = *(uintptr_t*)(*(uintptr_t*)GET_ADDRESS(0x140fa42a8));
        /*bool cVar6 = (**(code**)(*(longlong*)*puVar10 + 0x7a8))((longlong*)*puVar10, DAT_140fa42a8);*/
        bool isInWater = false;
        bool thickFog = false;
        bool aaa = *(bool*)(gameRenderer + 0x144);
        /*bool aaa = true;*/
        bool isInLava = false; // FUN_1402f4100

        if (hasBlindness)
        {
            /*void* livingEntity = static_cast<void*>((*(GameRenderer*)gameRenderer).entity);*/
            float f = 5.0f;
            /*int j = MobEffectInstance::getDuration();*/
            int j = 0;
            if (j < 20) {
                f = 5.0f + (fogDistance() - 5.0f) * (1.0f - (float)j / 20.0f);
            }

            GlStateManager::fogMode(1);
            if (i == -1) {
                GlStateManager::fogStart(0.0f);
                GlStateManager::fogEnd(f * 0.8f);
            }
            else {
                GlStateManager::fogStart(f * 0.25f);
                GlStateManager::fogEnd(f);
            }

            /*if (GLContext.getCapabilities().GL_NV_fog_distance) {
                GlStateManager::method_12300(34138, 34139);
            }*/
        }
        else if (thickFog) {
            GlStateManager::fogMode(2);
            GlStateManager::fogDensity(0.1f);
        }
        else if (aaa == false)
        {
            /*else if (blockState.getMaterial() == Material.WATER) {*/
            if (isInWater) {
                GlStateManager::fogMode(2);
                /*if (instanceof<void*>((*(GameRenderer*)gameRenderer).entity)) {
                    void* livingEntity = static_cast<void*>((*(GameRenderer*)_this).entity);
                    if (livingEntity.hasStatusEffect(StatusEffects.WATER_BREATHING)) {
                        GlStateManager::fogDensity(0.01);
                    }
                    else {
                        GlStateManager::fogDensity(0.1 - (float)EnchantmentHelper::getRespiration((void*)(*(GameRenderer*)_this).entity) * 0.03);
                    }
                }
                else {*/
                    GlStateManager::fogDensity(0.1f);
                /*}*/
            }
            /*else if (blockState.getMaterial() == Material.LAVA) {*/
            else if (isInLava) {
                GlStateManager::fogMode(2);
                /*GlStateManager::fogDensity(2.0f);*/
                GlStateManager::fogDensity(0.1f);
            }
            else {
                /*int renderDistance = fogDistance();*/
                float f = fogDistance();

                float h = (100.0f - (float)FogStart::get())/100.0f;
                GlStateManager::fogMode(1);
                if (i == -1) {
                    GlStateManager::fogStart(0.0f);
                    GlStateManager::fogEnd(f);
                }
                else {
                    GlStateManager::fogStart(f * h);
                    GlStateManager::fogEnd(f);
                }
            
                /*GlStateManager::fogDensity(1.0f);*/

            /*if (GLContext.getCapabilities().GL_NV_fog_distance) {
                GlStateManager::method_12300(34138, 34139);
            }*/

            /*if (this.client.world.dimension.isFogThick((int)(*(GameRenderer*)_this).entity.x, (int)(*(GameRenderer*)_this).entity.z) || this.client.inGameHud.method_12167().method_12174()) {
                GlStateManager::fogStart(f * 0.05);
                GlStateManager::fogEnd(Math::min(f, 192.0) * 0.5);
            }*/
            }
        }

        /*GlStateManager::enableColorMaterial();*/
        GlStateManager::enableFog();
        /*GlStateManager::colorMaterial(0, 2);*/
    }
}