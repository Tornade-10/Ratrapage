#ifndef API_UI_VIEW_H_
#define API_UI_VIEW_H_

#include "tilemap/TileMap.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

//TODO : Prevent the view from going out of bounds

class ViewPoint
{

	sf::View view_;

	TileMap tile_map_;

	const sf::Vector2f dead_zone_ = sf::Vector2f(1875.f, 1075.f);
	const sf::Vector2f camera_speed_ = sf::Vector2f(0.01f, 0.012f);

	sf::Vector2f pos_ = sf::Vector2f(800, 600);

	const float max_zoom_ = 0.5f;
	const float min_zoom_ = 1.5f;

	float zoom_ = 1.0f;

	bool camera_modification_ = false;

public:
	//void ViewDraw(sf::RenderWindow& window, TileMap& tile_map);

	ViewPoint();

	sf::View view() const
	{
		return view_;
	}

	sf::Vector2f pos() const
	{
		return pos_;
	}

	bool IsWithinBounds(sf::Vector2f newCenter);

	sf::Vector2f ClampCenterToBounds(const sf::Vector2f& center);

	void Move(sf::Event event);

	void Zoom(sf::Event event, sf::RenderWindow& window);

	void MoveViewByMouse(sf::RenderWindow& window);

	//void ClampView();
};

#endif // API_UI_VIEW_H_
