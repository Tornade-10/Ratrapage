#pragma once

#include <fstream>
#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

enum Tile
{
	kGround,
	kWall,
	kDoor,
	kObstacle,
	kKey,
	kFocusCam
};

constexpr int kMapX = 32;
constexpr int kMapY = 32;
const sf::Vector2f kTileSize = sf::Vector2f(32, 32);



class TileMap
{
	int tile_map_[kMapX * kMapY] = {0};

	int selected_tile_ = kGround;

	sf::Vector2i mouse_pos_ = sf::Vector2i(0, 0);
	sf::Vector2i mouse_tile_pos_ = sf::Vector2i(mouse_pos_.x / kTileSize.x, mouse_pos_.y / kTileSize.y);

public:

	sf::Vector2i GetMousePos() const
	{
		return mouse_pos_;
	}
	void SetMousePos(const sf::RenderWindow& window)
	{
		mouse_pos_ = sf::Mouse::getPosition(window);
		//std::cout << mouse_pos_.x << " : " << mouse_pos_.y << std::endl;
	}

	void Save() const {
		std::ofstream file_("level.txt", std::ios::binary);
		if (file_.is_open()) {
			file_.write(reinterpret_cast<const char*>(tile_map_), sizeof(tile_map_));
			if (file_.fail()) {
				// Error writing to file
				std::cerr << "Error writing to file." << std::endl;
			}
			file_.close();
		}
		else {
			// Error opening file
			std::cerr << "Error opening file for writing." << std::endl;
		}
	}

	void Load() {
		std::ifstream file_("level.txt", std::ios::binary);
		if (file_.is_open()) {
			file_.read(reinterpret_cast<char*>(tile_map_), sizeof(tile_map_));
			if (file_.fail()) {
				// Error reading from file
				std::cerr << "Error reading from file." << std::endl;
			}
			file_.close();
		}
		else {
			// Error opening file
			std::cerr << "Error opening file for reading." << std::endl;
		}
	}

	Tile GetTile(int x, int y)
	{
		if (x >= 0 && x < kMapX && y >= 0 && y < kMapY) 
		{
			return static_cast<Tile>(tile_map_[x + y * kMapX]);
		}
		else {
			// Return a default tile type if coordinates are out of bounds
			return kGround;
		}
	}
	void SetTile(int x, int y)
	{
		tile_map_[static_cast<int>(y / kTileSize.y) * kMapX + static_cast<int>(x / kTileSize.x)] = kGround;
	}

	int GetTilePose()
	{

		for (int y = 0; y < kMapY; y++)
		{
			for (int x = 0; x < kMapX; x++)
			{

				if (tile_map_[x + y * kMapX] == kFocusCam)
				{
					return x + y * kMapX;
				}
			}
		}
	}

	void EditTile(sf::RenderWindow& window);
	void DrawTile(sf::RenderWindow& window);

};
