#ifndef API_GRAPHICS_RESOURCE_MANAGER_H
#define API_GRAPHICS_RESOURCE_MANAGER_H

#include <array>
#include <unordered_map>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

class ResourceManager
{

public:
	enum class ResourceUI
	{
		kGreenFrame,
		kGreyFrame,
		kHouseIcon,
		kSawmillIcon,
		kMineIcon,
		kStorageIcon,
		kLength
	};

	enum class ResourceLand
	{
		kTerrainGround,
		kTerrainForest,
		kTerrainStone,
		kHouse,
		kSawmill,
		kMine,
		kStorage,
		kCityHall,
		kLength
	};

	enum class ResourceCursor
	{
		kClassicCursor,
		kBuildingCursor,
		kLength
	};

	enum class ResourceNPC
	{
		kWoodsMan,
		kLength
	};


	enum class RessourceFonts
	{
		kPixelated,
		kLength
	};

private:
	std::array<sf::Texture, static_cast<int>(ResourceUI::kLength)> ui_textures_;
	std::array<sf::Texture, static_cast<int>(ResourceLand::kLength)> land_textures_;
	std::array<sf::Texture, static_cast<int>(ResourceCursor::kLength)> cursor_textures_;
	std::array<sf::Texture, static_cast<int>((ResourceNPC::kLength))> npc_textures_;
	std::array<sf::Font, static_cast<int>((RessourceFonts::kLength))> text_fonts_;
	sf::Texture blankTexture_;

	void LoadAllTextures();
public:
	static ResourceManager& Get() {
		static ResourceManager instance_;
		return instance_;
	}

	ResourceManager();
	~ResourceManager();

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetUiTexture(ResourceUI resourceId);
	sf::Texture& GetLandTexture(ResourceLand resourceId);
	sf::Texture& GetCursorTexture(ResourceCursor resourceId);
	sf::Texture& GetNpcTexture(ResourceNPC resourceId);
	sf::Font& GetTextFont(RessourceFonts resourceId);
};

#endif // API_GRAPHICS_RESOURCE_MANAGER_H