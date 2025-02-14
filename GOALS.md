# List of current goals for 1.0

## 544p, 720p, 1440p, and 4K resolution support
544p and 720p UIs can likely be modified from other LCE versions, whereas 1440p can use a doubled-720p and 4K can be recreated from the ground up.

## Mipmapping features
Two toggle-able options; 'disable manual mipmapping' and 'use JE mipmap blending'

## Higher render distances
Hard to achieve from what has been gathered, but very worth it once figured out. From current performance tests, it's likely that the max render distance could be very high; possibly 64 or 128 chunks? This is just a guess.

## OptiFine-like features
Things like better quality grass, in-hand lighting, etc.

## JE graphics features
Things like disable smooth lighting, disable leaves culling, block rotations, fov, etc.

## PCK texture pack improvements
Allowing for blocks to be defined outside of the terrain.png, allowing for items to be defined outside of the items.png, blockstates and models equivelent to JE, injecting textures/assets into already installed DLC (for modders), allowing for UI textures and other FUI features to be defined outside of FUIs, etc.

## Optional patches for artificial rendering limitations
These patches will come as disabled-by-default options for disabling some performance features 4J added. One notable feature is x32+ item rendering, which does not exist in LCE currently and instead uses the mipped item textures.

## Raised mob cap
The mob cap will be defined by the player, with an optional ability to disable it entirely.

## Graphics presets
These will be presets for graphics settings based on performance tests and how other LCE versions render. The current plan for presets are as shown:
- Extremely Low: no smooth lighting, 2-4 render distance, disabled fog, fast clouds, fast leaves, etc.
- Low: equivelent to PS Vita at launch
- Medium: equivelent to Xbox 360/PS3/Wii U/Switch 1080p
- High: equivelent to default Xbox One settings
- Very High: 32 chunk render distance, optional patches enabled, etc.
- EXTREME: Either 64 or 128 render distance, depending on how far the game can go on high-end hardware

This is all subject to change during development.

## HDR support
This should be very easy to setup due to DirectX having quick call for it, from what has been told.

## Gamma fix
A fix for the gamma. Currently MC Xbox One on PC can't use gamma due to it originally being tied to Xbox One's display drivers. The goal is to make a recreation of the gamma system that does not rely on the display drivers and instead shaders.

## Performance improvements
Theoretical performance improvements. May not need too many.
