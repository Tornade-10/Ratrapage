#include "Player.h"

Player::Player()
{
	player_shape_.setSize(kTileSize);
	player_shape_.setOrigin(player_shape_.getSize().x / 2 ,player_shape_.getSize().y / 2);
	player_shape_.setFillColor(sf::Color::White);
	player_shape_.setPosition(player_coords_.x , player_coords_.y);
}

void Player::PlayerMove(TileMap& tile_map)
{
	if(input_clock_.getElapsedTime().asSeconds() >= input_delay_)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player_new_coords_.y -= 1 * kTileSize.y;
			//std::cout << "Up" << std::endl;
			input_clock_.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player_new_coords_.y += 1 * kTileSize.y;
			//std::cout << "Down" << std::endl;
			input_clock_.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player_new_coords_.x += 1 * kTileSize.x;
			//std::cout << "Right" << std::endl;
			input_clock_.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player_new_coords_.x -= 1 * kTileSize.x;
			//std::cout << "Left" << std::endl;
			input_clock_.restart();
		}
	}

	//std::cout << player_new_coords_.x / kTileSize.x << " : " << player_new_coords_.y / kTileSize.y << std::endl;


	switch (tile_map.GetTile(static_cast<int>(player_new_coords_.x / kTileSize.x), static_cast<int>(player_new_coords_.y / kTileSize.y)))
	{

	case kWall:
		player_new_coords_ = player_coords_;
		std::cout << "you hit a wall" << std::endl;
		break;

	case kKey:
		has_the_key_ = true;
		tile_map.SetTile(player_coords_.x, player_coords_.y);
		break;

	case kDoor:
		if (has_the_key_)
		{
			std::cout << "You went trough the door" << std::endl;
			has_the_key_ = false;
			has_won_ = true;
		}
		else
		{
			std::cout << "You don't have the key" << std::endl;
			player_new_coords_ = player_coords_;
		}
		break;

	case kObstacle:
		player_health_ -= 1;
		std::cout << "you walked on a trap" << std::endl;
		tile_map.SetTile(player_coords_.x, player_coords_.y);
		break;

	default:
		player_coords_ = player_new_coords_;
		break;
	}

	if(tile_map.GetTile(static_cast<int>(player_new_coords_.x / kTileSize.x), static_cast<int>(player_new_coords_.y / kTileSize.y)) != kWall)
	{
		player_coords_ = player_new_coords_;
	}
	else
	{
		player_new_coords_ = player_coords_;
		std::cout << "you hit a wall" << std::endl;
	}
}

void Player::ViewDraw(sf::RenderWindow& window)
{
	//sf::View view_(sf::Vector2f(player_coords_.y, window.getSize().y / 2), sf::Vector2f(window.getSize().y / 2, player_coords_.y));
	sf::View view_(sf::Vector2f(player_coords_.x, player_coords_.y), sf::Vector2f(window.getSize().x, window.getSize().y));
	window.setView(view_);
}