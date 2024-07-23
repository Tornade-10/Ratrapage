#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "tilemap/TileMap.h"
#include "ui/ui_button.h"

int main()
{
	Game game;

	game.Init();

	game.Loop();

	return EXIT_SUCCESS;
}
