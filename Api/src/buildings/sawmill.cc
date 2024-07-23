#include "buildings/sawmill.h"


#include "graphics/ressource_manager.h"

Sawmill::Sawmill(float x, float y) : Building(x, y)
{
	DefineTexture();
}

void Sawmill::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kSawmill));
}