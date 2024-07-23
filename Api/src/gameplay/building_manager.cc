#include "gameplay/building_manager.h"

#include "tilemap/tile.h"
#include "gameplay/building.h"

#include <iostream>

#include "buildings/house.h"
#include "buildings/mine.h"
#include "buildings/sawmill.h"
#include "buildings/storage.h"

void BuildingManager::SetActive(bool active)
{
	is_active_ = active;
}
bool BuildingManager::GetActive() const
{
	return is_active_;
}

void BuildingManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& b : buildings_)
	{
		target.draw(b, states);
	}
}

void BuildingManager::AddHouse(Tile& tile)
{
	if (is_active_)
	{
		std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

		if (tile.Type() == Tile::TileType::kGround)
		{
			House newHouse(tile.Position().x, tile.Position().y);
			tile.SetWalkable(false);

			buildings_.emplace_back(newHouse);
		}
	}

	is_active_ = false;
}

void BuildingManager::AddSawmill(Tile& tile)
{
	if (is_active_)
	{
		std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

		if (tile.Type() == Tile::TileType::kGround)
		{
			Sawmill newSawmill(tile.Position().x, tile.Position().y);
			tile.SetWalkable(false);

			buildings_.emplace_back(newSawmill);
		}
	}

	is_active_ = false;
}

void BuildingManager::AddMine(Tile& tile)
{
	if (is_active_)
	{
		std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

		if (tile.Type() == Tile::TileType::kGround)
		{
			Mine newMine(tile.Position().x, tile.Position().y);
			tile.SetWalkable(false);

			buildings_.emplace_back(newMine);
		}
	}

	is_active_ = false;
}

void BuildingManager::AddStorage(Tile& tile)
{
	if (is_active_)
	{
		std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

		if (tile.Type() == Tile::TileType::kGround)
		{
			Storage newStorage(tile.Position().x, tile.Position().y);
			tile.SetWalkable(false);

			buildings_.emplace_back(newStorage);
		}
	}

	is_active_ = false;
}
