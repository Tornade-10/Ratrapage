#include "TileMap.h"

void TileMap::EditTile(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selected_tile_ = kGround;
		std::cout << "Ground" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selected_tile_ = kWall;
		std::cout << "Wall" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		selected_tile_ = kKey;
		std::cout << "Key" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		selected_tile_ = kDoor;
		std::cout << "Door" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		selected_tile_ = kObstacle;
		std::cout << "Trap" << std::endl;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//std::cout << "i'm here " << static_cast<int>(mouse_pos_.x / kTileSize.x) << " : " << static_cast<int>(mouse_pos_.y / kTileSize.y) << std::endl;

		// Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
		if (mouse_tile_pos_.x < 0 || mouse_tile_pos_.x >= kMapX || mouse_tile_pos_.y < 0 || mouse_tile_pos_.y >= kMapY)
		{
			printf("Out of bounds\n");
		}
		else if (mouse_tile_pos_.x >= 0 || mouse_tile_pos_.x < kMapX || mouse_tile_pos_.y > 0 || mouse_tile_pos_.y < kMapY)
		{
			// Set the hovered tile to true or false depending on the pressed mouse button.
			tile_map_[static_cast<int>(mouse_pos_.y / kTileSize.y) * kMapX + static_cast<int>(mouse_pos_.x / kTileSize.x)] = selected_tile_;
		}
		//some code my cat wrighted
		//c5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3v	}////////////////////////////////lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll+
	}
}

void TileMap::DrawTile(sf::RenderWindow& window)
{
	sf::RectangleShape tile(kTileSize);
	tile.setOrigin(tile.getSize().x / 2, tile.getSize().y / 2);

	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			tile.setPosition(kTileSize.x * x, kTileSize.y * y);
			switch (tile_map_[x + y * kMapX])
			{
			case kGround:
				tile.setFillColor(sf::Color::Black);
				break;

			case kWall:
				tile.setFillColor(sf::Color::Blue);
				break;

			case kKey:
				tile.setFillColor(sf::Color::Yellow);
				break;

			case kDoor:
				tile.setFillColor(sf::Color::Green);
				break;

			case kObstacle:
				tile.setFillColor(sf::Color::Magenta);
				break;

			default: 
				break;
			}

			window.draw(tile);

			//if (tile_map_[x + y * kMapX] == kGround)
			//{

			//	if (true)
			//	{
			//		tile.setFillColor(sf::Color::Red);
			//	}

			//}
		}
	}
}
