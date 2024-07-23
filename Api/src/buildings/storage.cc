#include "buildings/storage.h"


#include "graphics/ressource_manager.h"

Storage::Storage(float x, float y) : Building(x, y)
{
	DefineTexture();
}

void Storage::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kStorage));
}