#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class HUD
{

	sf::Font font_;
	sf::Text game_over_;
	sf::Text won_;

public:

	void HUDInit(sf::RenderWindow& window);

	void TextDrawGameOver(sf::RenderWindow& window);
	void TextDrawWon(sf::RenderWindow& window);
};

