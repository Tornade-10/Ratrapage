#include "graphics/ressource_manager.h"

#ifdef TRACY_ENABLE
#include <tracy/Tracy.hpp>
#endif

void ResourceManager::LoadAllTextures()
{
#ifdef TRACY_ENABLE
    ZoneScoped;
#endif

    // Default Texture -----------------
    blankTexture_ = sf::Texture();

    // UI Textures -----------------
    ui_textures_[static_cast<int>(ResourceUI::kGreenFrame)].loadFromFile("resources/Sprites/green_button00.png");
	ui_textures_[static_cast<int>(ResourceUI::kHouseIcon)].loadFromFile("resources/Sprites/Icon/House_Icon.png");
    ui_textures_[static_cast<int>(ResourceUI::kSawmillIcon)].loadFromFile("");
    ui_textures_[static_cast<int>(ResourceUI::kMineIcon)].loadFromFile("resources/Sprites/Icon/Mine_Icon.png");
    ui_textures_[static_cast<int>(ResourceUI::kStorageIcon)].loadFromFile("resources/Sprites/Icon/Storage_Icon.png");

    // Ground Textures -----------------
    land_textures_[static_cast<int>(ResourceLand::kTerrainGround)].loadFromFile("resources/Sprites/tiles/tile_0000.png");
    land_textures_[static_cast<int>(ResourceLand::kTerrainForest)].loadFromFile("resources/Sprites/tiles/Forest.png");
    land_textures_[static_cast<int>(ResourceLand::kTerrainStone)].loadFromFile("resources/Sprites/tiles/tile_0043.png");
    land_textures_[static_cast<int>(ResourceLand::kHouse)].loadFromFile("resources/Sprites/tiles/House.png");
    land_textures_[static_cast<int>(ResourceLand::kSawmill)].loadFromFile("");
    land_textures_[static_cast<int>(ResourceLand::kMine)].loadFromFile("resources/Sprites/tiles/Mine.png");
    land_textures_[static_cast<int>(ResourceLand::kStorage)].loadFromFile("resources/Sprites/tiles/Storage.png");
    land_textures_[static_cast<int>(ResourceLand::kCityHall)].loadFromFile("");

    // Cursors Textures ----------------
    cursor_textures_[static_cast<int>(ResourceCursor::kClassicCursor)].loadFromFile("resources/Sprites/cursor_none.png");
    cursor_textures_[static_cast<int>(ResourceCursor::kBuildingCursor)].loadFromFile("resources/Sprites/tool_hammer.png");

    // NPC Textures ---------------
    //npc_textures_[static_cast<int>(ResourceNPC::kWoodsMan)].loadFromFile("resources/Sprites/npc/tile_0086.png");

    // Building Textures ----------

    text_fonts_[static_cast<int>(RessourceFonts::kPixelated)].loadFromFile("resources/fonts/pixelated.ttf");
}

ResourceManager::ResourceManager()
{
#ifdef TRACY_ENABLE
    ZoneScoped;
#endif
    LoadAllTextures();
}

// TODO : finish the destructor
ResourceManager::~ResourceManager()
{
    //instance = nullptr;
}

sf::Texture& ResourceManager::GetUiTexture(ResourceUI resourceId)
{
    return this->ui_textures_[static_cast<int>(resourceId)];
}

sf::Texture& ResourceManager::GetLandTexture(ResourceLand resourceId)
{
	return land_textures_[static_cast<int>(resourceId)];
}

sf::Texture& ResourceManager::GetCursorTexture(ResourceCursor resourceId)
{
	return cursor_textures_[static_cast<int>(resourceId)];
}

sf::Texture& ResourceManager::GetNpcTexture(ResourceNPC resourceId)
{
	return npc_textures_[static_cast<int>(resourceId)];
}

sf::Font& ResourceManager::GetTextFont(RessourceFonts resourceId)
{
    return text_fonts_[static_cast<int>(resourceId)];
}
