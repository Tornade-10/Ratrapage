#include "Game.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "HUD.h"
#include "Player.h"
#include "TileMap.h"

void Game::Init()
{
	//Create the window
	render_window_.create(sf::VideoMode(kTileSize.x * 16, kTileSize.y * 16), "Le game");

	//Set the frame limit
	render_window_.setVerticalSyncEnabled(true);
	render_window_.setFramerateLimit(60);
}

void Game::Loop()
{

	HUD hud;
	TileMap tile_map;
	Player player;

	hud.HUDInit(render_window_);
	tile_map.Load();

	while (render_window_.isOpen())
	{
		render_window_.clear();

		sf::Event event;
		while (render_window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				render_window_.close();
			}
		}

		if (false)
		{
			tile_map.SetMousePos(render_window_);
			tile_map.EditTile(render_window_);
			tile_map.Save();
		}

		tile_map.DrawTile(render_window_);
		player.ViewDraw(render_window_);
		if(player.GetPlayerHealth() <= 0)
		{
			hud.TextDrawGameOver(render_window_);
		}
		else
		{
			player.PlayerMove(tile_map);
			player.DrawPlayer(render_window_);
		}

		render_window_.display();
	}
}
