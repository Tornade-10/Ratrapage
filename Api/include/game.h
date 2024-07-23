#ifndef API_GAME_H
#define API_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "gameplay/building_manager.h"
#include "tilemap/TileMap.h"
#include "ui/ui_button.h"
#include "ui/View.h"

class Game
{
	sf::RenderWindow window_;
	sf::View fix_view_;

	// ResourceManager resource_;

	std::vector<UiButton> buttons_;

	TileMap map_;
	ViewPoint view_point_;
	sf::Vector2f clamped_center_;
	BuildingManager building_manager_;

	void InitUI();

public:

	void Init();
	void Loop();
};

#endif // API_GAME_H
