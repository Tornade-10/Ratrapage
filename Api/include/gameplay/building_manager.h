#ifndef BUILDING_MANAGER_H
#define BUILDING_MANAGER_H

#include <vector>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "building.h"
#include "tilemap/tile.h"

class BuildingManager
{
	bool is_active_ = false;

	std::vector<Building> buildings_;

public:
	void SetActive(bool active);
	bool GetActive() const;

	void AddHouse(Tile& tile);
	void AddSawmill(Tile& tile);
	void AddMine(Tile& tile);
	void AddStorage(Tile& tile);
	//void AddSityHall(Tile& tile);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // BUILDING_MANAGER_H