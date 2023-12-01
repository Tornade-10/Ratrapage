#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "TileMap.h"

class Player
{

	sf::RectangleShape player_shape_;
	sf::Vector2i player_coords_ = sf::Vector2i(32, 32);
	sf::Vector2i player_new_coords_ = sf::Vector2i(32, 32);

	sf::Clock input_clock_;
	const float input_delay_ = 0.2f;
	bool has_the_key_ = false;
	bool has_won_ = false;
	int player_health_ = 5;

public:

	Player();

	int GetPlayerHealth()
	{
		return player_health_;
	}
	void SetPlayerHealth(int player_health)
	{
		player_health_ = player_health;
	}

	int PlayerWon()
	{
		return PlayerWon();
	}

	sf::Vector2i GetPlayerCoords()
	{
		return player_coords_;
	}
	void SetPlayerCoords(sf::Vector2i player_coords)
	{
		player_coords_ = player_coords;
	}

	sf::Vector2i GetPlayerNewCoords() 
	{
		return player_new_coords_;
	}
	void SetPlayerNewCoords(sf::Vector2i player_new_coords)
	{
		player_new_coords_ = player_new_coords;
	}

	void PlayerMove(TileMap& tile_map);
	void ViewDraw(sf::RenderWindow& window);

	void DrawPlayer(sf::RenderWindow& window)
	{
		player_shape_.setPosition(player_coords_.x, player_coords_.y);
		window.draw(player_shape_);
	}

};
