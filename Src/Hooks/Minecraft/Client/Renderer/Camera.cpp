#include "Camera.h"

void* Camera::getBlockAt(Level* level, Entity* entity, float param_3)
{
	return Camera_GetBlockAt(level, entity, param_3);
}