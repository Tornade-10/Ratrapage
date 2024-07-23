#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/ressource_manager.h"

class Tile : public sf::Drawable
{
public:
	enum class TileType
	{
		kGround,
		kForest,
		kStone,
		kHouse,
		kSawmill,
		kMine,
		kStorage,
		kCityHall,
		kLength
	};

	Tile(TileType type, float x, float y, bool is_walkable);

private:

	sf::Sprite sprite_;
	sf::RectangleShape outline_;

	bool is_walkable_;
	bool is_selected_ = false;

	TileType type_;

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	bool GetWalkable() const
	{
		return is_walkable_;
	}
	void SetWalkable(bool is_walkable)
	{
		is_walkable_ = is_walkable;
	}

	sf::Vector2f Position() const
	{
		return sprite_.getPosition();
	}

	TileType Type() const
	{
		return type_;
	}

	void Select()
	{
		is_selected_ = true;
	}
	void UnSelect()
	{
		is_selected_ = false;
	}
	sf::Texture& GetFromType();
	void SetType(TileType new_type);
};

#endif // TILE_H
