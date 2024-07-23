#include "tilemap/tile.h"

#include <SFML/Graphics/RectangleShape.hpp>

#ifdef TRACY_ENABLE
#include <tracy/Tracy.hpp>
#endif

Tile::Tile(TileType type, float x = 0, float y = 0, bool is_walkable = true)
{
	type_ = type;

	sprite_.setTexture(GetFromType());
	sprite_.setPosition(x, y);

	outline_.setSize(sf::Vector2f(sprite_.getTexture()->getSize()));
	outline_.setPosition(x, y);
	outline_.setFillColor(sf::Color(255, 255, 255, 0));
	outline_.setOutlineColor(sf::Color::White);
	outline_.setOutlineThickness(-1);

	is_walkable_ = is_walkable;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
#ifdef TRACY_ENABLE
	ZoneNamedN(TileCreation, "Tile Creation", true);
#endif

	target.draw(sprite_, states);

	if (is_selected_)
	{
		target.draw(outline_, states);
	}
}

sf::Texture& Tile::GetFromType()
{
	switch (type_)
	{
	case TileType::kForest:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kTerrainForest);
		break;

	case TileType::kStone:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kTerrainStone);
		break;

	case TileType::kGround:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kTerrainGround);
		break;

	case TileType::kHouse:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kHouse);
			break;
	case TileType::kSawmill:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kSawmill);
		break;
	case TileType::kMine:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kMine);
		break;
	case TileType::kStorage:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kStorage);
		break;
	case TileType::kCityHall:
		return ResourceManager::Get().GetLandTexture(ResourceManager::ResourceLand::kCityHall);
		break;

	default:
		break;
	}
}

void Tile::SetType(TileType new_type)
{
	type_ = new_type;
	sprite_.setTexture(GetFromType());
}