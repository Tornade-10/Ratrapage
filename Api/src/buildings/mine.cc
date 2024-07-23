#include "buildings/mine.h"


#include "graphics/ressource_manager.h"

Mine::Mine(float x, float y) : Building(x, y)
{
	DefineTexture();
}

void Mine::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kMine));
}