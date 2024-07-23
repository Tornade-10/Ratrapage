#ifndef API_UI_TILEMAP_H
#define API_UI_TILEMAP_H

#include <iostream>
#include <vector>
#include <functional>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Tile.h"

class TileMap final : public sf::Drawable
{
	sf::Vector2u playground_size_u_;
	sf::Vector2u playground_tile_offset_u_;

	std::vector<Tile> tiles_;
	std::vector<sf::Vector2f> trees_;

	Tile* tileSelected_;

	sf::Vector2f map_size_ = sf::Vector2f(150, 150);
	sf::Vector2f tile_size_ = sf::Vector2f(16, 16);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:


	void Setup(sf::Vector2u playground_size_u, sf::Vector2u playground_tile_offset_u);
	void HandleEvent(const sf::Event& event);

	TileMap() = default;

	void Generate();
	std::vector<sf::Vector2f> GetWalkables();

	sf::Vector2f GetClosestTree(sf::Vector2f pos);
	[[nodiscard]] bool GatherTree(sf::Vector2f pos);

	std::function<void(Tile&)> ClickedTile;

	sf::Vector2f GetTileSize() const;
	sf::Vector2f GetMapSize() const;
};

#endif // API_UI_TILEMAP_H