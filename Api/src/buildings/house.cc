#include "buildings/house.h"


#include "graphics/ressource_manager.h"

House::House(float x, float y) : Building(x,y)
{
	DefineTexture();
}

void House::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kHouse));
}
